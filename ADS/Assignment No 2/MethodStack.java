class MethodStack {
    private String[] data = new String[10];
    private int top = -1;

    boolean push(String m) {
        if (top == data.length - 1) {
            return false;
        }
        data[++top] = m;
        return true;
    }

    String pop() {
        if (top == -1) {
            return null;
        }
        return data[top--];
    }

    String peek() {
        if (top == -1) {
            return null;
        }
        return data[top];
    }

    boolean isEmpty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }

    void printTrace() {
        for (int i = top; i >= 0; i--) {
            System.out.println("at " + data[i]);
        }
    }
}

public class CrashReporter {
    public static void main(String[] args) {

        String[] log = {
            "ENTER main",
            "ENTER placeOrder",
            "ENTER validateCart",
            "EXIT validateCart",
            "ENTER processPayment",
            "ENTER connectBank",
            "CRASH"
        };

        MethodStack stack = new MethodStack();
        int maxDepth = 0;

        for (int i = 0; i < log.length; i++) {

            String[] parts = log[i].split(" ");

            if (parts[0].equals("ENTER")) {
                if (!stack.push(parts[1])) {
                    System.out.println("StackOverflowError: call depth exceeded 10");
                    return;
                }

                if (stack.size() > maxDepth) {
                    maxDepth = stack.size();
                }

            } else if (parts[0].equals("EXIT")) {

                if (stack.peek() == null || !stack.peek().equals(parts[1])) {
                    System.out.println("Invalid EXIT at line " + (i + 1));
                    return;
                }

                stack.pop();

            } else if (parts[0].equals("CRASH")) {

                System.out.println("Application crashed at line " + (i + 1) + ". Stack trace:");
                stack.printTrace();
                System.out.println("Maximum call depth reached: " + maxDepth);
                return;
            }
        }

        System.out.println("Program finished normally");
    }
}