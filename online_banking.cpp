#include <iostream>
#include <vector>
#include <cstdlib> // For system("cls") or system("clear")
using namespace std;

class BankAccount {
private:
    string name;
    int accountNum;
    double balance;
public:
    BankAccount(string n, int ac, double bal) {
        name = n;
        accountNum = ac;
        balance = bal;
    }
    string getName() {
        return name;
    }
    int getAccountNum() {
        return accountNum;
    }
    double getBalance() {
        return balance;
    }
    void deposit(double amount) {
        balance += amount;
    }    
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "\t\tWithdraw Successful..." << endl;
        } else {
            cout << "\t\tInsufficient Balance..." << endl;
        }
    }    
};

class BankManagement {
private:
    vector<BankAccount> accounts;
public:
    void AddAccount(string name, int accountNum, double balance) {
        accounts.push_back(BankAccount(name, accountNum, balance));
    }
    void showAllAccounts() {
        cout << "\t\tAll Account Holders:" << endl;
        for (int i = 0; i < accounts.size(); i++) {
            cout << "Name: " << accounts[i].getName()
                 << " | Account Number: " << accounts[i].getAccountNum()
                 << " | Balance: " << accounts[i].getBalance() << endl;
        }
    }
    void searchAccount(int account) {
        cout << "\t\tAccount Holder:" << endl;
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNum() == account) {
                cout << "Name: " << accounts[i].getName()
                     << " | Account Number: " << accounts[i].getAccountNum()
                     << " | Balance: " << accounts[i].getBalance() << endl;
                return;
            }
        }
        cout << "\t\tAccount Not Found." << endl;
    }
    BankAccount* findAccount(int accountNum) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNum() == accountNum) {
                return &accounts[i];
            }
        }
        return nullptr; // Return nullptr if account is not found
    }
};

int main() {
    BankManagement bank;
    int choice;
    char op;
    do {
        // For Windows use "cls"; for Unix-based systems use "clear"
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        cout << "\t\t:: Welcome to Our All People Bank ::" << endl;
        cout << "\t\t\tMain Menu" << endl;
        cout << "\t\t1. Create New Account" << endl;
        cout << "\t\t2. Show All Accounts" << endl;
        cout << "\t\t3. Search Account" << endl;
        cout << "\t\t4. Deposit Money" << endl;
        cout << "\t\t5. Withdraw Money" << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "\t\t-------------------------------" << endl;
        cout << "\t\tEnter Your Choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                string name;
                int accountNum;
                double balance;
                cout << "\t\tEnter Name: ";
                cin >> name;
                cout << "\t\tEnter Account Number: ";
                cin >> accountNum;
                cout << "\t\tEnter Initial Balance: ";
                cin >> balance;
                bank.AddAccount(name, accountNum, balance);
                cout << "\t\tAccount Created Successfully." << endl;
                break;
            }
            case 2: {
                bank.showAllAccounts();
                break;
            }
            case 3: {
                int accountNum;
                cout << "\t\tEnter Account Number: ";
                cin >> accountNum;
                bank.searchAccount(accountNum);
                break;
            }
            case 4: {
                int accountNum;
                double amount;
                cout << "\t\tEnter Account Number to Deposit Money: ";
                cin >> accountNum;
                BankAccount* account = bank.findAccount(accountNum);
                if (account != nullptr) {
                    cout << "\t\tEnter Amount to Deposit: ";
                    cin >> amount;
                    account->deposit(amount);
                    cout << "\t\t" << amount << " deposited successfully." << endl;
                } else {
                    cout << "\t\tAccount Not Found." << endl;
                }
                break;
            }
            case 5: {
                int accountNum;
                double amount;
                cout << "\t\tEnter Account Number to Withdraw Money: ";
                cin >> accountNum;
                BankAccount* account = bank.findAccount(accountNum);
                if (account != nullptr) {
                    cout << "\t\tEnter Amount to Withdraw: ";
                    cin >> amount;
                    account->withdraw(amount);
                } else {
                    cout << "\t\tAccount Not Found." << endl;
                }
                break;
            }
            case 6: {
                cout << "\t\tExiting Program." << endl;
                return 0;
            }
            default: {
                cout << "\t\tInvalid Choice!" << endl;
            }
        }
        cout << "\t\tDo You Want to Continue? [Y/N]: ";
        cin >> op;
    } while(op == 'y' || op == 'Y');

    return 0;
}
