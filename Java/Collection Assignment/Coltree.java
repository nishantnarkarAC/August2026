import java.util.*;

class Coltree {
	
	public static void main(String args[]) {
		
		TreeSet <String> Ts = new TreeSet<String>();
		
		Ts.add("Red");
		Ts.add("Blue");
		Ts.add("Yellow");
		Ts.add("Green");
		
		System.out.println(Ts);
		
		TreeSet <String> Ts2 = new TreeSet<String>();
		
		Ts.add("White");
		Ts.add("Black");
		
		Ts2.addAll(Ts);
		
		System.out.println(Ts2);

		
		
		System.out.println(Ts2.descendingSet());
		
		System.out.println(Ts2.getFirst());
		
		System.out.println(Ts2.getLast());
		
	}
}