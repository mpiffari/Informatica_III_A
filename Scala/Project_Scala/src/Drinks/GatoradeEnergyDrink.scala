package Drinks

// Extends abstract class EnergyDrink without adding any arguments
class GatoradeEnergyDrink(data: String,
                         volume: Int, price: Double, calories: Int,
                         tagITA: List[String], tagENG: List[String]) extends EnergyDrink(price, volume, data, calories, tagITA, tagENG){}
