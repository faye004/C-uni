package Figura;

public class Quadrato extends Rettangolo{
	public Quadrato(double x) {
		super(x, x);
		//base = x;
		//altezza = x;
	}
	
	public double getLato() {
		return super.getBase();
	}
	
	public String toString() {
		return ("Quadrato, lato=" + base + ".");
	}
}
