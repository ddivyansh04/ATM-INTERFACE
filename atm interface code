#include <bits/stdc++.h>
#include <ctime> // For timestamps
#ifdef _WIN32
#include <conio.h> // For getch() on Windows
#else
#include <termios.h>
#include <unistd.h>
char getch() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    char ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

using namespace std;

struct Account {
    string accountNumber;
    string pin;
    double balance;
    int failedAttempts;
    bool isLocked;
    vector<string> transactionHistory;

    Account() : accountNumber(""), pin(""), balance(0.0), failedAttempts(0), isLocked(false) {}
    Account(string accNum, string p, double bal)
        : accountNumber(accNum), pin(p), balance(bal), failedAttempts(0), isLocked(false) {}
};

unordered_map<string, Account> accounts;

string currentTimestamp() {
    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt) - 1] = '\0'; // Remove newline
    return string(dt);
}

string maskPIN() {
    string pin = "";
    char ch;
    while ((ch = getch()) != '\n' && ch != '\r') {  // Handle both '\n' (Linux) and '\r' (Windows)
        if (ch == '\b' || ch == 127) {  // Handle backspace (127 for Linux)
            if (!pin.empty()) {
                pin.pop_back();
                cout << "\b \b";
            }
        } else if (isdigit(ch) && pin.size() < 4) {
            pin += ch;
            cout << '*';
        }
    }
    cout << endl;
    return pin;
}

void createAccount() {
    string accNum, pin;
    double initialDeposit;
    cout << "Enter new account number: ";
    cin >> accNum;
    if (accounts.find(accNum) != accounts.end()) {
        cout << "Account already exists!\n";
        return;
    }
    cout << "Set a 4-digit PIN: ";
    pin = maskPIN();
    cout << "Initial deposit amount: ";
    cin >> initialDeposit;

    accounts[accNum] = Account(accNum, pin, initialDeposit);
    accounts[accNum].transactionHistory.push_back("[" + currentTimestamp() + "] Account created with initial deposit: $" + to_string(initialDeposit));
    cout << "Account created successfully!\n";
}

bool authenticate(string accNum) {
    if (accounts.find(accNum) == accounts.end()) return false;

    if (accounts[accNum].isLocked) {
        cout << "Account is locked due to multiple failed attempts.\n";
        return false;
    }

    cout << "Enter PIN: ";
    string pin = maskPIN();

    if (accounts[accNum].pin == pin) {
        accounts[accNum].failedAttempts = 0; // Reset on success
        return true;
    } else {
        accounts[accNum].failedAttempts++;
        cout << "Incorrect PIN!\n";
        if (accounts[accNum].failedAttempts >= 3) {
            accounts[accNum].isLocked = true;
            cout << "Account locked due to 3 failed attempts.\n";
        }
        return false;
    }
}

void checkBalance(Account &acc) {
    cout << "Current Balance: $" << acc.balance << "\n";
}

void deposit(Account &acc) {
    double amount;
    cout << "Enter deposit amount: ";
    cin >> amount;
    acc.balance += amount;
    acc.transactionHistory.push_back("[" + currentTimestamp() + "] Deposited: $" + to_string(amount));
    cout << "Deposit successful!\n";
}

void withdraw(Account &acc) {
    double amount;
    cout << "Enter withdrawal amount: ";
    cin >> amount;
    if (amount > acc.balance) {
        cout << "Insufficient balance!\n";
        return;
    }
    acc.balance -= amount;
    acc.transactionHistory.push_back("[" + currentTimestamp() + "] Withdrew: $" + to_string(amount));
    cout << "Withdrawal successful!\n";
}

void transferFunds(Account &acc) {
    string recipientAcc;
    double amount;
    cout << "Enter recipient account number: ";
    cin >> recipientAcc;

    if (accounts.find(recipientAcc) == accounts.end()) {
        cout << "Recipient account does not exist!\n";
        return;
    }
    cout << "Enter amount to transfer: ";
    cin >> amount;
    if (amount > acc.balance) {
        cout << "Insufficient balance!\n";
        return;
    }
    acc.balance -= amount;
    accounts[recipientAcc].balance += amount;

    acc.transactionHistory.push_back("[" + currentTimestamp() + "] Transferred $" + to_string(amount) + " to Account " + recipientAcc);
    accounts[recipientAcc].transactionHistory.push_back("[" + currentTimestamp() + "] Received $" + to_string(amount) + " from Account " + acc.accountNumber);

    cout << "Transfer successful!\n";
}

void viewTransactionHistory(Account &acc) {
    cout << "Transaction History:\n";
    for (const auto &entry : acc.transactionHistory) {
        cout << "- " << entry << "\n";
    }
}

void atmMenu(Account &acc) {
    int choice;
    do {
        cout << "\n--- ATM Menu ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer Funds\n";
        cout << "5. View Transaction History\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: checkBalance(acc); break;
            case 2: deposit(acc); break;
            case 3: withdraw(acc); break;
            case 4: transferFunds(acc); break;
            case 5: viewTransactionHistory(acc); break;
            case 6: cout << "Thank you for using the ATM.\n"; break;
            default: cout << "Invalid option, try again.\n";
        }
    } while (choice != 6);
}

int main() {
    int mainChoice;
    do {
        cout << "\n--- Welcome to the ATM System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                createAccount();
                break;
            case 2: {
                string accNum;
                cout << "Enter account number: ";
                cin >> accNum;
                if (authenticate(accNum)) {
                    atmMenu(accounts[accNum]);
                } else {
                    cout << "Authentication failed!\n";
                }
                break;
            }
            case 3:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid option, try again.\n";
        }
    } while (mainChoice != 3);

    return 0;
}
