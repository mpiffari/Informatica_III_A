package Pattern_visitor;

abstract class FiguraGeometrica implements Visitable {

}

class Cerchio extends FiguraGeometrica {

	double raggio;
	public Cerchio(double raggio) {
		this.raggio = raggio;
	}
	
	@Override
	public <T> T accept(Visitor<T> v) {
		return v.visit(this);
	}
	
}

class Rettangolo extends FiguraGeometrica {
	
	double latoA;
	double latoB;
	public Rettangolo(double latoA, double latoB) {
		this.latoA = latoA;
		this.latoB = latoB;
	}
	@Override
	public <T> T accept(Visitor<T> v) {
		return v.visit(this);
	}
	
}

class Triangolo extends FiguraGeometrica {

	double latoA;
	double latoB;
	double latoC;
	public Triangolo(double latoA, double latoB, double latoC) {
		this.latoA = latoA;
		this.latoB = latoB;
		this.latoC = latoC;
	}
	
	@Override
	public <T> T accept(Visitor<T> v) {
		return v.visit(this);
	}
}
