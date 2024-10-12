# Food Ordering Application

# Entity Model 

## 1. User
- **username** (Primary Key)  
- password  
- address  

## 2. Vendor
- **vendorName** (Primary Key)  
- vendorLocation  

## 3. Restaurant
- **restaurantName** (Primary Key)  
- **vendorName** (Foreign Key referencing `Vendor.vendorName`)

## 4. MenuItem
- **name** (Primary Key)  
- price  
- category  
- **restaurantName** (Foreign Key referencing `Restaurant.restaurantName`)

## 5. Order
- **orderID** (Primary Key)  
- **username** (Foreign Key referencing `User.username`)  
- totalPrice  

## 6. Payment
- **paymentID** (Primary Key)  
- **orderID** (Foreign Key referencing `Order.orderID`)  
- amount  
- paymentMethod  

---

## **Relationships**

- **User → Order**: One-to-Many  
  A user can place multiple orders.

- **Order → Payment**: One-to-One  
  Each order has a corresponding payment.

- **Vendor → Restaurant**: One-to-Many  
  A vendor manages multiple restaurants.

- **Restaurant → MenuItem**: One-to-Many  
  Each restaurant offers multiple menu items.


## Relationships

### User places Order
- **Description:** A user can place multiple orders, and each order is placed by one user.
- **Cardinality:** One-to-Many (1:M)
- **Attributes of Relationship:** None

### Vendor manages Restaurant
- **Description:** Each vendor manages multiple restaurants.
- **Cardinality:** One-to-Many (1:M)
- **Attributes of Relationship:** None

### Restaurant has MenuItems
- **Description:** Each restaurant has multiple menu items, but each menu item belongs to only one restaurant.
- **Cardinality:** One-to-Many (1:M)
- **Attributes of Relationship:** None

### Order contains MenuItems
- **Description:** Each order contains one or more menu items, and each menu item can be part of multiple orders (many-to-many relationship).
- **Cardinality:** Many-to-Many (M:N)
- **Attributes of Relationship:** None

### Order is processed by Payment
- **Description:** Each order is processed by one payment, and each payment is linked to one order.
- **Cardinality:** One-to-One (1:1)
- **Attributes of Relationship:** `paymentID`, `paymentMethod`, `amount`

## ER Model Breakdown

- **User:** Entity for users with attributes username, password, and address. Users place orders.
- **Vendor:** Entity for vendors with attributes vendorName and vendorLocation. Vendors manage multiple restaurants.
- **Restaurant:** Entity for restaurants with an attribute restaurantName. Restaurants have multiple menu items.
- **MenuItem:** Entity for menu items with attributes name, price, and category. Menu items belong to restaurants and are part of orders.
- **Order:** Entity for orders with attributes orderID and totalPrice. Orders contain multiple menu items and are placed by users.
- **Payment:** Entity for payments with attributes paymentID, amount, and paymentMethod. Payments are linked to orders.

## Constraints

1. **User places Order:** Each user can place many orders, but an order is placed by only one user.
2. **Vendor manages Restaurant:** Each vendor can manage multiple restaurants, but each restaurant is managed by only one vendor.
3. **Restaurant has MenuItems:** A restaurant can have multiple menu items, but a menu item is only part of one restaurant.
4. **Order contains MenuItems:** An order can contain multiple menu items, and a menu item can be part of multiple orders (many-to-many relationship).
5. **Order is processed by Payment:** An order is processed by one payment, and each payment is associated with one order.

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Forward Declarations
class Vendor;
class MenuItem;
class Order;
class Payment;
class Restaurant;

// User Class
class User {
private:
    string username, password, address;
public:
    User(string u, string p, string a) : username(u), password(p), address(a) {}

    string getUsername() { return username; }
    string getAddress() { return address; }

    bool login(string inputUsername, string inputPassword) {
        return (inputUsername == username && inputPassword == password);
    }
};

// Vendor Class
class Vendor {
private:
    string vendorName, vendorLocation;
    vector<Restaurant*> restaurants;
public:
    Vendor(string name, string location) : vendorName(name), vendorLocation(location) {}

    string getVendorName() { return vendorName; }
    string getVendorLocation() { return vendorLocation; }

    void addRestaurant(Restaurant* restaurant) {
        restaurants.push_back(restaurant);
    }

    vector<Restaurant*> getRestaurants() { return restaurants; }
};

// MenuItem Class
class MenuItem {
private:
    string name;
    float price;
    string category;
public:
    MenuItem(string n, float p, string c) : name(n), price(p), category(c) {}

    string getName() { return name; }
    float getPrice() { return price; }
    string getCategory() { return category; }

    void displayItem() {
        cout << "Name: " << name << ", Price: $" << price << ", Category: " << category << endl;
    }
};

// Restaurant Class
class Restaurant {
private:
    string restaurantName;
    vector<MenuItem*> menu;
public:
    Restaurant(string name) : restaurantName(name) {}

    string getRestaurantName() { return restaurantName; }

    void addMenuItem(MenuItem* item) {
        menu.push_back(item);
    }

    vector<MenuItem*> getMenu() { return menu; }

    void displayMenu() {
        cout << "Menu for " << restaurantName << ":\n";
        for (auto item : menu) {
            item->displayItem();
        }
    }

    vector<MenuItem*> filterByCategory(string category) {
        vector<MenuItem*> filteredMenu;
        for (auto item : menu) {
            if (item->getCategory() == category)
                filteredMenu.push_back(item);
        }
        return filteredMenu;
    }

    void sortMenuByPrice() {
        sort(menu.begin(), menu.end(), [](MenuItem* a, MenuItem* b) {
            return a->getPrice() < b->getPrice();
        });
    }
};

// Order Class
class Order {
private:
    vector<MenuItem*> orderItems;
    float totalPrice;
public:
    Order() : totalPrice(0.0f) {}

    void addItem(MenuItem* item) {
        orderItems.push_back(item);
        totalPrice += item->getPrice();
    }

    float getTotalPrice() { return totalPrice; }

    void displayOrder() {
        cout << "Your order:\n";
        for (auto item : orderItems) {
            cout << "- " << item->getName() << " - $" << item->getPrice() << endl;
        }
        cout << "Total Price: $" << totalPrice << endl;
    }
};

// Payment Class
class Payment {
public:
    bool processPayment(float amount, string paymentMethod) {
        cout << "Processing payment of $" << amount << " using " << paymentMethod << "...\n";
        // For now, assume all payments are successful
        return true;
    }
};

// System for handling users, vendors, and orders
class FoodOrderingSystem {
private:
    vector<User*> users;
    vector<Vendor*> vendors;
    User* loggedInUser;
public:
    FoodOrderingSystem() : loggedInUser(nullptr) {}

    void signup(string username, string password, string address) {
        users.push_back(new User(username, password, address));
        cout << "User " << username << " signed up successfully!\n";
    }

    bool login(string username, string password) {
        for (auto user : users) {
            if (user->login(username, password)) {
                loggedInUser = user;
                cout << "User " << username << " logged in successfully!\n";
                return true;
            }
        }
        cout << "Invalid login credentials.\n";
        return false;
    }

    void addVendor(Vendor* vendor) {
        vendors.push_back(vendor);
    }

    vector<Vendor*> getVendors() { return vendors; }

    void browseRestaurants() {
        if (!loggedInUser) {
            cout << "Please log in to browse restaurants.\n";
            return;
        }
        cout << "Browsing restaurants:\n";
        for (auto vendor : vendors) {
            cout << "Vendor: " << vendor->getVendorName() << ", Location: " << vendor->getVendorLocation() << endl;
            for (auto restaurant : vendor->getRestaurants()) {
                cout << "  - Restaurant: " << restaurant->getRestaurantName() << endl;
            }
        }
    }

    void placeOrder(Restaurant* restaurant) {
        if (!loggedInUser) {
            cout << "Please log in to place an order.\n";
            return;
        }

        Order order;
        // restaurant->displayMenu();
        int itemNumber;
        cout << "Enter the item number to add to the order (0 to complete): ";
        while (cin >> itemNumber && itemNumber != 0) {
            vector<MenuItem*> menu = restaurant->getMenu();
            if (itemNumber > 0 && itemNumber <= menu.size()) {
                order.addItem(menu[itemNumber - 1]);
            }
            cout << "Enter the next item number (0 to complete): ";
        }

        order.displayOrder();
        Payment payment;
        string paymentMethod;
        cout << "Enter payment method (Card/Cash/UPI): ";
        cin >> paymentMethod;

        if (payment.processPayment(order.getTotalPrice(), paymentMethod)) {
            cout << "Payment successful! Order placed.\n";
        }
    }

    void filterAndSortMenu(Restaurant* restaurant) {
        cout << "1. Filter by category\n2. Sort by price\nChoose an option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string category;
            cout << "Enter category to filter: ";
            cin >> category;
            vector<MenuItem*> filteredMenu = restaurant->filterByCategory(category);
            cout << "Filtered Menu:\n";
            for (auto item : filteredMenu) {
                item->displayItem();
            }
        } else if (choice == 2) {
            restaurant->sortMenuByPrice();
            restaurant->displayMenu();
        }
    }
};

int main() {
    FoodOrderingSystem system;

    // Sample Data
    Vendor* vendor1 = new Vendor("Fast Food Co.", "City Center");
    Restaurant* restaurant1 = new Restaurant("Burger Joint");
    restaurant1->addMenuItem(new MenuItem("Cheeseburger", 5.99, "Main"));
    restaurant1->addMenuItem(new MenuItem("French Fries", 2.49, "Side"));
    vendor1->addRestaurant(restaurant1);
    system.addVendor(vendor1);

    // User Signup and Login
    system.signup("john_doe", "password123", "123 Main St");
    system.login("john_doe", "password123");

    // Browse Restaurants 
    system.browseRestaurants();

    // Filter and Sort Menu Example
    system.filterAndSortMenu(restaurant1);

    // and Place Order
    system.placeOrder(restaurant1);

    return 0;
}
