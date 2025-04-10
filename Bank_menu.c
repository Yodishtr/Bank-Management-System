#include <stdio.h>

// global variables
typedef struct Client{
    char name[50];
    int acc_no;
    float balance;
} Client;

// function prototypes for banking operations
void menu();
void deposit_money(Client *client_ptr, float amount);
void withdraw_money(Client *client_ptr, float *amount);
void transfer_money();
void account_details();
void transaction_details();

// client initalization
Client client;

int main(){
    int choice;
    printf("Enter your name: \n");
    scanf("%s", client.name);
    printf("Enter your account number: \n");
    scanf("%d", client.acc_no);
    menu();
    printf("Enter your choice of options: \n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("You have selected Deposit Money option.\n");
            printf("Enter the amount to deposit: \n");
            float deposit_amount;
            scanf("f", &deposit_amount);
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
            float withdrawal_amount;
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
            transfer_money();
            break;
        case 4:
            account_details();
            break;
        case 5:
            transaction_details();
            break;
        case 6:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
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




