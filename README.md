
# ATM Management System

A console-based **ATM Management System** implemented in **C++**. This application simulates essential ATM functionalities, including account creation, secure authentication, deposits, withdrawals, transfers, and transaction history.

---

## Getting Started

To get started with the project, follow these steps:

1. Clone the repository
   - git clone https://github.com/ddivyansh04/Banking-and-ATM-interface.git
2. Navigate to the project directory
   - cd Banking-and-ATM-interface
3. Compile the source code
   - g++ -o atm atm.cpp
4. Run the application
   - ./atm

## Tech Stack
- C++
- Standard Library (for data structures, I/O, time utilities)
- Conditional Includes for Windows / Linux keypress handling

## 🚀 Features
- Account Creation: Create a new account with a unique account number, 4-digit PIN, and initial deposit.
- Secure Authentication: Enter the correct PIN to access your account, with an account lock after 3 failed attempts.
- Balance Inquiry: Check your current account balance at any time.
- Deposit: Safely add funds to your account.
- Withdraw: Withdraw funds, ensuring you have sufficient balance.
- Transfer Funds: Transfer money to another account within the system.
- Transaction History: View a log of all your deposits, withdrawals, transfers, and account actions.
- Cross-Platform: Uses conio.h on Windows or termios.h on Linux for secure PIN input.


## Contributing
If you would like to contribute to ATM Management System, follow these steps:
1. Fork the repository
2. Create a new branch
   - git checkout -b new-feature
3. Make your changes and commit them:
   - git commit -m "Add: new feature description"
4. Push to the branch:
   - git push origin new-feature
5. Create a pull request



