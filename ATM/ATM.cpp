#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
private:
    int id;
    string password;
    double balance;

public:
    Account(int id, string password) : id(id), password(password), balance(0) {}

    bool login(int entered_id, string entered_password) {
        return (id == entered_id && password == entered_password);
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Your balance is $" << balance << "." << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Your balance is $" << balance << "." << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void requestBalance() {
        cout << "Your balance is $" << balance << "." << endl;
    }
};

class ATM {
private:
    vector<Account> accounts;

public:
    void createAccount(int id, string password) {
        accounts.push_back(Account(id, password));
        cout << "Thank You! Your account has been created!" << endl;
    }

    bool login(int id, string password) {
        for (const auto& account : accounts) {
            if (account.login(id, password)) {
                return true;
            }
        }
        return false;
    }

    Account* getAccount(int id, string password) {
        for (auto& account : accounts) {
            if (account.login(id, password)) {
                return &account;
            }
        }
        return nullptr;
    }
};

int main() {
    ATM atm;

    char choice;
    int id;
    string password;
    double amount;

    while (true) {
        cout << "Please select an option from the menu below:\n"
                "l -> Login\n"
                "c -> Create New Account\n"
                "q -> Quit\n"
                "> ";
        cin >> choice;

        switch (choice) {
            case 'l':
                cout << "Please enter your user id: ";
                cin >> id;
                cout << "Please enter your password: ";
                cin >> password;
                if (atm.login(id, password)) {
                    Account* userAccount = atm.getAccount(id, password);
                    cout << "Access Granted!" << endl;
                    while (true) {
                        cout << "d -> Deposit Money\n"
                                "w -> Withdraw Money\n"
                                "r -> Request Balance\n"
                                "q -> Quit\n"
                                "> ";
                        cin >> choice;

                        switch (choice) {
                            case 'd':
                                cout << "Amount of deposit: $";
                                cin >> amount;
                                userAccount->deposit(amount);
                                break;
                            case 'w':
                                cout << "Amount of withdrawal: $";
                                cin >> amount;
                                userAccount->withdraw(amount);
                                break;
                            case 'r':
                                userAccount->requestBalance();
                                break;
                            case 'q':
                                cout << "Thanks for stopping by!" << endl;
                                return 0;
                            default:
                                cout << "Invalid choice!" << endl;
                                break;
                        }
                    }
                } else {
                    cout << "******** LOGIN FAILED! ********" << endl;
                }
                break;
            case 'c':
                cout << "Please enter your user id: ";
                cin >> id;
                cout << "Please enter your password: ";
                cin >> password;
                atm.createAccount(id, password);
                break;
            case 'q':
                cout << "Thanks for stopping by!" << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }

    return 0;
}
