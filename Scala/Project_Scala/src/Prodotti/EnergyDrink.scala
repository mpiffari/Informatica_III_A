package prodotti

import java.time.LocalDate
import java.time.format.DateTimeFormatter
import java.text.SimpleDateFormat
import java.util.Calendar


abstract class EnergyDrink(val price: Double,
                           val volume: Int,
                           val expirationDate: String, 
                           val calories: Int,
                           val tagITA: List[String],
                           val tagENG: List[String]) extends Expirable with Ordered[EnergyDrink]{
  
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
  
  override def compare(rhs: EnergyDrink): Int = {
		  this.calories - rhs.calories
  }
}

/*
object RedBullEnergyDrink {
  def price: Double = 1.00
  def calories: Int = 500
  def tagITA: List[String] = List("caffe","caffeina","studio intenso","studio disperato")
  def tagENG: List[String] = List("coffee","caffeine"," study hard", "study study")
}

object GatoradeEnergyDrink {
  def price: Double = 3.00
  def calories: Int = 500
  def tagITA: List[String] = List("caffe","caffeina","studio intenso","studio disperato")
  def tagENG: List[String] = List("coffee","caffeine"," study hard", "study study")
}

object MonsterEnergyDrink {
  def price: Double = 1.75
  def calories: Int = 356
  def tagITA: List[String] = List("caffe","caffeina","studio intenso","studio disperato")
  def tagENG: List[String] = List("coffee","caffeine"," study hard", "study study")
}*/