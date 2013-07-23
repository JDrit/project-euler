import java.util.HashSet;


public class problem029 {

  public static void main(String[] args) {
		HashSet<Double> numbers = new HashSet<Double>();
		for (int a = 2 ; a <= 100 ; a++) {
			for (int b = 2; b <= 100 ; b++) {
				numbers.add( Math.pow(a, b));
			}
		}
		System.out.println(numbers.size());
		
	}

}
