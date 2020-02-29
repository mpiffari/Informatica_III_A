package Main
import VendingMachine._
import Drinks._

object Main {
  
  def main(args:Array[String]): Unit = {
    // Creation of vending machine
    val vendingMachineENG: VendingMachine = new EnergyDrinkVendingMachine(language = "ENG")
    val vendingMachineITA: VendingMachine = new EnergyDrinkVendingMachine(language = "ITA")
    
    // Show information of empty vending machines
    vendingMachineENG.show 
    vendingMachineITA.show
    
    // Products to add
    val redBull1 = new RedBullEnergyDrink("2020-03-29", 330, 1.75, 150,
        List("studio intenso", "studio disperato"), List("study", "hard study"))
    val redBull2_expired = new RedBullEnergyDrink("2010-03-29", 330, 1.75, 150,
        List("studio intenso", "studio disperato"), List("study", "hard study"))
    
     val redBull3 = new RedBullEnergyDrink("2020-03-29", 330, 1.75, 150,
        List("studio intenso", "studio disperato"), List("study", "hard study"))
     val monster1 = new MonsterEnergyDrink("2020-03-29", 330, 1.75, 150,
        List("palestra", "palestra cus", "migliorare in palestra"), List("fitness gym", "gym", "gym motivation"))
     val gatorade1 = new GatoradeEnergyDrink("2020-03-29", 330, 1.75, 150,
        List("concentrazione", "concetrazione meditazione"), List("concentration", "meditation concentration"))
    val italian1 = new ItalianEnergyDrink("2020-03-29", 330, 1.75, 150,
        List("concentrazione", "concetrazione meditazione"))
  
    // Addition of products
    vendingMachineENG.addProduct(redBull1)
    vendingMachineENG.addProduct(redBull2_expired)
    vendingMachineENG.addProduct(redBull3)
    vendingMachineENG.addProduct(monster1)
    vendingMachineENG.addProduct(gatorade1)
    
    vendingMachineITA.addProduct(redBull1)
    vendingMachineITA.addProduct(redBull2_expired)
    vendingMachineITA.addProduct(redBull3)
    vendingMachineITA.addProduct(monster1)
    vendingMachineITA.addProduct(gatorade1)
    vendingMachineITA.addProduct(italian1)
    
    // Show information of NOT empty vending machines
    vendingMachineENG.show 
    vendingMachineITA.show
    
    // Search by tag
    println("Column with product with tag CONCENTRATION "  + vendingMachineENG.searchByTag("concentration"))
    println("Column with product with tag HARD STUDY "  + vendingMachineENG.searchByTag("hard study"))
    println("Column with product with tag CONCENTRAZIONE "  + vendingMachineITA.searchByTag("concentrazione"))

    /*dis.show
    
    println("Resto: "+dis.vendi(1,10) +"\n")
    println("Resto: "+dis.vendi(1,10) +"\n")
    dis.show
    println("Resto: "+dis.vendi(1,10) +"\n")
    println("Resto: "+dis.vendi(2,10) +"\n")
    println("Resto: "+dis.vendi(3,10) +"\n")*/
  } 
}