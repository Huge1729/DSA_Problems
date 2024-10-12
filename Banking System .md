# ER MODEL - SYSTEM DESIGN 
## BANKING SYSTEM

### Entities and Attributes:

#### Bank
- **BankID** (Primary Key)
- **Name** 
- **Code**
- **Address**

#### Branch
- **BranchID** (Primary Key)
- **Name**
- **Address**
- **BankID** (Foreign Key)

#### Person
- **PersonID** (Primary Key)
- **Name**
- **Address**
- **Phone**

#### Customer (Inherits from Person)
- **CustomerID** (Primary Key)
- **PersonID** (Foreign Key)

#### Account
- **AccountID** (Primary Key)
- **Balance**
- **CustomerID** (Foreign Key)
- **BranchID** (Foreign Key)

#### SavingsAccount (Inherits from Account)
- **InterestRate**

#### CurrentAccount (Inherits from Account)
- **OverdraftLimit**

#### Loan
- **LoanID** (Primary Key)
- **Amount**
- **CustomerID** (Foreign Key)
- **BranchID** (Foreign Key)

#### HomeLoan (Inherits from Loan)
- **InterestRate**

#### PersonalLoan (Inherits from Loan)
- **RepaymentPeriod**

---

### Relationships:
- **Bank - Branch:** A bank has multiple branches (One-to-Many).
  - `BankID` from **Bank** connects with `BankID` in **Branch**.
  
- **Person - Customer:** A person can be a customer (One-to-One).
  - `PersonID` from **Person** connects with `PersonID` in **Customer**.
  
- **Customer - Account:** A customer can have multiple accounts (One-to-Many).
  - `CustomerID` from **Customer** connects with `CustomerID` in **Account**.
  
- **Customer - Loan:** A customer can avail multiple loans (One-to-Many).
  - `CustomerID` from **Customer** connects with `CustomerID` in **Loan**.
  
- **Branch - Account:** A branch has multiple accounts (One-to-Many).
  - `BranchID` from **Branch** connects with `BranchID` in **Account**.
  
- **Branch - Loan:** A branch processes multiple loans (One-to-Many).
  - `BranchID` from **Branch** connects with `BranchID` in **Loan**.

---

### ER Diagram Design:
- **Bank** entity is connected to the **Branch** entity in a 1-to-many relationship.
- **Branch** is connected to both **Account** and **Loan** entities in a 1-to-many relationship.
- **Person** entity connects with **Customer** in a 1-to-1 relationship.
- **Customer** connects with **Account** and **Loan** in 1-to-many relationships.
- **Account** has two subtypes: **SavingsAccount** and **CurrentAccount** (ISA relationship, generalization-specialization).
- **Loan** has two subtypes: **HomeLoan** and **PersonalLoan** (ISA relationship).

# OOP-Based Banking System

This C++ program demonstrates the principles of Object-Oriented Programming (OOP) such as **Encapsulation**, **Abstraction**, **Inheritance**, and **Polymorphism** through a simple banking system.

## Code

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ENCAPSULATION and ABSTRACTION in Person class
class Person {
private:
    string name;
    string address;
    string phone;
public:
    Person(string name, string address, string phone)
        : name(name), address(address), phone(phone) {}

    // Getters and Setters (Encapsulation)
    string getName() { return name; }
    string getAddress() { return address; }
    string getPhone() { return phone; }

    void setName(string n) { name = n; }
    void setAddress(string a) { address = a; }
    void setPhone(string p) { phone = p; }

    // Common method for displaying person details
    virtual void displayPersonDetails() const {
        cout << "Name: " << name << ", Address: " << address << ", Phone: " << phone << endl;
    }
};

// Bank class to hold bank information
class Bank {
private:
    string name;
    string code;
    string address;

public:
    Bank(string name, string code, string address)
        : name(name), code(code), address(address) {}

    // Encapsulation through Getters
    string getBankName() { return name; }
    string getBankCode() { return code; }
    string getBankAddress() { return address; }

    void displayBankDetails() {
        cout << "Bank Name: " << name << ", Code: " << code << ", Address: " << address << endl;
    }
};

// Branch class encapsulating branch details
class Branch {
private:
    int branch_id;
    string name;
    string address;

public:
    Branch(int branch_id, string name, string address)
        : branch_id(branch_id), name(name), address(address) {}

    void displayBranchDetails() const {
        cout << "Branch ID: " << branch_id << ", Name: " << name << ", Address: " << address << endl;
    }
};

// POLYMORPHISM and INHERITANCE: Abstract Account class
class Account {
protected:
    int account_no;
    double balance;

public:
    Account(int account_no, double balance)
        : account_no(account_no), balance(balance) {}

    // Pure virtual function for polymorphism
    virtual void displayAccountDetails() const = 0;

    // Common methods for deposit and withdrawal
    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount)
            balance -= amount;
        else
            cout << "Insufficient funds!" << endl;
    }

    double getBalance() const {
        return balance;
    }

    int getAccountNo() const {
        return account_no;
    }
};

// Derived SavingsAccount class using inheritance and overriding
class SavingsAccount : public Account {
private:
    double interest_rate;

public:
    SavingsAccount(int account_no, double balance, double interest_rate)
        : Account(account_no, balance), interest_rate(interest_rate) {}

    // Overriding the display method (Polymorphism)
    void displayAccountDetails() const override {
        cout << "Savings Account No: " << account_no << ", Balance: " << balance
             << ", Interest Rate: " << interest_rate << "%" << endl;
    }
};

// Derived CurrentAccount class using inheritance and overriding
class CurrentAccount : public Account {
private:
    double overdraft_limit;
public:
    CurrentAccount(int account_no, double balance, double overdraft_limit)
        : Account(account_no, balance), overdraft_limit(overdraft_limit) {}

    // Overriding the display method (Polymorphism)
    void displayAccountDetails() const override {
        cout << "Current Account No: " << account_no << ", Balance: " << balance
             << ", Overdraft Limit: " << overdraft_limit << endl;
    }
};

// POLYMORPHISM: Abstract Loan class
class Loan {
protected:
    int loan_id;
    double amount;
public:
    Loan(int loan_id, double amount)
        : loan_id(loan_id), amount(amount) {}

    // Pure virtual function for Polymorphism
    virtual void displayLoanDetails() const = 0;

    double getLoanAmount() const {
        return amount;
    }
    
    int getLoanID() const {
        return loan_id;
    }
};

// Derived HomeLoan class
class HomeLoan : public Loan {
private:
    double interest_rate;

public:
    HomeLoan(int loan_id, double amount, double interest_rate)
        : Loan(loan_id, amount), interest_rate(interest_rate) {}

    void displayLoanDetails() const override {
        cout << "Home Loan ID: " << loan_id << ", Amount: " << amount
             << ", Interest Rate: " << interest_rate << "%" << endl;
    }
};

// Derived PersonalLoan class
class PersonalLoan : public Loan {
private:
    int repayment_period;

public:
    PersonalLoan(int loan_id, double amount, int repayment_period)
        : Loan(loan_id, amount), repayment_period(repayment_period) {}

    void displayLoanDetails() const override {
        cout << "Personal Loan ID: " << loan_id << ", Amount: " << amount
             << ", Repayment Period: " << repayment_period << " months" << endl;
    }
};

// INHERITANCE: Customer class derived from Person
class Customer : public Person {
private:
    int cust_id;
    vector<Account*> accounts;
    vector<Loan*> loans;

public:
    Customer(int cust_id, string name, string address, string phone)
        : Person(name, address, phone), cust_id(cust_id) {}

    // Method to add accounts
    void addAccount(Account* account) {
        accounts.push_back(account);
    }

    // Method to avail loans
    void availLoan(Loan* loan) {
        loans.push_back(loan);
    }

    // Display customer details with all accounts and loans
    void displayCustomerDetails() const {
        displayPersonDetails();
        cout << "Customer ID: " << cust_id << endl;

        cout << "Accounts: " << endl;
        for (auto account : accounts) {
            account->displayAccountDetails();
        }

        cout << "Loans: " << endl;
        for (auto loan : loans) {
            loan->displayLoanDetails();
        }
    }
};

// Main function to demonstrate the OOP-based banking system
int main() {
    // Create a bank
    Bank bank("State Bank", "SBI001", "Main Street, Kanpur");
    bank.displayBankDetails();

    // Create a branch
    Branch branch(101, "Kanpur Branch", "Mall Road, Kanpur");
    branch.displayBranchDetails();

    // Create a customer
    Customer customer(1, "Vishal Pal", "Civil Lines, Kanpur", "9876543210");

    // Create accounts and loans
    SavingsAccount savings(1001, 50000, 3.5);
    CurrentAccount current(1002, 150000, 50000);

    HomeLoan homeLoan(5001, 500000, 7.0);
    PersonalLoan personalLoan(5002, 200000, 36);

    // Add accounts and loans to the customer
    customer.addAccount(&savings);
    customer.addAccount(&current);
    customer.availLoan(&homeLoan);
    customer.availLoan(&personalLoan);

    // Display customer details
    customer.displayCustomerDetails();

    return 0;
}

