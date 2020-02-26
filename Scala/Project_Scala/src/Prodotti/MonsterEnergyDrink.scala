package Prodotti
import prodotti.EnergyDrink

class MonsterEnergyDrink(data: String,
                         volume: Int, price: Double, calories: Int,
                         tagITA: List[String], tagENG: List[String]) extends EnergyDrink(price, volume, data, calories, tagITA, tagENG){}
