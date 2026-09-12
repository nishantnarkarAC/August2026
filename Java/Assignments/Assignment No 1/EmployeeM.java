class EmployeeM {
	
	private int salary;
	int hours;
	
	
	void setInfo(int salary, int hours) {
		this.salary = salary;
		this.hours = hours;
	}
	
	int getSalary() {
		
		return salary;
	}
	
	int getHours() {
		
		return hours;
	}
	
	void getInfo() {
		System.out.println(salary);
		System.out.println(hours);
	}
	
	void addSalary() {
		
		if(salary < 500 ) {
			salary+=10;
		} else {
		
		}
	}
	
	void addWork() {
		
		if(hours > 6 ) {
			salary+=5;
		} else {
		
		}
	}
	
	public static void main(String args[]) {
	
		EmployeeM e1 = new EmployeeM();
		
		e1.setInfo(410, 7);
		
//		System.out.println(e1.getSalary());
//		System.out.println(e1.getHours());
		
		e1.getInfo();
		
		e1.addSalary();
		e1.addWork();
		
		
		e1.getInfo();
	}
	
	
}