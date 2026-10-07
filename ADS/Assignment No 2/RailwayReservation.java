import java.util.Scanner;

class RailwayReservation {

    static boolean[] booked;
    static int n;

    // Find berth type from berth number
    static String getBerthType(int berth) {

        int type = berth % 8;

        if (type == 1 || type == 4) {
            return "LB";
        } 
        else if (type == 2 || type == 5) {
            return "MB";
        } 
        else if (type == 3 || type == 6) {
            return "UB";
        } 
        else if (type == 7) {
            return "SL";
        } 
        else {
            return "SU";
        }
    }

    // Book the first free berth of requested type
    static void book(String requestedType) {

        // First search for requested berth type
        for (int i = 1; i <= n; i++) {

            if (!booked[i] &&
                getBerthType(i).equals(requestedType)) {

                booked[i] = true;

                System.out.println(
                    "Berth " + i + " (" + requestedType + ") booked"
                );

                return;
            }
        }

        // If requested type is not available,
        // find any free berth
        for (int i = 1; i <= n; i++) {

            if (!booked[i]) {

                booked[i] = true;

                System.out.println(
                    "No " + requestedType +
                    " free. Berth " + i +
                    " (" + getBerthType(i) +
                    ") allotted instead"
                );

                return;
            }
        }

        // No berth available
        System.out.println("Waiting List");
    }

    // Cancel a berth
    static void cancel(int berth) {

        // Check whether berth number is valid
        if (berth < 1 || berth > n) {
            System.out.println("Invalid berth number");
            return;
        }

        // Check whether berth is actually booked
        if (!booked[berth]) {
            System.out.println(
                "Berth " + berth + " is not booked"
            );
            return;
        }

        booked[berth] = false;

        System.out.println(
            "Berth " + berth + " cancelled"
        );
    }

    // Count available berths
    static void available() {

        int count = 0;

        for (int i = 1; i <= n; i++) {

            if (!booked[i]) {
                count++;
            }
        }

        System.out.println(
            count + " berths free"
        );
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of berths: ");
        n = sc.nextInt();

        // N + 1 because we ignore index 0
        booked = new boolean[n + 1];

        while (true) {

            System.out.println("\n--- Railway Reservation ---");
            System.out.println("1. Book");
            System.out.println("2. Cancel");
            System.out.println("3. Available");
            System.out.println("4. Exit");

            System.out.print("Enter choice: ");
            int choice = sc.nextInt();

            switch (choice) {

                case 1:

                    System.out.print(
                        "Enter berth type (LB/MB/UB/SL/SU): "
                    );

                    String type = sc.next().toUpperCase();

                    book(type);

                    break;

                case 2:

                    System.out.print(
                        "Enter berth number to cancel: "
                    );

                    int berth = sc.nextInt();

                    cancel(berth);

                    break;

                case 3:

                    available();

                    break;

                case 4:

                    System.out.println("Exiting...");
                    sc.close();
                    return;

                default:

                    System.out.println(
                        "Invalid choice"
                    );
            }
        }
    }
}