package Main
import VendingMachine._
import Drinks._

object Main {
  
  def main(args:Array[String]): Unit = {
    // Creation of vending machine
    val vendingMachineENG: VendingMachine = new EnergyDrinkVendingMachine(language = "ENG", id = 10)
    val vendingMachineITA: VendingMachine = new EnergyDrinkVendingMachine(language = "ITA", id = 100)
    
    // Showing information of two empty vending machines just created
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
  
    // Addition of products to vending machines
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
    
    // Search product by tag
    println("Column with product with tag CONCENTRATION "  + vendingMachineENG.searchByTag("concentration"))
    println("Column with product with tag HARD STUDY "  + vendingMachineENG.searchByTag("hard study"))
    println("Column with product with tag CONCENTRAZIONE "  + vendingMachineITA.searchByTag("concentrazione"))
    
    // Buying some energy drink (colum --> type of product, money --> money inserted)
    println("Resto from ENG: " + vendingMachineENG.buy(0,10) + "\n")
    println("Resto from ENG: " + vendingMachineENG.buy(1,10) + "\n")
    vendingMachineENG.show
    
    println("Resto from ITA: " + vendingMachineITA.buy(0,10) + "\n")
    println("Resto from ITA: " + vendingMachineITA.buy(0,10) + "\n")
    println("Resto from ITA: " + vendingMachineITA.buy(2,1) + "\n")
    println("Resto from ITA: " + vendingMachineITA.buy(3,10) + "\n")
    vendingMachineITA.show
  } 
}