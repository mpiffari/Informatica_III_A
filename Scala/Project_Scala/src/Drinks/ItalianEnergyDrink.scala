package Drinks

// Extends abstract class EnergyDrink without adding any arguments: in particoular
// italian energy drink hasn't tagEng, and so we use local intializer for this field
class ItalianEnergyDrink(data: String,
                         volume: Int, price: Double, calories: Int,
                         tagITA: List[String]) extends EnergyDrink(price, volume, data, calories, tagITA, List()){}
