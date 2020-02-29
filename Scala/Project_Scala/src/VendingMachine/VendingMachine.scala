package VendingMachine
import Drinks._

trait VendingMachine {
  def addProduct(product: EnergyDrink)
  def searchByTag(tag: String) : List[Int]
  def show
}