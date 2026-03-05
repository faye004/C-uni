package esercitazione2;

public class InsiemeN {
	private int[] insieme;
	
	public InsiemeN(int lunghezza) {
		if(lunghezza <= 0) {exception
			throw new ArrayIndexOutOfBoundsException("insieme non esistente");
		}
		insieme = new int[lunghezza];
		for(int i = 0; i < lunghezza; i++) {
			insieme[i] = -1;
		}
	}
	
	public void inserisciElemento(int x) {
		if(!this.contains(x)) {
			for(int i = 0; i < insieme.length; i++) {
				if(insieme[i] == -1) {
					insieme[i] = x;
					break;
				}
			}
		}
	}
	
	public void removeElement(int x) {
		for(int i = 0; i < insieme.length; i++) {
			if(insieme[i] == x) {
				insieme[i] = -1;
				break;
			}
		}
	}
	
	public boolean contains(int x) {
		for(int i = 0; i < insieme.length; i++) {
			if(insieme[i] == x) {
				return true;
			}
		}
		return false;
	}
	
	public void stampa() {
		
	}
}
