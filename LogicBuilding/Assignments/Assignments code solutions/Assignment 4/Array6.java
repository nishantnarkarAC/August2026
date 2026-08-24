import java.util.*;

class Array6 {

	public static void main(String args[]) {
	
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter size = ");
		int size = sc.nextInt();
		
		int[] array = new int[5];
		
		
		for(int i = 0; i<size; i++) {
			
			System.out.println("Enter element = ");
			array[i] = sc.nextInt();
			
			
		
		}
				System.out.println("elements are : ");
		for(int i = 0; i< size; i++ ) {
			
			System.out.println(array[i]);
			
		}

	}
	

}