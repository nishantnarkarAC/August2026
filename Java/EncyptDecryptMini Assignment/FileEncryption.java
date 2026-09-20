import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

class FileEncryption {

    public void encryptFile(String inputFile, String encryptedFile) {

        try {

            FileReader reader = new FileReader(inputFile);
            FileWriter writer = new FileWriter(encryptedFile);

            int ch;

            while ((ch = reader.read()) != -1) {

                char encryptedChar = (char)(ch + 3);

                writer.write(encryptedChar);
            }

            reader.close();
            writer.close();

            System.out.println("File encrypted successfully.");

        } catch (IOException e) {

            System.out.println("Error: " + e.getMessage());
        }
    }


    public void decryptFile(String encryptedFile, String decryptedFile) {

        try {

            FileReader reader = new FileReader(encryptedFile);
            FileWriter writer = new FileWriter(decryptedFile);

            int ch;

            while ((ch = reader.read()) != -1) {

                char decryptedChar = (char)(ch - 3);

                writer.write(decryptedChar);
            }

            reader.close();
            writer.close();

            System.out.println("File decrypted successfully.");

        } catch (IOException e) {

            System.out.println("Error: " + e.getMessage());
        }
    }
}