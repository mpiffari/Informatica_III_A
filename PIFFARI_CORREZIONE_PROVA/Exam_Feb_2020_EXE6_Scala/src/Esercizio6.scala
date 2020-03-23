import java.util.ArrayList

object Esercizio6 {
  // =====================================================================
	def prodPariFino_iterativo(N: Int): Int = {
			var prodotto: Int  = 1;
			for(n <- 1 to N) {
				if(n % 2 == 0) {
					prodotto = prodotto * n
				}
			}
			prodotto
	}

	def prodPariFino_ricorsivo(N: Int): Int = {
			if(N == 1) {
				1
			} else {
				if(N % 2 == 0) {
					N * prodPariFino_ricorsivo(N - 1)
				} else {
					prodPariFino_ricorsivo(N -1)
				}
			}
	}
	
  def prodPariFino_ricorsivoTail(N: Int): Int = {
    def prodPariFino_ricorsivoTail_wrapped(N: Int, acc: Int): Int = {
			if(N == 1) {
				acc
			} else {
				if(N % 2 == 0) {prodPariFino_ricorsivoTail_wrapped(N - 1, (acc * N))
				} else {
					prodPariFino_ricorsivoTail_wrapped(N - 1, acc)
				}
			}
	  }
    prodPariFino_ricorsivoTail_wrapped(N,1);
  }
	// =====================================================================

	def spp_for(list: List[Int]): Int = {
			var somma = 0
			for(n <- list) {
				somma = somma + prodPariFino_ricorsivoTail(n)
			}
			somma
	}

	def spp_forEach(list: List[Int]): Int = {
			var somma = 0

			def customFunction(N: Int) {
				somma = somma + prodPariFino_ricorsivoTail(N)
			}

			list.foreach(customFunction)
			somma
	}

	def spp_ric(list: List[Int]): Int = {
			if(list.size == 0) {
				0
			} else {
				prodPariFino_ricorsivoTail(list.head) + spp_ric(list.tail)
			}
	}
	
	def spp_ricTail(list: List[Int]): Int = {
	  def spp_ricTail_wrapper(list: List[Int], acc: Int): Int = {
			if(list.size == 0) {
				acc
			} else {
				spp_ricTail_wrapper(list.tail, (acc + prodPariFino_ricorsivoTail(list.head)))
			}
	  }
	  spp_ricTail_wrapper(list, 0);
	}


	def spp_filter(list: List[Int]): Int = {
			var somma = 0

			def customFunction(n: Int): Boolean = {
			  somma = somma + prodPariFino_ricorsivoTail(n)
				true
			}

			list.filter(customFunction)
			somma
	}

	def spp_map(list: List[Int]): Int = {
		def customFunction(n: Int): Int = {
				prodPariFino_ricorsivoTail(n)

		}
		list.map(customFunction).sum
	}
	
	def spp_fold_left(list: List[Int]): Int = {
		def customFunction(acc: Int, n: Int): Int = {
			 acc + prodPariFino_ricorsivoTail(n)
		}		

		list.foldLeft(0)(customFunction)
	}

	def spp_fold_right(list: List[Int]): Int = {
		def customFunction(n: Int, acc: Int): Int = {
				acc + prodPariFino_ricorsivoTail(n)
		}		

		list.foldRight(0)(customFunction)
	}
	
	def spp_HOF(f: Int => Int, list: List[Int]): Int = {
			list.map(f).sum
	}

	def main(args: Array[String]): Unit = {
			println("ITERATIVO " + prodPariFino_iterativo(5))
			println("RICORSIVO " + prodPariFino_ricorsivo(5))
			println("TAIL " + prodPariFino_ricorsivoTail(5))

			var lista: List[Int] = List(5,5,5)
			println("SPP FOR " +spp_for(lista))
			println("SPP FOR EACH " +spp_forEach(lista))
			println("SPP RIC " +spp_ric(lista))
			println("SPP RIC TAIL " +spp_ricTail(lista))
			println("SPP FILTER " +spp_filter(lista))
			println("SPP MAP " +spp_map(lista))
			println("SPP FOLD LEFT " +spp_fold_left(lista))
			println("SPP FOLD RIGHT " +spp_fold_right(lista))
			
			// Filtro numeri divisibili per uno specifico numero j
			def f(j: Int)(N: Int): Int =  {
			  var prodotto = 1
				for(n <- 1 to N) {
					if(n % j == 0) {
						prodotto = prodotto * n
					}
				}
			  prodotto
			}
			
			val criterio = f(5)(_)
			println("SPP HOF " + spp_HOF(criterio, lista))
	}
}