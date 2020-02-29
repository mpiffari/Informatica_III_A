package VendingMachine
import Drinks._

trait VendingMachine {
  def addProduct(product: EnergyDrink)
  def searchByTag(tag: String) : List[String]
  def buy(column: Int, money: Double): Double
  def show
}