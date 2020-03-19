package Drinks

import java.time.LocalDate
import java.time.format.DateTimeFormatter
import java.text.SimpleDateFormat
import java.util.Calendar

// Extends abstract class Expirable and add proper arguments and function
abstract class EnergyDrink(val price: Double,
                           val volume: Int,
                           val expirationDate: String, 
                           val calories: Int,
                           val tagITA: List[String],
                           val tagENG: List[String]) extends Expirable {
  
  override def isExpired(): Boolean = {

    val formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd")
    val d = LocalDate.parse(expirationDate, formatter)
    
    val format = new SimpleDateFormat("yyyy-MM-dd")
		val currentDate = format.format(Calendar.getInstance().getTime())
		val now = LocalDate.parse(currentDate, formatter)
                                            
		now.toEpochDay() - d.toEpochDay() > 0
  }
  
  def nutritionalValues() = calories match {
       case i1: Int if calories <= 100  => IpoCalorico
       case i2: Int if calories < 1000  => NormoCalorico
       case i3: Int if calories >= 1000 => IperCalorico
  }
}