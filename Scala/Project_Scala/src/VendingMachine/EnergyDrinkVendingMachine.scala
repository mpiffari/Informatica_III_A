package VendingMachine
import Drinks._
import scala.collection.mutable.Queue

class EnergyDrinkVendingMachine(val language: String) extends VendingMachine {
  
   // Make array of queue: it's like in a real vending machine
   // 1: Red Bull  2: Monster  3: Gatorade  4: Italian
   val RED_BULL: Int = 0
   val MONSTER: Int = 1
   val GATORADE: Int = 2
   val ITALIAN: Int = 3
   var products = Array[Queue[EnergyDrink]](Queue[EnergyDrink](),Queue[EnergyDrink](),Queue[EnergyDrink](),Queue[EnergyDrink]())
   var amountOfMoneyOnMachine = 0.0
   
   def addProduct(product: EnergyDrink) {
     if(product.isInstanceOf[RedBullEnergyDrink]) {
       products(RED_BULL) += product
     } else if(product.isInstanceOf[MonsterEnergyDrink]) {
       products(MONSTER) += product
     } else if(product.isInstanceOf[GatoradeEnergyDrink]) {
       products(GATORADE) += product
     } else if(product.isInstanceOf[ItalianEnergyDrink]) {
       products(ITALIAN) += product
     }
   }
   
   def searchByTag(tag: String) : List[Int] = {
     val columns = Vector(RED_BULL,MONSTER,GATORADE,ITALIAN)
     
     def checkTag(product: EnergyDrink) : Boolean = {
       if(language == "ITA") {
         if(product.tagITA.filter(t => t.contains(tag)).size > 0) {
           return true
         } else {
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
     
     var columnWithTagRequested = List[Int]()
      for(column <- columns) {
        if(checkTag(products(column)(0))) {
          columnWithTagRequested.+:(column)
        } 
     }
      columnWithTagRequested
   }
     
   def isEmpty(column: Int): Boolean = {
     products(column).isEmpty
   }
   
   def sell(column: Int): EnergyDrink = {
     products(column).dequeue()
   }
   
   def sell(column: Int, money: Double): Double = {
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
     
     if(!isEmpty(column)) {
       println("Product " + productDescription + " not available")
       money
     } else {
       val productSelected = sell(column)
       val price = productSelected.price
       if(money < price || money <= 0){
         println("Money not enough for " + productDescription)
         return money
       } else {
         if(productSelected.isExpired()) {
           println(productDescription + " expired! Take it for free")
           return money
         } else {
            println(productDescription + "has \n-		" + productSelected.nutritionalValues() 
                + " nutriation value\n-	" + productSelected.calories + " calories");
            amountOfMoneyOnMachine += price
         }
       }
       money - price
     }
   }
   
   def show {
     println("Language --> " + language)
     println("Available drinks:\n")
     if(!isEmpty(RED_BULL)) {
         println("	- RED BULL")
     } else {
         println("	- RED BULL EMPTY!")
     }
     
     if(!isEmpty(MONSTER)) {
         println("	- MONSTER")
     } else {
         println("	- MONSTER EMPTY!")
     }
     
     if(!isEmpty(GATORADE)) {
         println("	- GATORADE")
     } else {
         println("	- GATORADE EMPTY!")
     }
     
     if(!isEmpty(ITALIAN)) {
         println("	- ITALIAN")
     } else {
         println("	- ITALIAN EMPTY!")
     } 
   }
}