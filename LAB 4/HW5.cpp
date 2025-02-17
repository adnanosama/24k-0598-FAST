#include <iostream>
using namespace std;


struct MenuItem {
    string name;
    string type; 
    double price;
};


class CoffeeShop {
private:
    string name;
    MenuItem* menu;
    int menuSize;
    string* orders; 
    int orderCount;
    int orderCapacity;

public:
    CoffeeShop(string shopName, MenuItem menuItems[], int size) {
        name = shopName;
        menu = menuItems;
        menuSize = size;
        orderCount = 0;
        orderCapacity = 10; 
        orders = new string[orderCapacity];
    }

 
    ~CoffeeShop() {
        delete[] orders;
    }


    void resizeOrders() {
        orderCapacity *= 2;
        string* newOrders = new string[orderCapacity];
        for (int i = 0; i < orderCount; i++) {
            newOrders[i] = orders[i];
        }
        delete[] orders;
        orders = newOrders;
    }

    
    string addOrder(string itemName) {
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].name == itemName) {
                if (orderCount == orderCapacity) {
                    resizeOrders();
                }
                orders[orderCount++] = itemName;
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable";
    }


    string fulfillOrder() {
        if (orderCount > 0) {
            string item = orders[0];
            for (int i = 0; i < orderCount - 1; i++) {
                orders[i] = orders[i + 1];
            }
            orderCount--;
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }


    void listOrders() {
        if (orderCount == 0) {
            cout << "No orders placed." << endl;
        } else {
            for (int i = 0; i < orderCount; i++) {
                cout << orders[i] << endl;
            }
        }
    }

    double dueAmount() {
        double total = 0.0;
        for (int i = 0; i < orderCount; i++) {
            for (int j = 0; j < menuSize; j++) {
                if (menu[j].name == orders[i]) {
                    total += menu[j].price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menuSize == 0) return "No items available";
        MenuItem cheapest = menu[0];
        for (int i = 1; i < menuSize; i++) {
            if (menu[i].price < cheapest.price) {
                cheapest = menu[i];
            }
        }
        return cheapest.name;
    }

    string foodsonly(){
        cout << "Foods only items: " << endl;
        string foods="";
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "food") {
                foods+=menu[i].name+"\n";
            }
        }
        return foods;
    }
    

    string drinksonly() {
        cout << "Drinks only items: " << endl;
        string drinks = "";
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].type == "drink") {
                drinks += menu[i].name + "\n";
            }
        }
        return drinks;
    }
};


int main() {
    MenuItem menu[] = {
        {"Espresso", "drink", 2.5},
        {"Cappuccino", "drink", 3.0},
        {"Latte", "drink", 3.5},
        {"Sandwich", "food", 5.0},
        {"Muffin", "food", 2.0}
    };

    CoffeeShop shop("Java Cafe", menu, 5);
    
    cout << shop.addOrder("Espresso") << endl;
    cout << shop.addOrder("Muffin") << endl;
    cout << shop.addOrder("Burger") << endl; 
    cout << shop.drinksonly() << endl;
    cout << shop.foodsonly() << endl;
    cout << "Total due: $" << shop.dueAmount() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl; 
    cout << "Cheapest item: " << shop.cheapestItem() << endl;
    
    return 0;
}
