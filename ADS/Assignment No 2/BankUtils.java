public class BankUtils {

    static int countDigits(long n) {

        if (n < 0) {
            n = -n;
        }

        if (n < 10) {
            return 1;
        }

        return 1 + countDigits(n / 10);
    }

    static int sumDigits(long n) {

        if (n < 0) {
            n = -n;
        }

        if (n == 0) {
            return 0;
        }

        return (int)(n % 10) + sumDigits(n / 10);
    }

    static int digitalRoot(long n) {

        if (n < 0) {
            n = -n;
        }

        if (n < 10) {
            return (int)n;
        }

        return digitalRoot(sumDigits(n));
    }

    static String mask(String acc) {

        if (acc.length() <= 4) {
            return acc;
        }

        return "X" + mask(acc.substring(1));
    }

    static double amount(double p, double r, int years) {

        if (years == 0) {
            return p;
        }

        return amount(p, r, years - 1) * (1 + r / 100);
    }

    public static void main(String[] args) {

        System.out.println(countDigits(4096013));
        System.out.println(sumDigits(4096013));
        System.out.println(digitalRoot(4096013));
        System.out.println(mask("123456789012"));
        System.out.printf("%.2f", amount(10000, 10, 3));
    }
}