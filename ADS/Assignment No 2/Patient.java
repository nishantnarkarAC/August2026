class Patient {
    String name;
    Patient prev;
    Patient next;

    Patient(String n) {
        name = n;
    }
}

public class WaitingList {

    private Patient head;
    private Patient tail;
    private int size;

    public void addNormal(String name) {

        Patient newPatient = new Patient(name);

        if (head == null) {
            head = tail = newPatient;
        } else {
            tail.next = newPatient;
            newPatient.prev = tail;
            tail = newPatient;
        }

        size++;
    }

    public void addEmergency(String name) {

        Patient newPatient = new Patient(name);

        if (head == null) {
            head = tail = newPatient;
        } else {
            newPatient.next = head;
            head.prev = newPatient;
            head = newPatient;
        }

        size++;
    }

    public String callNext() {

        if (head == null) {
            return null;
        }

        String name = head.name;

        head = head.next;

        if (head == null) {
            tail = null;
        } else {
            head.prev = null;
        }

        size--;

        return name;
    }

    public boolean leave(String name) {

        Patient temp = head;

        while (temp != null) {

            if (temp.name.equals(name)) {

                if (temp.prev != null) {
                    temp.prev.next = temp.next;
                } else {
                    head = temp.next;
                }

                if (temp.next != null) {
                    temp.next.prev = temp.prev;
                } else {
                    tail = temp.prev;
                }

                size--;
                return true;
            }

            temp = temp.next;
        }

        return false;
    }

    public void display() {

        Patient temp = head;

        while (temp != null) {
            System.out.print(temp.name + " ");

            temp = temp.next;
        }

        System.out.println();
    }

    public void displayReverse() {

        Patient temp = tail;

        while (temp != null) {
            System.out.print(temp.name + " ");

            temp = temp.prev;
        }

        System.out.println();
    }

    public int waiting() {
        return size;
    }

    public static void main(String[] args) {

        WaitingList list = new WaitingList();

        list.addNormal("Riya");
        list.addNormal("Sam");
        list.addEmergency("Tom");
        list.addNormal("Uma");

        System.out.println(list.callNext());

        list.leave("Sam");

        list.addEmergency("Vik");

        list.display();
        list.displayReverse();

        System.out.println(list.waiting());
    }
}