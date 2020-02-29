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
    
    /*dis.aggiungiProdotto(new SuccoPera(data="2000-01-01"))
    dis.aggiungiProdotto(new SuccoPera("2020-01-01"))
    dis.aggiungiProdotto(new SuccoPesca("2020-01-01"))
    dis.aggiungiProdotto(new SuccoPesca("2020-01-01"))
    dis.aggiungiProdotto(new SuccoPesca("2020-01-01"))
    dis.aggiungiProdotto(new SuccoAlbicocca("2020-01-01"))
    
    dis.show
    
    println("Resto: "+dis.vendi(1,10) +"\n")
    println("Resto: "+dis.vendi(1,10) +"\n")
    dis.show
    println("Resto: "+dis.vendi(1,10) +"\n")
    println("Resto: "+dis.vendi(2,10) +"\n")
    println("Resto: "+dis.vendi(3,10) +"\n")*/
  } 
}