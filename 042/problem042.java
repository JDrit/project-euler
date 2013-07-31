import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;

public class problem042 {

  public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("words.txt"));
		HashSet<Integer> triValues = new HashSet<Integer>();
		ArrayList<String> words;
		int count = 0;
		for (int i = 1 ; i < 100000 ; i++) {
			triValues.add((i * (i + 1)) / 2);
		}
		words = new ArrayList<String>(Arrays.asList(br.readLine().replaceAll("\"", "").split(",")));
		br.close();
		
		for (String word : words) {
			int sum = 0;
			for (char c : word.toCharArray()) {
				sum += Character.getNumericValue(c) - 9;
			}
			if (triValues.contains(sum)) {
				count++;
			} 
		}
		System.out.println(count);
	}
}
