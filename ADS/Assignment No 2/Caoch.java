class Coach {
    String id;
    String type;
    Coach next;

    Coach(String id, String type) {
        this.id = id;
        this.type = type;
    }
}

public class Train {

    private Coach head = new Coach("ENGINE", "ENGINE");
    private Coach tail = head;
    private int count = 0;

    public void attach(String id, String type) {

        Coach temp = head;

        while (temp != null) {
            if (temp.id.equals(id)) {
                System.out.println("Duplicate coach ID");
                return;
            }
            temp = temp.next;
        }

        Coach newCoach = new Coach(id, type);

        tail.next = newCoach;
        tail = newCoach;
        count++;
    }

    public boolean insertAfter(String afterId, String id, String type) {

        Coach temp = head;

        while (temp != null) {

            if (temp.id.equals(id)) {
                System.out.println("Duplicate coach ID");
                return false;
            }

            temp = temp.next;
        }

        temp = head;

        while (temp != null) {

            if (temp.id.equals(afterId)) {

                Coach newCoach = new Coach(id, type);

                newCoach.next = temp.next;
                temp.next = newCoach;

                if (temp == tail) {
                    tail = newCoach;
                }

                count++;
                return true;
            }

            temp = temp.next;
        }

        return false;
    }

    public boolean detach(String id) {

        if (id.equals("ENGINE")) {
            return false;
        }

        Coach prev = head;

        while (prev.next != null &&
               !prev.next.id.equals(id)) {
            prev = prev.next;
        }

        if (prev.next == null) {
            return false;
        }

        if (prev.next == tail) {
            tail = prev;
        }

        prev.next = prev.next.next;
        count--;

        return true;
    }

    public int position(String id) {

        Coach temp = head.next;
        int position = 1;

        while (temp != null) {

            if (temp.id.equals(id)) {
                return position;
            }

            position++;
            temp = temp.next;
        }

        return -1;
    }

    public int countType(String type) {

        int countType = 0;
        Coach temp = head.next;

        while (temp != null) {

            if (temp.type.equals(type)) {
                countType++;
            }

            temp = temp.next;
        }

        return countType;
    }

    public void display() {

        Coach temp = head;

        while (temp != null) {
            System.out.print(temp.id);

            if (temp.next != null) {
                System.out.print(" -> ");
            }

            temp = temp.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {

        Train train = new Train();

        train.attach("S1", "SLEEPER");
        train.attach("S2", "SLEEPER");
        train.attach("S3", "SLEEPER");
        train.attach("GEN1", "GENERAL");

        train.insertAfter("S2", "PC", "PANTRY");

        train.detach("S3");

        train.display();

        System.out.println(train.countType("SLEEPER"));
        System.out.println(train.position("PC"));
        System.out.println(train.count);
    }
}