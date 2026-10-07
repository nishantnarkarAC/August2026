class BookNode {
    int id;
    String title;
    BookNode left;
    BookNode right;

    BookNode(int id, String title) {
        this.id = id;
        this.title = title;
    }
}

public class Catalogue {

    private BookNode root;

    public void insert(int id, String title) {
        root = insert(root, id, title);
    }

    private BookNode insert(BookNode node, int id, String title) {

        if (node == null) {
            return new BookNode(id, title);
        }

        if (id < node.id) {
            node.left = insert(node.left, id, title);
        } else if (id > node.id) {
            node.right = insert(node.right, id, title);
        } else {
            System.out.println("Duplicate Book ID");
        }

        return node;
    }

    public BookNode search(int id) {

        BookNode temp = root;

        while (temp != null) {

            System.out.print(temp.id + " ");

            if (id == temp.id) {
                System.out.println();
                return temp;
            }

            if (id < temp.id) {
                temp = temp.left;
            } else {
                temp = temp.right;
            }
        }

        System.out.println();
        return null;
    }

    public void inorder(BookNode n) {

        if (n == null) {
            return;
        }

        inorder(n.left);
        System.out.print(n.id + " ");
        inorder(n.right);
    }

    public void preorder(BookNode n) {

        if (n == null) {
            return;
        }

        System.out.print(n.id + " ");
        preorder(n.left);
        preorder(n.right);
    }

    public void postorder(BookNode n) {

        if (n == null) {
            return;
        }

        postorder(n.left);
        postorder(n.right);
        System.out.print(n.id + " ");
    }

    public int count(BookNode n) {

        if (n == null) {
            return 0;
        }

        return 1 + count(n.left) + count(n.right);
    }

    public int height(BookNode n) {

        if (n == null) {
            return -1;
        }

        int leftHeight = height(n.left);
        int rightHeight = height(n.right);

        return 1 + Math.max(leftHeight, rightHeight);
    }

    public int min() {

        if (root == null) {
            return -1;
        }

        BookNode temp = root;

        while (temp.left != null) {
            temp = temp.left;
        }

        return temp.id;
    }

    public int max() {

        if (root == null) {
            return -1;
        }

        BookNode temp = root;

        while (temp.right != null) {
            temp = temp.right;
        }

        return temp.id;
    }

    public BookNode getRoot() {
        return root;
    }

    public static void main(String[] args) {

        Catalogue c = new Catalogue();

        c.insert(105, "Book A");
        c.insert(62, "Book B");
        c.insert(148, "Book C");
        c.insert(40, "Book D");
        c.insert(87, "Book E");
        c.insert(120, "Book F");
        c.insert(173, "Book G");
        c.insert(95, "Book H");

        System.out.print("Inorder: ");
        c.inorder(c.getRoot());

        System.out.println();

        System.out.print("Preorder: ");
        c.preorder(c.getRoot());

        System.out.println();

        System.out.print("Postorder: ");
        c.postorder(c.getRoot());

        System.out.println();

        System.out.println("Count: " + c.count(c.getRoot()));
        System.out.println("Height: " + c.height(c.getRoot()));
        System.out.println("Min: " + c.min());
        System.out.println("Max: " + c.max());

        System.out.print("Search 95 path: ");
        c.search(95);
    }
}