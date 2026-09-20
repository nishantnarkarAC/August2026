import java.util.ArrayList;
import java.util.Collections;

class New {
	
	public static void main(String args[]) {
		
		ArrayList<String> Ai = new ArrayList<String>();
		
		Ai.add("Red");
		Ai.add("Blue");
		Ai.add("Yellow");
		Ai.add("Green");
		Ai.add("Pink");
		
		ArrayList<String> Ai2 = new ArrayList<String>();
		
		Ai2.add(null);
		Ai2.add(null);
		Ai2.add(null);
		Ai2.add(null);
		Ai2.add(null);
		
		Collections.sort(Ai);
		System.out.println(Ai);
		
		Collections.shuffle(Ai);
		System.out.println(Ai);
		
		Collections.copy(Ai2, Ai);
		System.out.println(Ai2);
		
		Collections.reverse(Ai2);
		System.out.println(Ai2);
		
	}
}