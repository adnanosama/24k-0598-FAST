#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct User {
    string user_id, first_name, last_name, address, email;
};

struct Product {
    string product_id, product_name, description;
    int price;
};

struct Order {
    string order_id, user_id, product_id;
    int total_paid;
};

vector<User> loadUsers(const string& filename) {
    vector<User> users;
    ifstream inFile(filename);
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        User user;
        getline(ss, user.user_id, ',');
        getline(ss, user.first_name, ',');
        getline(ss, user.last_name, ',');
        getline(ss, user.address, ',');
        getline(ss, user.email, ',');
        users.push_back(user);
    }
    return users;
}

vector<Product> loadProducts(const string& filename) {
    vector<Product> products;
    ifstream inFile(filename);
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        Product product;
        string priceStr;
        getline(ss, product.product_id, ',');
        getline(ss, product.product_name, ',');
        getline(ss, product.description, ',');
        getline(ss, priceStr, ',');
        product.price = stoi(priceStr);
        products.push_back(product);
    }
    return products;
}

vector<Order> loadOrders(const string& filename) {
    vector<Order> orders;
    ifstream inFile(filename);
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        Order order;
        string totalStr;
        getline(ss, order.order_id, ',');
        getline(ss, order.user_id, ',');
        getline(ss, order.product_id, ',');
        getline(ss, totalStr, ',');
        order.total_paid = stoi(totalStr);
        orders.push_back(order);
    }
    return orders;
}

void findProductsForUser(const string& username) {
    vector<User> users = loadUsers("users.txt");
    vector<Product> products = loadProducts("products.txt");
    vector<Order> orders = loadOrders("orders.txt");

    string userId;
    for (auto& user : users) {
        if (user.first_name == username) {
            userId = user.user_id;
            break;
        }
    }

    if (userId.empty()) {
        cout << "User not found.\n";
        return;
    }

    vector<string> productIds;
    for (auto& order : orders) {
        if (order.user_id == userId) {
            productIds.push_back(order.product_id);
        }
    }

    cout << "Products ordered by " << username << ":\n";
    for (auto& product : products) {
        for (auto& pid : productIds) {
            if (product.product_id == pid) {
                cout << "- " << product.product_name << endl;
            }
        }
    }
}

int main() {
    findProductsForUser("Linus");
    return 0;
}
