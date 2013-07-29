public class problem041 {

  private static int [] generatePrimes(int max) {
		boolean[] isComposite = new boolean[max + 1];
		for (int i = 2; i * i <= max; i++) {
			if (!isComposite [i]) {
				for (int j = i; i * j <= max; j++) {
					isComposite [i*j] = true;
				}
			}
		}
		int numPrimes = 0;
		for (int i = 2; i <= max; i++) {
			if (!isComposite [i]) numPrimes++;
		}
		int [] primes = new int [numPrimes];
		int index = 0;
		for (int i = 2; i <= max; i++) {
			if (!isComposite [i]) primes [index++] = i;
		}
		return primes;
	}

	public static boolean isPandigital(int number) {
		boolean[] lst = new boolean[10];
		for (Character c : new Integer(number).toString().toCharArray()) {
			if (lst[Character.getNumericValue(c)] == true) {
				return false;
			} else {
				lst[Character.getNumericValue(c)] = true;
			}
		}
		for (int i = 1 ; i <= new Integer(number).toString().length() ; i++) {
			if (lst[i] == false) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) {
		int best = 0;
		for (int i : generatePrimes(987654321)) {
			if (isPandigital(i)) {
				best = i;
			}
		}
		System.out.println(best);

	}
}
