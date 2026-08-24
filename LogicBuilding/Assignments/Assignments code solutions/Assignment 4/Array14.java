import java.util.Scanner;

class Array14 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter array size: ");
        int size = sc.nextInt();

        int[] array = new int[size];

        // Input
        for (int i = 0; i < size; i++) {
            System.out.print("Enter element: ");
            array[i] = sc.nextInt();
        }
		
		System.out.print("Search : ");
		int search = sc.nextInt();

	boolean found = false;

	for (int i = 0; i < size; i++) {

    if (array[i] == search) {
  
        System.out.println("Index = " + i);
        found = true;
        break;
    }
}

	if (!found) {
    System.out.println(search + " not found");
}
}
}
