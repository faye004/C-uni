package Figura;
import java.util.*;

public abstract class Figura {
	
	//public Figura() {} //il costruttore non serve
	public Figura() {}
	
	public abstract double getArea();
	
	public abstract double getPerimetro();
	
	public boolean haAreaMaggiore(Figura r) {
		if(r.getArea() < this.getArea()) {
			return true;
		}
		
		return false;
		
		//return this.getArea() > r.getArea
	}
	
	public boolean haPerimetroMaggiore(Figura r) {
		if(r.getPerimetro() < this.getPerimetro()) {
			return true;
		}
		
		return false;
	}
	
	public boolean equals(Figura r) {
		if(r.toString() == super.toString()) {
			return true;
		}
		
		return false;
	}
	
	/*
	//soluzione del prof
	private double lato1;
	private double lato2;
	public boolean equals(Figura r) { //soluzione del prof
		if(r instanceof Rettangolo) {
			return true;
		}
		
		Rettangolo r1 = (Rettangolo) r;
		
		return this.lato1 == r1.lato1 && this.lato2 == r1.lato2;
	}
	*/
	
	public static void main(String[] args) {
		int n = 0, lato1, lato2, index = 0;
		double max_area = -1;
		Scanner sc = new Scanner(System.in);
		Figura[] figure;
		
		Figura f1 = new Cerchio(9);
		Figura f2 = new Quadrato(5);
		Figura f3 = new Rettangolo(3, 2);
		
		System.out.println(f1.toString() + "\n" + f2.toString() + "\n" + f3.toString());
		
		System.out.println("Quanti rettangoli vuoi inserire? ");
		n = sc.nextInt();
		figure = new Rettangolo[n];
		
		for(int i = 0; i < n; i++) {
			System.out.println("Inserisci la base del rettangolo n. " + n + ": ");
			lato1 = sc.nextInt();
			System.out.println("Inserisci l'altezza rettangolo del rettangolo n. " + n + ": ");
			lato2 = sc.nextInt();
			figure[i] = new Rettangolo(lato1, lato2);
		}
		
		for(int i = 0; i < n; i++) {
			if(max_area < figure[i].getArea()) {
				max_area = figure[i].getArea();
				index = i;
			}
		}
		
		System.out.println("Il rettangolo con la maggiore area è: \n" + figure[index].toString());
	}
}
