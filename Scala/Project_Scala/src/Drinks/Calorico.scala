package Drinks

sealed trait Calorico

final case class IpoCalorico() extends Calorico
final case class NormoCalorico() extends Calorico
final case class IperCalorico() extends Calorico
