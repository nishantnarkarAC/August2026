class LeapYear { 

	public static void checkLeapYear(int Year) {

	if((Year % 4 == 0 && Year % 100 !=0) || (Year % 400 == 0)) {

		System.out.println(Year +" Year is leap year");

	} else {

		System.out.println(Year + " Year is not leap year");
	
		}

	}

		public static void main(String args[]) {


			checkLeapYear(2024);
			checkLeapYear(1900);
	}

}