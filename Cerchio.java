package Figura;

public class Cerchio extends Figura{
	private double raggio;
	
	public Cerchio(double r) {
		raggio = r;
	}
	
	public double getRaggio() {
		return raggio;
	}
	
	public double getArea(){
		return (Math.PI*raggio*raggio); //Math.PI richiama l'attributo STATICO della classe Math che corrisponde al pi-greco
	}
	
	public double getCirconferenza(){
		return (raggio*2*Math.PI); //Math.PI richiama l'attributo STATICO della classe Math che corrisponde al pi-greco
	}
	
	public double getPerimetro(){
		return getCirconferenza();
	}
	
	public String toString(){
		return "Cerchio, raggio = r";
	}
}
