import java.util.*;

public class ColorList {
	
	public static void main(String args[]) {
		
		ArrayList Al = new ArrayList();
		
		Al.add("Red");
		Al.add("Green");
		Al.add("Blue");
		Al.add("Pink");
		Al.add("Orange");
		Al.add(1,"white");
		
		System.out.println(Al);
		
		System.out.println(Al.get(0));
		System.out.println(Al.set(3, "Black"));
		System.out.println(Al.remove(5));
		System.out.println(Al.contains("white"));
		
		System.out.println(Al);
	}
}