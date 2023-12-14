#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100


struct Account {
    int accountNumber;
    char name[50];
    float balance;
};


struct Account accounts[MAX_ACCOUNTS];


int totalAccounts = 0;


void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Bank is full.\n");
        return;
    }

    struct Account newAccount;
    newAccount.accountNumber = totalAccounts + 1;

    printf("Enter account holder's name: ");
    scanf("%s", newAccount.name);

    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);

    accounts[totalAccounts++] = newAccount;

    printf("Account created successfully. Account number is %d.\n", newAccount.accountNumber);
}


void transferMoney(int senderAccNum, int receiverAccNum, float amount) {
    int senderIndex = senderAccNum - 1;
    int receiverIndex = receiverAccNum - 1;

    if (senderIndex < 0 || senderIndex >= totalAccounts ||
        receiverIndex < 0 || receiverIndex >= totalAccounts) {
        printf("Invalid account number(s).\n");
        return;
    }

    if (accounts[senderIndex].balance < amount) {
        printf("Insufficient balance in the sender's account.\n");
        return;
    }

    accounts[senderIndex].balance -= amount;
    accounts[receiverIndex].balance += amount;

    printf("Amount transferred successfully.\n");
}


void checkBalance(int accountNumber) {
    int index = accountNumber - 1;

    if (index < 0 || index >= totalAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Account Number: %d\n", accounts[index].accountNumber);
    printf("Account Holder's Name: %s\n", accounts[index].name);
    printf("Current Balance: %.2f\n", accounts[index].balance);
}


int login() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        printf("Login successful.\n");
        return 1; 
    } else {
        printf("Login failed. Invalid credentials.\n");
        return 0; 
    }
}

int main() {
    int choice, loggedIn = 0;

    do {
        printf("\nBank Management System\n");
        printf("1. Login\n");
        printf("2. Create Account\n");
        printf("3. Transfer Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                loggedIn = login();
                break;
            case 2:
                if (loggedIn) {
                    createAccount();
                } else {
                    printf("Please login to create an account.\n");
                }
                break;
            case 3:
                if (loggedIn) {
                    int senderAcc, receiverAcc;
                    float amount;

                    printf("Enter sender's account number: ");
                    scanf("%d", &senderAcc);

                    printf("Enter receiver's account number: ");
                    scanf("%d", &receiverAcc);

                    printf("Enter amount to transfer: ");
                    scanf("%f", &amount);

                    transferMoney(senderAcc, receiverAcc, amount);
                } else {
                    printf("Please login to transfer money.\n");
                }
                break;
            case 4:
                if (loggedIn) {
                    int accountNumber;

                    printf("Enter account number to check balance: ");
                    scanf("%d", &accountNumber);

                    checkBalance(accountNumber);
                } else {
                    printf("Please login to check balance.\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
