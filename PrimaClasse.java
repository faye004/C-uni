package gestioneordini;

import java.util.Scanner;

public class PrimaClasse {

	//vari commenti
	
	/*commenti*/
	
	/*
	 * errore di compilazione: errore nel codice che non permette al compilatore di leggere quello che c'è scritto,
	 *  quindi non riesce a generare il bytecode (o file eseguibile)
	 *  qui è segnato con una lucina gialla e rossa sul lato dello schermo
	 * */
	
	//cerca debugging and developing perspective, e come si fa il debug, in modo da imparare
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Benvenuti al corso");
		System.out.println("Inserisci il tuo nome qui sotto : "); // se scrivi "Syso" poi premi ctrl + spazio + invio di scriverà System.out.println();
		String name = sc.nextLine();
		System.out.println("Ciao " + name + ", come stai?");
		
		Bike bike1 = new Bike();
		Bike bike2 = new Bike();
	}
}
