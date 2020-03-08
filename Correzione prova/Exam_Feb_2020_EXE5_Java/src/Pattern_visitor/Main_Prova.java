package Pattern_visitor;

import java.util.ArrayList;
import java.util.List;

public class Main_Prova {

	public static void main(String[] args) {
		Rettangolo r1 = new Rettangolo(5.0, 5.0);
		Cerchio c1 = new Cerchio(4.0);
		Triangolo t1 = new Triangolo(4.0, 2.0, 3.0);

		creaDescrizione cd = new creaDescrizione();
		System.out.println(r1.accept(cd));
		System.out.println(c1.accept(cd));
		System.out.println(t1.accept(cd));
		
		List<FiguraGeometrica> list = new ArrayList<FiguraGeometrica>();
		list.add(r1);
		list.add(c1);
		list.add(t1);
		System.out.println("Figura con area max: " + calcolaMax(list).accept(cd));
	}
	
	static FiguraGeometrica calcolaMax(List<FiguraGeometrica> list) {
		CalcolaArea ca = new CalcolaArea();
		FiguraGeometrica maxFigura = list.get(0);
		for (FiguraGeometrica figuraGeometrica : list) {
			// Automatically inferred which accept called (not neeed specific Visitor for FiguraGeometrica with instanceOf)
			if(figuraGeometrica.accept(ca) > maxFigura.accept(ca)) {
				maxFigura = figuraGeometrica;
			}
		}
		return maxFigura;
	}
}
