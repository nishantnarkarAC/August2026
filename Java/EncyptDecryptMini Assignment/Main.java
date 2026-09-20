import java.util.*;

class Main {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        FileEncryption file = new FileEncryption();

        int choice;

        do {

            System.out.println("1. Encrypt File");
            System.out.println("2. Decrypt File");
            System.out.println("3. Exit");
            System.out.println("4. Enter your choice : ");

            choice = sc.nextInt();
            sc.nextLine();

            switch(choice) {

            case 1:

                System.out.println("Enter file name");
                String inputFile = sc.nextLine();

                System.out.println("Enter Encrypted file");
                String encryptedFile = sc.nextLine();

                file.encryptFile(inputFile, encryptedFile);

                break;


            case 2:

                System.out.println("Enter encrypted file name");
                String encryptedFile1 = sc.nextLine();

                System.out.println("Enter decrypted file name");
                String decryptedFile = sc.nextLine();

                file.decryptFile(encryptedFile1, decryptedFile);

                break;


            case 3:

                System.out.println("Terminate program");

                break;


            default:

                System.out.println("Invalid choice");
            }

        } while(choice != 3);

        sc.close();
    }
}