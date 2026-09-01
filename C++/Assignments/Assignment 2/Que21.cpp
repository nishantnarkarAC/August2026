#include <iostream>
#include <iomanip>

using namespace std;

class Product
{
private:
    int productId;
    string name;
    double price;
    int quantity;

public:

    // Accept product details
    void acceptDetails()
    {
        cout << "Enter Product ID: ";
        cin >> productId;

        cout << "Enter Product Name: ";
        cin >> name;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    // Display product details
    void displayDetails() const
    {
        cout << left
             << setw(10) << productId
             << setw(15) << name
             << setw(10) << fixed << setprecision(2) << price
             << setw(8) << quantity
             << setw(15) << totalValue()
             << endl;
    }

    // Calculate total value
    double totalValue() const
    {
        return price * quantity;
    }

    // Check low stock
    bool isLowStock(int threshold) const
    {
        return quantity < threshold;
    }
};

int main()
{
    // Create array of 5 Product objects
    Product products[5];

    // Accept details for all 5 products
    for(int i = 0; i < 5; i++)
    {
        cout << "\nEnter details for Product "
             << i + 1 << endl;

        products[i].acceptDetails();
    }

    // Display all products
    cout << "\n===== INVENTORY REPORT =====\n";

    cout << left
         << setw(10) << "ID"
         << setw(15) << "Name"
         << setw(10) << "Price"
         << setw(8) << "Qty"
         << setw(15) << "Total Value"
         << endl;

    for(int i = 0; i < 5; i++)
    {
        products[i].displayDetails();
    }

    // Find product with highest total value
    int highestIndex = 0;

    for(int i = 1; i < 5; i++)
    {
        if(products[i].totalValue() >
           products[highestIndex].totalValue())
        {
            highestIndex = i;
        }
    }

    cout << "\n===== HIGHEST VALUE PRODUCT =====\n";

    cout << left
         << setw(10) << "ID"
         << setw(15) << "Name"
         << setw(10) << "Price"
         << setw(8) << "Qty"
         << setw(15) << "Total Value"
         << endl;

    products[highestIndex].displayDetails();

    // Get low stock threshold
    int threshold;

    cout << "\nEnter low stock threshold: ";
    cin >> threshold;

    // Display low stock products
    cout << "\n===== LOW STOCK PRODUCTS =====\n";

    for(int i = 0; i < 5; i++)
    {
        if(products[i].isLowStock(threshold))
        {
            products[i].displayDetails();
        }
    }

    return 0;
}