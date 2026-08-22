import java.util.*;

class CheckAge {

	public static String checkAgeCategory(int age) {
	
		if(age<18){
		
			return "Minor";
		
		} else if(age>=18 && age<=60) {
		
			return "Adult";
		
		} else
	
			return "Senior citizen";
	
	}

	public static void main(String args[]) {
	
	 Scanner sc = new Scanner(System.in);
	 int age = sc.nextInt();
	 
	 String result = checkAgeCategory(age);
	 System.out.println(result);
	
	}
}