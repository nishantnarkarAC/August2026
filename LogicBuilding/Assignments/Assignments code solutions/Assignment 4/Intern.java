
class Intern {

	public static void main(String args[]) {
	
		String str1 = new String("hello");
		String str2 = new String("hello");
		
		System.out.println(str1 == str2);
		
		str1=str1.intern();
		str2=str2.intern();
		
		System.out.println(str1 == str2);
		
   }

}
