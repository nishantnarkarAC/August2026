import java.util.*;

class Array11 {

	public static void main(String args[]) {
	
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter size = ");
		int size = sc.nextInt();
		
		int[i] array = new int[size];
		
		
		for(int i = 0; i<size; i++) {
			
			System.out.println("Enter element = ");
			array[i] = sc.nextInt();
		
			}
		
		
		for(int i = 0; i<size; i++) {
			
			for(int j = i+1; j<size; j++) {
				
				if(array[i]>array[j]) {
					int temp = aaaray[i];
					array[i] = array[j];
					aaray[j] = temp;					
					
				}
				
				}
				
			}
			
			
			System.out.println("Ascending order = ");
			array[i] = sc.nextInt();
		
			for(i = 0; i < size; i++){
				
				System.out.println(array[i]);
				
			}

	}
	

}