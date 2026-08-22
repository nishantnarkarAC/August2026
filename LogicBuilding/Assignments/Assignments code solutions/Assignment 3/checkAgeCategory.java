import java.util.*;

class CheckAge {

	public static int checkAgeCategory(int age) {
	
		if(age<18){
		
			System.out.println("Minor");
		
		} else if(age>=18 && age<=60) {
		
			System.out.println("Adult");
		
		} else
	
			System.out.println("senior citizen");
		return age;
	}

	public static void main(String args[]) {
	
	 Scanner sc = new Scanner(System.in);
	 int age = sc.nextInt();
	 
	 CheckAge checkAgeCategory(age);
	
	}
}