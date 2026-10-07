class Attendance {

    // Method to count present days
    static int countPresent(int[] attendance) {

        int present = 0;

        for (int i = 0; i < attendance.length; i++) {

            if (attendance[i] == 1) {
                present++;
            }
        }

        return present;
    }

    // Method to find longest streak
    // value = 1 -> longest presence
    // value = 0 -> longest absence
    static int[] longestStreak(int[] attendance, int value) {

        int current = 0;
        int best = 0;
        int bestEnd = -1;

        for (int i = 0; i < attendance.length; i++) {

            if (attendance[i] == value) {
                current++;
            } else {
                current = 0;
            }

            if (current > best) {
                best = current;
                bestEnd = i;
            }
        }

        // Find starting index of longest streak
        int bestStart = -1;

        if (best > 0) {
            bestStart = bestEnd - best + 1;
        }

        // Return length, start index and end index
        return new int[]{best, bestStart, bestEnd};
    }

    // Method to find extra days needed for 75%
    static int daysNeeded(int present, int total) {

        int extraDays = 0;

        while ((double) (present + extraDays)
                / (total + extraDays) < 0.75) {

            extraDays++;
        }

        return extraDays;
    }

    public static void main(String[] args) {

        int[] attendance = {
            1, 1, 0, 1, 1,
            1, 1, 0, 0,
            1, 1, 1, 1, 1, 0
        };

        // Empty array check
        if (attendance.length == 0) {
            System.out.println("No attendance data.");
            return;
        }

        // --------------------------------
        // 1. Count present days
        // --------------------------------

        int present = countPresent(attendance);

        int total = attendance.length;

        System.out.println("Days present : "
                + present + " of " + total);


        // --------------------------------
        // 2. Calculate attendance percentage
        // --------------------------------

        double percentage =
                (double) present / total * 100;

        System.out.println("Attendance : "
                + String.format("%.2f", percentage) + " %");


        // --------------------------------
        // 3. Check eligibility
        // --------------------------------

        if (percentage >= 75) {
            System.out.println("Eligible : YES");
        } else {
            System.out.println("Eligible : NO");
        }


        // --------------------------------
        // 4. Longest presence
        // --------------------------------

        int[] presence =
                longestStreak(attendance, 1);

        int presenceLength = presence[0];
        int presenceStart = presence[1];
        int presenceEnd = presence[2];

        if (presenceLength > 0) {

            System.out.println(
                "Longest presence : "
                + presenceLength
                + " days (day "
                + (presenceStart + 1)
                + " to day "
                + (presenceEnd + 1)
                + ")"
            );

        } else {

            System.out.println(
                "Longest presence : 0 days"
            );
        }


        // --------------------------------
        // 5. Longest absence
        // --------------------------------

        int[] absence =
                longestStreak(attendance, 0);

        int absenceLength = absence[0];
        int absenceStart = absence[1];
        int absenceEnd = absence[2];

        if (absenceLength > 0) {

            System.out.println(
                "Longest absence : "
                + absenceLength
                + " days (day "
                + (absenceStart + 1)
                + " to day "
                + (absenceEnd + 1)
                + ")"
            );

        } else {

            System.out.println(
                "Longest absence : 0 days"
            );
        }


        // --------------------------------
        // 6. Days needed for 75%
        // --------------------------------

        if (percentage < 75) {

            int extraDays =
                    daysNeeded(present, total);

            int newPresent = present + extraDays;
            int newTotal = total + extraDays;

            double newPercentage =
                    (double) newPresent
                    / newTotal * 100;

            System.out.println(
                "Days needed for 75%: "
                + extraDays
                + " (" + newPresent
                + " of " + newTotal
                + " = "
                + String.format("%.2f", newPercentage)
                + " %)"
            );

        } else {

            System.out.println(
                "Days needed for 75%: 0"
            );
        }
    }
}