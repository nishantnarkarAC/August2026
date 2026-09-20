import java.util.*;

class Numbertree {
	
	public static void main(String args[])  {
		
		TreeSet<Integer> ts = new TreeSet<Integer>();
		
		ts.add(12);
		ts.add(23);
		ts.add(78);
		ts.add(77);
		
		int num = 75;
		
		int result = ts.ceiling(75);
		
		System.out.println(result);
	}
	
}