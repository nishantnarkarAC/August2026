import java.util.*;

class Array8 {

	public static void main(String args[]) {
	
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter size = ");
		int size = sc.nextInt();
		
		String[] names = new String[size];
		
		
		for(int i = 0; i<size; i++) {
			
			System.out.println("Enter name = "+ (i+1));
			names[i] = sc.next();
			
			
		
		}
				System.out.println("Names are : ");
		for(int i = 0; i< size; i++ ) {
			
			System.out.println(names[i]);
			
		}

	}
	

}