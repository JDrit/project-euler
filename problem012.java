import java.util.HashSet;

public class problem012 {
  
    private static int factorCount(long number) {
        HashSet<Long> factors = new HashSet<Long>();
        for (long f = 1; f <= Math.sqrt(number); f++) {
            if (number % f == 0) {
                factors.add(f);
            }
        }
        HashSet<Long> factors2 = new HashSet<Long>();
        for (long l : factors) {
            factors2.add(number / l);
        }
        factors.addAll(factors2);
        return factors.size();
    }
    
	public static void main(String[] args) {
		int count = 3;
		int current = 3;
		while (true) {			
			if (factorCount(current + count) > 500) {
				System.out.println(current + count);
				break;
			}
			current += count;
			count++;
		}
	}
}
