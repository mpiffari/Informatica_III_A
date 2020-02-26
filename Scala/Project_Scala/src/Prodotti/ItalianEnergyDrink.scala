package Prodotti
import prodotti.EnergyDrink

class ItalianEnergyDrink(data: String,
                         volume: Int, price: Double, calories: Int,
                         tagITA: List[String], tagENG: List[String] = List()) extends EnergyDrink(price, volume, data, calories, tagITA, tagENG){}
