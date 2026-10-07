import java.util.ArrayList;

class CartItem {

    String name;
    int price;
    int qty;

    // Constructor
    CartItem(String name, int price, int qty) {
        this.name = name;
        this.price = price;
        this.qty = qty;
    }
}

class ShoppingCart {

    ArrayList<CartItem> cart = new ArrayList<>();


    // -----------------------------------
    // ADD PRODUCT
    // -----------------------------------
    void add(String name, int price, int qty) {

        // Check whether product already exists
        for (int i = 0; i < cart.size(); i++) {

            CartItem item = cart.get(i);

            if (item.name.equalsIgnoreCase(name)) {

                // Product already exists
                item.qty = item.qty + qty;

                System.out.println(
                    name + " already in cart: quantity becomes "
                    + item.qty
                );

                return;
            }
        }

        // Product does not exist
        CartItem item = new CartItem(name, price, qty);

        cart.add(item);

        System.out.println(name + " added to cart");
    }


    // -----------------------------------
    // REMOVE PRODUCT
    // -----------------------------------
    void remove(String name) {

        for (int i = 0; i < cart.size(); i++) {

            CartItem item = cart.get(i);

            if (item.name.equalsIgnoreCase(name)) {

                cart.remove(i);

                System.out.println(name + " removed");

                return;
            }
        }

        System.out.println(name + " not found");
    }


    // -----------------------------------
    // UPDATE QUANTITY
    // -----------------------------------
    void updateQty(String name, int newQty) {

        for (int i = 0; i < cart.size(); i++) {

            CartItem item = cart.get(i);

            if (item.name.equalsIgnoreCase(name)) {

                // Quantity 0 means remove item
                if (newQty == 0) {

                    cart.remove(i);

                    System.out.println(
                        name + " removed"
                    );

                    return;
                }

                item.qty = newQty;

                System.out.println(
                    name + " quantity updated to "
                    + newQty
                );

                return;
            }
        }

        System.out.println(name + " not found");
    }


    // -----------------------------------
    // CALCULATE BILL
    // -----------------------------------
    void bill() {

        int subtotal = 0;

        // Calculate subtotal
        for (int i = 0; i < cart.size(); i++) {

            CartItem item = cart.get(i);

            subtotal = subtotal + (item.price * item.qty);
        }


        // Calculate 10% discount
        int discount = 0;

        if (subtotal >= 1000) {

            // Integer division
            discount = subtotal / 10;
        }


        // Amount after discount
        int afterDiscount = subtotal - discount;


        // Delivery charge
        int delivery = 0;

        if (afterDiscount < 500 && afterDiscount > 0) {

            delivery = 40;
        }


        // Final total
        int total = afterDiscount + delivery;


        System.out.println(
            "Bill: Subtotal " + subtotal
            + " | Discount " + discount
            + " | Delivery " + delivery
            + " | Total " + total
        );
    }


    // -----------------------------------
    // DISPLAY CART
    // -----------------------------------
    void display() {

        if (cart.size() == 0) {

            System.out.println("Cart is empty");
            return;
        }

        System.out.println("\nCart:");

        for (int i = 0; i < cart.size(); i++) {

            CartItem item = cart.get(i);

            System.out.println(
                item.name
                + " | Price: " + item.price
                + " | Quantity: " + item.qty
            );
        }
    }
}


public class OnlineShoppingCart {

    public static void main(String[] args) {

        ShoppingCart cart = new ShoppingCart();


        // Add Pen
        cart.add("Pen", 20, 5);


        // Add Notebook
        cart.add("Notebook", 60, 10);


        // Add Bag
        cart.add("Bag", 450, 1);


        // Add Pen again
        // Quantity becomes 10
        cart.add("Pen", 20, 5);


        // Display bill
        cart.bill();


        // Remove Bag
        cart.remove("Bag");


        // Display bill
        cart.bill();


        // Update Notebook quantity to 2
        cart.updateQty("Notebook", 2);


        // Display bill
        cart.bill();
    }
}