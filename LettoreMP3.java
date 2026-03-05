package esercitazione2;

public class LettoreMP3 {
	private int numeroSerie;
	//private final int numeroSerie; // questo fa si che, non appena assegni un valore a numeroSerie, quel valore gli rimmarrà assegnato per sempre
	//impossibile cambiarlo dunque
	
	public LettoreMP3(int numeroSerie){
		if(numeroSerie<0) {
			throw new IllegalArgumentException("Non puoi creare un lettore con un numero seriale negativo");
		}
		this.numeroSerie = numeroSerie; // this sta ad indicare  l'attributo numeroSerie di QUESTO oggetto
		//this.setNumeroSerie(numeroSerie);
	}
	
	public void setNumeroSerie(int numeroSerie) {
		if(numeroSerie<0) {
			throw new IllegalArgumentException("Non puoi creare un lettore con un numero seriale negativo");
		}
		this.numeroSerie = numeroSerie;
	}
	
	public int getNumeroSerie() {
		return numeroSerie;
	}
}
