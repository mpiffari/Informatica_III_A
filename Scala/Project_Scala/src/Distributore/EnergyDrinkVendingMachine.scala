package distributore
import prodotti._
import scala.collection.mutable.Queue
import Prodotti.RedBullEnergyDrink
import Prodotti.MonsterEnergyDrink
import Prodotti.GatoradeEnergyDrink
import Prodotti.GatoradeEnergyDrink
import Prodotti.ItalianEnergyDrink
import com.sun.javafx.css.Match

class EnergyDrinkVendingMachine extends VendingMachine {
  
   // Make array of queue: it's like in a real vending machine
   // 1: Red Bull  2: Monster  3: Gatorade  4: Italian
   val RED_BULL: Int = 0
   val MONSTER: Int = 1
   val GATORADE: Int = 2
   val ITALIAN: Int = 3
   var products = Array[Queue[EnergyDrink]](Queue[EnergyDrink](),Queue[EnergyDrink](),Queue[EnergyDrink](),Queue[EnergyDrink]())
   var amountOfMoneyOnMachine = 0.0
   
   def addProduct(product: Expirable) = Boolean {
     if(product.isInstanceOf[RedBullEnergyDrink]) {
       products(RED_BULL) += p
     } else if(product.isInstanceOf[MonsterEnergyDrink]) {
       products(MONSTER) += p
     } else if(product.isInstanceOf[GatoradeEnergyDrink]) {
       products(GATORADE) += p
     } else if(product.isInstanceOf[ItalianEnergyDrink]) {
       products(ITALIAN) += p
     }
     true
   }
     
   def isEmpty(column: Int): Boolean = {
     products(column).isEmpty
   }
   
   def sell(column: Int): EnergyDrink = {
     products(column).dequeue()
   }
   
   def sell(column: Int, money: Double): Double = {
     def productDescription = match {
       case i1: Int if column == 0 => "Red Bull"
       case i2: Int if column == 1 => "Monster"
       case i3: Int if column == 2 => "Gatorade"
       case i4: Int if column == 3 => "Italian"
     }
     if(!isEmpty(column)) {
       println("Product " + productDescription + " not available")
       return money
     } else {
       val productSelected = sell(column)
       val price = productSelected.price
       if(money < price || money <= 0){
         println("Money not enough for " + productDescription)
         return money
       } else {
         if(productSelected.expired) {
           println(productDescription + " expired! Take it for free")
           return contanti
         } else {
            println(productDescription + "has \n-		" + productSelected.valoreNutrizionale() 
                + " nutriation valu\n-	" + productSelected.calories + " calories");
            amountOfMoneyOnMachine += price
         }
       }       
     }
     money - price
   }
   
   
   def show = println("PRODOTTI DISPONIBILI:\n" + (if(!isEmpty(1)) "1) Succo Pera		" + SuccoPera.COSTO + " €\n"  else "") 
                                                + (if(!isEmpty(2)) "2) Succo Pesca		" + SuccoPesca.COSTO + " €\n" else "") 
                                                + (if(!isEmpty(3)) "3) Succo Albicocca	" + SuccoAlbicocca.COSTO + "   €\n" else ""))
   
   
   
   
  
}