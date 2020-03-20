package Drinks

// Sealed to guarantee that all subclass will be declared in the same file [here]
sealed trait Calorico

case class IpoCalorico() extends Calorico
case class NormoCalorico() extends Calorico
case class IperCalorico() extends Calorico
