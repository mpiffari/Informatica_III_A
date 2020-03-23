package Pattern_visitor;

public interface Visitor<T> {
	T visit(Rettangolo r);
	T visit(Cerchio c);
	T visit(Triangolo t);
}

class CalcolaPerimetro implements Visitor<Double> {

	@Override
	public Double visit(Rettangolo r) {
		return 2 * (r.latoA + r.latoB);
	}

	@Override
	public Double visit(Cerchio c) {
		return 2 * Math.PI * c.raggio;
	}

	@Override
	public Double visit(Triangolo t) {
		return t.latoA + t.latoB + t.latoC;
	}
	
}

class CalcolaArea implements Visitor<Double> {

	@Override
	public Double visit(Rettangolo r) {
		return r.latoA * r.latoB;
	}

	@Override
	public Double visit(Cerchio c) {
		return Math.PI * (c.raggio * c.raggio);
	}

	@Override
	public Double visit(Triangolo t) {
		CalcolaPerimetro cp = new CalcolaPerimetro();
		double p = t.accept(cp);
		return Math.sqrt(p * (p - t.latoA) * (p - t.latoB) * (p - t.latoC));
	}
	
}

class creaDescrizione implements Visitor<String> {

	@Override
	public String visit(Rettangolo r) {
		CalcolaPerimetro cp = new CalcolaPerimetro();
		CalcolaArea ca = new CalcolaArea();
		double p = r.accept(cp);
		double a = r.accept(ca);
		return "RETTANGOLO - Perimetro: " + p + " ~ Area: " + a;
	}

	@Override
	public String visit(Cerchio c) {
		CalcolaPerimetro cp = new CalcolaPerimetro();
		CalcolaArea ca = new CalcolaArea();
		double p = c.accept(cp);
		double a = c.accept(ca);
		return "CERCHIO - Perimetro: " + p + " ~ Area: " + a;
	}

	@Override
	public String visit(Triangolo t) {
		CalcolaPerimetro cp = new CalcolaPerimetro();
		CalcolaArea ca = new CalcolaArea();
		double p = t.accept(cp);
		double a = t.accept(ca);
		return "TRIANGOLO - Perimetro: " + p + " ~ Area: " + a;
	}
	
}