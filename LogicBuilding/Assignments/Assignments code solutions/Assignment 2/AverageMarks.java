class AverageMarks {

	public static void main(String args[]) {

	int maths = 69;

	int science = 78;

	int history = 37;

	int averageMarks =(maths + science + history)/3;
	
	String Grade;

	if(averageMarks>90) {
	
		Grade = "A";
	
	} else if(averageMarks>=70 && averageMarks<=89) {

		Grade = "B";

	} else if(averageMarks>=50 && averageMarks<=69) {

		Grade = "C";

	} else if(averageMarks>=30 && averageMarks<=49) {

		Grade = "D";
	} else {

		Grade = "F";
		
		}	

		System.out.println("AverageMarks = " + averageMarks);

		if(Grade.equals("F")) {

		System.out.println("Fail");
		
		} else {

		System.out.println("Grade = " + Grade);
		
		}
	

	}

}