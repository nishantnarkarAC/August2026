import java.util.*;

class Array10 {

	public static void main(String args[]) {
	
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter size = ");
		int size = sc.nextInt();
		
		int[] array = new int[size];
		int sum = 0;
		
		
		for(int i = 0; i<size; i++) {
			
			System.out.println("Enter element = ");
			array[i] = sc.nextInt();
			sum = sum+ array[i];
		
			}
			
			double avg = (double)sum/size;
	

			System.out.println("Average : "+avg);

	}
	

}