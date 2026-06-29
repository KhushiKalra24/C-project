//High banking system
#include <stdio.h>

struct BankAccount
{
    int accNo;
    char name[50];
    float balance;
};

void createAccount(struct BankAccount *acc);
void deposit(struct BankAccount *acc);
void withdraw(struct BankAccount *acc);
void checkBalance(struct BankAccount acc);
void saveToFile(struct BankAccount acc);

int main()
{
    struct BankAccount account;
    int choice;

    createAccount(&account);

    do
    {
        printf("\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Balance Enquiry\n");
        printf("4. Save & Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                deposit(&account);
                break;

            case 2:
                withdraw(&account);
                break;

            case 3:
                checkBalance(account);
                break;

            case 4:
                saveToFile(account);
                printf("\nAccount details saved successfully.\n");
                printf("Thank you for using our Banking System!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 4);

    return 0;
}

void createAccount(struct BankAccount *acc)
{
    printf("Enter Account Number: ");
    scanf("%d", &acc->accNo);

    printf("Enter Account Holder Name: ");
    scanf("%s", acc->name);

    printf("Enter Initial Balance: ");
    scanf("%f", &acc->balance);
}

void deposit(struct BankAccount *acc)
{
    float amount;

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    if(amount > 0)
    {
        acc->balance += amount;
        printf("Deposit Successful!\n");
    }
    else
    {
        printf("Invalid Amount!\n");
    }
}

void withdraw(struct BankAccount *acc)
{
    float amount;

    printf("Enter Withdrawal Amount: ");
    scanf("%f", &amount);

    if(amount <= 0)
    {
        printf("Invalid Amount!\n");
    }
    else if(amount > acc->balance)
    {
        printf("Insufficient Balance!\n");
    }
    else
    {
        acc->balance -= amount;
        printf("Withdrawal Successful!\n");
    }
}

void checkBalance(struct BankAccount acc)
{
    printf("\n----- Account Details -----\n");
    printf("Account Number : %d\n", acc.accNo);
    printf("Account Holder : %s\n", acc.name);
    printf("Current Balance : %.2f\n", acc.balance);
}

void saveToFile(struct BankAccount acc)
{
    FILE *fp;

    fp = fopen("bank.txt", "w");

    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "Account Number : %d\n", acc.accNo);
    fprintf(fp, "Account Holder : %s\n", acc.name);
    fprintf(fp, "Balance : %.2f\n", acc.balance);

    fclose(fp);
}