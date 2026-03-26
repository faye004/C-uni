package Figura;

public class Rettangolo extends Figura{
	protected double base;
	protected double altezza;
	
	public Rettangolo(double x, double y) {
		base = x;
		altezza = y;
	}
	
	public double getAltezza() {
		return altezza;
	}
	
	public double getBase() {
		return base;
	}
	
	@Override
	public double getArea() {
		return (base*altezza);
	}
	
	@Override
	public double getPerimetro() {
		return (2*(base+altezza));
	}
	
	@Override
	public String toString() {
		return ("Rettangolo, base=" + base + ", altezza=" + altezza + ".");
	}
	
}
