package Main

import distributore.DistributoreAutomatico
import prodotti._

object Main {
  
  def main(args:Array[String]):Unit={
    var dis = new DistributoreAutomatico
    
    dis.show 
    
    dis.aggiungiProdotto(new SuccoPera(data="2000-01-01"))
    dis.aggiungiProdotto(new SuccoPera("2020-01-01"))
    dis.aggiungiProdotto(new SuccoPesca("2020-01-01"))
    dis.aggiungiProdotto(new SuccoPesca("2020-01-01"))
    dis.aggiungiProdotto(new SuccoPesca("2020-01-01"))
    dis.aggiungiProdotto(new SuccoAlbicocca("2020-01-01"))
    
    dis.show
    
    println("Resto: "+dis.vendi(1,10) +"\n")
    println("Resto: "+dis.vendi(1,10) +"\n")
    dis.show
    println("Resto: "+dis.vendi(1,10) +"\n")
    println("Resto: "+dis.vendi(2,10) +"\n")
    println("Resto: "+dis.vendi(3,10) +"\n") 
  } 
}