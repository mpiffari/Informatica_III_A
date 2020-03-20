package VendingMachine
import Drinks._
import Drinks.RedBullEnergyDrink
import Drinks.MonsterEnergyDrink
import Drinks.GatoradeEnergyDrink
import Drinks.ItalianEnergyDrink
import scala.collection.mutable.Queue

class EnergyDrinkVendingMachine(val language: String, val id: Int) extends VendingMachine {
  
   // Make array of queue: it's like in a real vending machine
   // 1: Red Bull  2: Monster  3: Gatorade  4: Italian
   val RED_BULL: Int = 0
   val MONSTER: Int = 1
   val GATORADE: Int = 2
   val ITALIAN: Int = 3
   // Simulated the matrix structure of a vending machine, with an array of different products.
   // Each queue can contains more energy drink, of the same type.
   var products = Array[Queue[EnergyDrink]](Queue[EnergyDrink](),Queue[EnergyDrink](),Queue[EnergyDrink](),Queue[EnergyDrink]())
   var amountOfMoneyOnMachine = 0.0
   
   // Adding new product in the correct Queue
   def addProduct(product: EnergyDrink) {
     if(product.isInstanceOf[RedBullEnergyDrink]) {
       products(RED_BULL) += product
     } else if(product.isInstanceOf[MonsterEnergyDrink]) {
       products(MONSTER) += product
     } else if(product.isInstanceOf[GatoradeEnergyDrink]) {
       products(GATORADE) += product
     } else if(product.isInstanceOf[ItalianEnergyDrink]) {
       // No italian energy drink allowed in english vending machine
       if(language == "ENG") {
         println("! ERROR ! Italian drink forbidden in ENG vending machine") 
       } else {
         products(ITALIAN) += product
       }
     }
   }
   
   def searchByTag(tag: String) : List[String] = {   
     
     // Check if tag searched is contained in vending machine
     def checkTag(product: EnergyDrink) : Boolean = {
       if(language == "ITA") {
         if(product.tagITA.filter(t => t.contains(tag)).size > 0) {
           // if size is equal than 0, it means that the product match the tag search
           return true
         } else {
           // else this product doesn't match the tag searched by user
           return false
         }
       } else if(language == "ENG") {
         if(product.tagENG.filter(t => t.contains(tag)).size > 0) {
           return true
         } else {
           return false
         }
       } else {
         return false
       }
     }

     val columns = Vector(RED_BULL,MONSTER,GATORADE,ITALIAN)
		 var columnWithTagRequested = List[String]()
		 // Search tag for each product
		 for(column <- columns) {
			 if(!isEmpty(column)) {
			   // Each kind of product has the same tags, so I'll use the tags of the first EnergyDrink of the queue
				 if(checkTag(products(column)(0))) {
					 if(column == 0) {
						 columnWithTagRequested = columnWithTagRequested:+"Red Bull"
					 } else if(column == 1) {
						 columnWithTagRequested = columnWithTagRequested:+"Monster"
					 } else if(column == 2) {
						 columnWithTagRequested = columnWithTagRequested:+"Gatorade"
					 } else {
						 columnWithTagRequested = columnWithTagRequested:+"Italian"
					 }
				 }
			 }
		 }

     columnWithTagRequested
   }
     
   // Check if a column is empty, and so if is available product
   def isEmpty(column: Int): Boolean = {
     products(column).isEmpty
   }
   
   // Take one energy drink from the queue
   def buy(column: Int): EnergyDrink = {
     products(column).dequeue()
   }
   
   def buy(column: Int, money: Double): Double = {
     var productDescription: String = ""
     if(column == 0) {
        productDescription = "Red Bull"
     } else if(column == 1) {
        productDescription = "Monster"
     } else if(column == 2) {
        productDescription = "Gatorade"
     } else {
       productDescription = "Italian"
     }
     
     if(isEmpty(column)) {
       println("Product " + productDescription + " not available")
       money
     } else {
       val productSelected = buy(column) // Take product from column
       val price = productSelected.price
       if(money < price || money <= 0){
         println("Money not enough for " + productDescription)
         return money
       } else {
         if(productSelected.isExpired()) {
           println(productDescription + " expired! Take it for free")
           return money
         } else {
            println("I'm giving you a " + productDescription + " that is \n- " + productSelected.nutritionalValues() 
                + "\n- " + productSelected.calories + " calories" + "\n- " + price + " (price)");
            amountOfMoneyOnMachine += price
         }
       }
       money - price
     }
   }
   
   // Print product name and amount available for each kind product 
   def show {
     println("Available drinks for machine with id " + id + ":")
     if(!isEmpty(RED_BULL)) {
         println("	- " + products(RED_BULL).size + " RED BULL")
     } else {
         println("	- RED BULL EMPTY!")
     }
     
     if(!isEmpty(MONSTER)) {
         println("	- " + products(MONSTER).size + " MONSTER")
     } else {
         println("	- MONSTER EMPTY!")
     }
     
     if(!isEmpty(GATORADE)) {
         println("	- " + products(GATORADE).size + " GATORADE")
     } else {
         println("	- GATORADE EMPTY!")
     }
     
     // Italian energy drink not allowed in ENG vending machine
     if(language != "ENG") {
    	 if(!isEmpty(ITALIAN)) {
    		 println("	- " + products(ITALIAN).size + " ITALIAN")
    	 } else {
    		 println("	- ITALIAN EMPTY!")
    	 } 
     }
   }
}