#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variables
typedef struct Transaction{
    char transfer_to[50];
    char transfer_from[50];
    float transfer_amount;
} Transaction;

typedef struct Client{
    char name[50];
    int acc_no;
    float balance;
    Transaction transaction_list[100];
    int transaction_count;

} Client;



// function prototypes for banking operations
void menu();
void deposit_money(Client *client_ptr, float amount);
void withdraw_money(Client *client_ptr, float *amount);
void transfer_money(Client *client_ptr, float *amount, char *transfer_account);
void account_details(Client *client_ptr);
void transaction_details(Client *client_ptr);

// client initalization
Client client;

int main(){
    int choice;
    int running_flag = 1;
    printf("Enter your name: \n");
    scanf("%s", client.name);
    printf("Enter your account number: \n");
    scanf("%d", &client.acc_no);

    while (running_flag){
        menu();
        printf("Enter your choice of options: \n");
        scanf("%d", &choice);
        float deposit_amount;
        float withdrawal_amount;
        float transfer_amount;
        char transfer_account[50];

    switch(choice){
        case 1:
            printf("You have selected Deposit Money option.\n");
            printf("Enter the amount to deposit: \n");
            scanf("%f", &deposit_amount);
            if (deposit_amount <= 0){
                printf("Invalid amount. Please enter a positive number.\n");
                while (deposit_amount <= 0){
                    printf("Enter a valid amount to deposit: \n");
                    scanf("%f", &deposit_amount);
                }
            }
            deposit_money(&client, deposit_amount);
            printf("You have successfully deposited %.2f into your account.\n", deposit_amount);
            printf("Your new balance is: %.2f\n", client.balance);
            break;
        case 2:
            printf("You have selected to withdraw money.\n");
            printf("Please enter the amount to withdraw: \n");
            
            scanf("%f", &withdrawal_amount);
            if (withdrawal_amount <= 0){
                printf("Invalid amount. Please enter a positive number.\n");
                while (withdrawal_amount <= 0){
                    printf("Enter a valid amount to withdraw: \n");
                    scanf("%f", &withdrawal_amount);
                }
            }
            
            withdraw_money(&client, &withdrawal_amount);
            printf("You have successfully withdrawn %.2f from your account.\n", withdrawal_amount);
            printf("Your new balance is: %.2f\n", client.balance);
            break;
        case 3:
            printf("You have chosen to transfer money.\n");
            printf("Please enter the amount that you wish to transfer: \n");
            
            printf("Please enter the name of the person to transfer to: \n");
            scanf("%s", transfer_account);
            scanf("%f", &transfer_amount);
            if (transfer_amount <= 0){
                printf("Invalid amount. Please enter a positive number.\n");
                while (transfer_amount <= 0){
                    printf("enter a valid amount\n");
                    scanf("%f", &transfer_amount);
                }
            }
            transfer_money(&client, &transfer_amount, transfer_account);
            printf("You have successfully transferred %.2f from your account.\n", transfer_amount);
            printf("Your new balance is: %.2f\n", client.balance);
            break;
        case 4:
            printf("You have selected to display your account balance. \n");
            account_details(&client);
            printf("Your account details are displayed above.\n");
            printf("Ayo Bomboclaat Bank reeeeal glad to hav ya as a cuhstomah!\n");
            break;
        case 5:
            printf("You have selected to display the transaction details.\n");
            transaction_details(&client);
            printf("Your transaction details are displayed above.\n");
            printf("Thank you for choosing the Bomboclaat Bank. JAH!\n");
            break;
        case 6:
            printf("Exiting the program...\n");
            printf("Thank you for using the Bomboclaat Bank. Swankipakitoke!\n");
            running_flag = 0;
            break;
        default:
            printf("Invalid choice. Please select a valid option from the menu.\n");
            break;
    }
}



    return 0;
}

void menu(){
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Transfer Money\n");
    printf("4. Account details\n");
    printf("5. Transaction details\n");
    printf("6. Exit\n");
}

void deposit_money(Client *client_ptr, float amount){
    (*client_ptr).balance += amount;
}

void withdraw_money(Client *client_ptr, float *amount){
    if ((*client_ptr).balance < *amount){
        printf("Insufficient funds. Enter a valid amount to withdraw: \n");
        scanf("%f", amount);
        while (client_ptr->balance < *amount){
            printf("Insufficient funds. Enter a valid amount to withdraw: \n");
            scanf("%f", amount);
        }
        (*client_ptr).balance -= *amount;
    } else {
        (*client_ptr).balance -= *amount;
    }
}

void transfer_money(Client *client_ptr, float *amount, char *transfer_account){
    if ((*client_ptr).balance < *amount){
        printf("Please enter a valid amount to transfer: \n");
        scanf("%f", amount);
        while ((*client_ptr).balance < *amount){
            printf("Insufficient funds in your account. Enter a valid amount: \n");
            scanf("%f", amount);
        }
        (*client_ptr).balance -= *amount;
        Transaction current_transaction;
        strcpy(current_transaction.transfer_to, transfer_account);
        strcpy(current_transaction.transfer_from, (*client_ptr).name);
        current_transaction.transfer_amount = *amount;
        (*client_ptr).transaction_list[(*client_ptr).transaction_count] = current_transaction;
        (*client_ptr).transaction_count++;
    } else {
        (*client_ptr).balance -= *amount;
        Transaction current_transaction;
        strcpy(current_transaction.transfer_to, transfer_account);
        strcpy(current_transaction.transfer_from, (*client_ptr).name);
        current_transaction.transfer_amount = *amount;
        (*client_ptr).transaction_list[(*client_ptr).transaction_count] = current_transaction;
        (*client_ptr).transaction_count++;
    }
}

void account_details(Client *client_ptr){
    printf("Account holder name: %s\n", client_ptr->name);
    printf("Account number: %d\n", client_ptr->acc_no);
    printf("Account balance: %.2f\n", client_ptr->balance);
    printf("Number of transactions: %d\n", client_ptr->transaction_count);
}

void transaction_details(Client *client_ptr){
    printf("Transaction details: \n");
    int i;
    for (int i = 0; i < client_ptr->transaction_count; i++){
        printf("Transaction %d\t", i + 1);
        printf("Transfer to: %s\t", client_ptr->transaction_list[i].transfer_to);
        printf("Transfer from: %s\t", client_ptr->transaction_list[i].transfer_from);
        printf("Transfer amount: %.2f\t", client_ptr->transaction_list[i].transfer_amount);
        printf("\n");
    }
}




