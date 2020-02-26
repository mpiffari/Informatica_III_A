package Distributore
import prodotti.Expirable

trait VendingMachine {
  def addProduct(product: Expirable)
}