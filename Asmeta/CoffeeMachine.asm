asm CoffeeMachine
import StandardLibrary

signature:
	/****** DOMAINS ******/

	abstract domain Product									// Product available from the machine

	domain CoinValue subsetof Integer						// Coins accepted by the machine (value in cents)

	enum domain State = {WAITING |
						COINS_INSERTED | GIVING_CHANGE |
						PREPARED | MAINTAINING |
						OUT_OF_SERVICE}						// Possible states for the machine
	enum domain WaitingAction = {INSERT_COINS |
								PRODUCT_INFO | MAINTAIN |
								EXIT}						// Possible user actions when the machine is waiting
	enum domain CoinsInsAction = {MORE_COINS |
								CHOOSE_PRODUCT}				// Possible user actions when some coins have been inserted
	enum domain PreparedAction = {PICK}						// Possible user actions when the chosen  has been prepared
	enum domain OutOfServiceAction = {REPAIR}				// Possible user actions when the machine is out of service
	enum domain MaintainAction = {FILL | SET_COINS |
									FINISH}					// Possible user actions when the machine has been opened for maintenance
	enum domain Ingredient = {COFFEE | MILK | WATER |
							TEA | CHOCOLATE |
							PLASTIC_GLASS}					// The "ingredients" needed to prepare a product


	/****** MONITORED FUNCTIONS (system readble) ******/

	dynamic monitored selectedProduct	 : Product				// The product that has just been chosen
	dynamic monitored insertedCoin		 : CoinValue			// The coin that has just been inserted
	dynamic monitored numberOfCoins		 : Natural				// The number of coins left in the machine by the maintenance man
	dynamic monitored filledIngredient	 : Ingredient			// The ingredient whose container has to be filled by the maintenance man
	dynamic monitored waitingAction		 : WaitingAction		// The selected action in the WAITING state
	dynamic monitored coinsInsAction	 : CoinsInsAction		// The selected action in the COINS_INSERTED state
	dynamic monitored preparedAction	 : PreparedAction		// The selected action in the PREPARED state
	dynamic monitored outOfServiceAction : OutOfServiceAction	// The selected action in the OUT_OF_SERVICE state
	dynamic monitored maintainAction	 : MaintainAction		// The selected action in the MAINTAINING state


	/****** CONTROLLED FUNCTIONS (system readble and writable) ******/

	dynamic controlled state		    			: State					// The machine state
	dynamic controlled display		    			: String				// The message displayed to the user
	dynamic controlled credit		    			: Integer				// The current credit of the user (coins only)
	dynamic controlled coinsLeft	    			: CoinValue -> Natural	// For each coin value, the number of coins held by the machine
	dynamic controlled maxInseartableCoinsQuantity	: CoinValue -> Natural	// For each coin value, the max quantity of coins that the machine can store
	dynamic controlled quantityLeft     			: Ingredient -> Integer	// The amount of ingredient left in the machine


	/****** STATIC FUNCTIONS ******/

	static capacity			: Ingredient -> Integer					// The maximum amount of an ingredient that the machine can hold
	static quantityNeeded	: Prod(Product, Ingredient) -> Integer	// The amount of ingredient needed to prepare a product
	static price			: Product -> Integer					// The price of a product
	static currencyToString : Integer -> String						// Formats an amount of cents in a human readable string


	/****** DERIVED FUNCTIONS ******/

	derived canPrepare		 : Product -> Boolean			 // True if the ingredients left are enough to prepare the product
	derived outOfIngredients : Boolean						 // True if no product can be prepared with the left ingredients (except glassOnly)


	/****** DEFAULT ELEMENTS FOR ABSTRACT DOMAINS ******/

	// available products
	static coffee	  : Product
	static tea		  : Product
	static cappuccino : Product
	static chocolate  : Product
	static glassOnly  : Product

definitions:
	/****** STATIC CONCRETE DOMAINS ******/

	domain CoinValue = {5, 10, 20, 50, 100, 200}

	/****** STATIC FUNCTIONS ******/

	function quantityNeeded ($p in Product, $i in Ingredient) =
		if($i = PLASTIC_GLASS) then
			1
		else
			switch($p,$i)
				case (coffee, COFFEE)		: 1
				case (coffee, WATER)		: 3

				case (tea, TEA)				: 1
				case (tea, WATER)			: 1

				case (cappuccino, COFFEE)	: 1
				case (cappuccino, MILK)		: 3
				case (cappuccino, WATER)	: 5

				case (chocolate, CHOCOLATE)	: 1
				case (chocolate, MILK)		: 3
				case (chocolate, WATER)		: 5

				otherwise 0

			endswitch
		endif

	function capacity($i in Ingredient) =
		switch($i)
			case COFFEE			:  100
			case MILK			:  100
			case WATER			:  750
			case TEA			:  100
			case CHOCOLATE		:  100
			case PLASTIC_GLASS	: 1000
		endswitch

	function price($p in Product) =
		switch($p)
			case coffee		: 30
			case tea		: 40
			case cappuccino	: 40
			case chocolate	: 40
			case glassOnly	: 10
		endswitch

	function currencyToString($n in Integer) =
		concat(toString($n/100), " €")

	/****** DERIVED FUNCTIONS ******/

	function canPrepare($p in Product) =
		not (exist $i in Ingredient
			with quantityLeft($i) < quantityNeeded($p,$i))

	function outOfIngredients =
		not (exist $p in Product with canPrepare($p) and $p != glassOnly)


	/****** RULES ******/

	/** UTILITY RULES **/

	// Reduce the amount of ingredients left, because they were used
	// to prepare a product
	rule r_consumeIngredients($p in Product) =
		forall $i in Ingredient do
			quantityLeft($i) := quantityLeft($i) - quantityNeeded($p,$i)

	// Changes the state and refreshes the display
	rule r_changeState($s in State) =
		par
			state := $s
			switch($s)
				case WAITING:
					display := "Waiting..."
				case COINS_INSERTED:
					display := concat("Credit: ", currencyToString(credit) )
				case PREPARED:
					display := "Prepared."
				case MAINTAINING:
					display := "*** Opened ***"
				case OUT_OF_SERVICE:
					display := "*** Out of service ***"
			endswitch
		endpar


	/** TRANISITION RULES **/

	// Show information about price/availability of a product
	rule r_productInfo =
		let($p1 = selectedProduct) in
			if(canPrepare($p1)) then
				display := currencyToString(price($p1))
			else
				display := "not available"
			endif
		endlet

	// Change state to MAINTAINING
	rule r_maintain =
		r_changeState[MAINTAINING]

	// Go out of service if no products can be prepared
	rule r_selfCheck =
		if(state = WAITING and outOfIngredients) then
			state := OUT_OF_SERVICE
		endif

	// Accept an inserted coin and change state to COINS_INSERTED
	rule r_insertCoins =
		let($c = insertedCoin) in
			seq
				credit := credit + $c
				coinsLeft($c) := coinsLeft($c) + 1n
				r_changeState[COINS_INSERTED]
			endseq
		endlet

	// Accept more coins
	rule r_moreCoins =
		r_insertCoins[]

	// If the chosen product is available and the credit is enough,
	// then prepare it and give the change
	rule r_chooseProduct =
		let($p2 = selectedProduct) in
			if(not canPrepare($p2)) then
				display := "not available"
			else
				if(credit >= price($p2)) then
					par
						r_changeState[GIVING_CHANGE]
						credit := credit - price($p2)
						r_consumeIngredients[$p2]
					endpar
				else
					display := concat("price is ", currencyToString( price($p2) ) )

				endif
			endif
		endlet

	// If some coin credit is left, try and give it back, choosing a greedy solution
	rule r_giveChange =
		if(state = GIVING_CHANGE) then
			// Find the highest available coin value, not greater than the residual credit
			choose $cv in CoinValue with coinsLeft($cv) > 0n // Available one
			and $cv <= credit  // Lower then credit
			and	not(exist $cv2 in CoinValue with coinsLeft($cv2) > 0n and $cv2 <= credit and $cv2 > $cv) do // The highest coin possible
				let ($cl = coinsLeft($cv)) in
					if($cl <= 0n) then
						display := "ERROR"
					else
						seq
							credit := credit - $cv
							//coinsLeft($cv) := $cl - 1
							display := concat("Pick up your change! Credit on machine ", currencyToString(credit))
						endseq
					endif
				endlet
			ifnone
				seq
					credit := 0
					r_changeState[PREPARED]
				endseq
		endif

		// Set the number of coins in the machine
	// (after insertion/removal by the maintenance man)
	rule r_setCoins =
		let($cv = insertedCoin, $n = numberOfCoins) in
			let($cl = coinsLeft($cv), $mq = maxInseartableCoinsQuantity($cv)) in
				if($n < $mq) then
					seq
						coinsLeft($cv) := $cl + $n
						display := concat("Coins left ", toString(coinsLeft($cv)))
					endseq
				else
					display := "MAX INSERTABLE COINS OVERBOUNDED"
				endif

				// Doesn't work on Natural minus
				/*if($cl < $mq) then // Here $mq is the size of the pocket for each coin size
					if($mq - $cl > $n) then
						// If amount of insertedCoins is lower than space available, insert only money available
						seq
							coinsLeft($cv) := $cl + $n
							display := concat("POCKET FULLFILLED WITH ", $n)
						endseq
					else
						// Else refill completely pocket for coin of type $cv
						seq
							coinsLeft($cv) := $mq
							display := "POCKET FULLFILLED"
						endseq
					endif
				else
					display := "MONEY POCKET ALREADY FULL"
				endif*/
			endlet
		endlet


	// Get back to WAITING state
	rule r_pick =
		r_changeState[WAITING]

	// Change state to MAINTAINING
	rule r_repair =
		r_changeState[MAINTAINING]

	// Change state to WAITING
	rule r_finish =
		r_changeState[WAITING]

	// Restore the maximum amount of an ingredient
	rule r_fill =
		quantityLeft(filledIngredient) := capacity(filledIngredient)


	/** EVENT MANAGEMENT RULES **/

	// Deal with events that can happen in the WAITING state
	rule r_waitingAction =
		if(state = WAITING) then
			switch(waitingAction)
				case PRODUCT_INFO:	r_productInfo[]
				case INSERT_COINS:	r_insertCoins[]
				case MAINTAIN:		r_maintain[]
				case EXIT:			skip
			endswitch
		endif

	// Deal with events that can happen in the COINS_INSERTED state
	rule r_coinsInsAction =
		if(state = COINS_INSERTED) then
			switch(coinsInsAction)
				case MORE_COINS:	 r_moreCoins[]
				case CHOOSE_PRODUCT: r_chooseProduct[]
			endswitch
		endif

	// Deal with events that can happen in the PREPARED state
	rule r_preparedAction =
		if(state = PREPARED) then
			switch(preparedAction)
				case PICK: r_pick[]
			endswitch
		endif

	// Deal with events that can happen in the OUT_OF_SERVICE state
	rule r_outOfServiceAction =
		if(state = OUT_OF_SERVICE) then
			switch(outOfServiceAction)
				case REPAIR: r_repair[]
			endswitch
		endif

	// Deal with events that can happen in the MAINTAINING state
	rule r_maintainAction =
		if(state = MAINTAINING) then
			switch(maintainAction)
				case FINISH:	r_finish[]
				case FILL:	 	r_fill[]
				case SET_COINS:	r_setCoins[]
			endswitch
		endif

	/** MAIN RULE **/

	main rule r_main =
		seq
			r_selfCheck[]
			par
				r_waitingAction[]
				r_coinsInsAction[]
				r_giveChange[]
				r_preparedAction[]
				r_maintainAction[]
				r_outOfServiceAction[]
			endpar
		endseq

default init initial_state:
	function state = WAITING
	function display = "Waiting..."
	function coinsLeft ($cv in CoinValue) =
		switch($cv)
			case   5 :  5n
			case  10 : 20n
			case  20 : 20n
			case  50 : 20n
			case 100 : 10n
			case 200 :  5n
		endswitch
	function maxInseartableCoinsQuantity ($cv in CoinValue) =
		switch($cv)
			case   5 : 20n
			case  10 : 20n
			case  20 : 20n
			case  50 : 10n
			case 100 : 10n
			case 200 : 	5n
		endswitch
	function credit = 0
	function quantityLeft($i in Ingredient) =
		switch($i)
			case PLASTIC_GLASS	: 1000
			case WATER			:  	80
			otherwise 			   	40
		endswitch

