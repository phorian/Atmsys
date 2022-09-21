#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

/*****************************
Creating a Atm banking system
1.Update console color
2.Function to deposit money
3.Function to withdraw Money
4.Check account Balance
*****************************/
void withdrawFunds();
void depositFunds();
void checkBal();
int pin=1234;                   //default pin for the user
int opt;                       //option to select choices
int entPin;                   //Pin entered by user
int count=0;                 //Pin entry counter
int amount=1;               //amount of money to deposit or withdraw
float balance = 50000;      //initial balance
int contTxn=1;             //To determine if user wants to continue the transaction

//Declare time variable and Show current Date and Time
time_t now;
int main(){
    system("color 3F");
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t    %s",ctime(&now));
    printf("\n\t\t\t===============# WELCOME TO X-NOVA. ATM #===============");

    //loop to go through the pin entry before it exits (3 tries)
    while(pin != entPin){
        printf("\nEnter Your Pin: ");
        scanf("%d", &entPin);
        if(entPin != pin){
            Beep(610,500);
            printf("INVALID PIN!!!");
        }
        count++;
        if(count == 3 && pin != entPin){
            exit(0);
        }
    }

    //going through the transaction
    while(contTxn != 0){
        system("cls");
        printf("\n\t\t\t============* Please Select Your Action *============");
        printf("\n\n\t\t\t\t    %s",ctime(&now));
        printf("\n\n\t[1]. Deposit");
        printf("\n\t[2]. Withdrawal");
        printf("\n\t[3]. Check Balance");
        printf("\n\n\t\t\t Please enter your option: ");
        scanf("%d", &opt);
        switch(opt){
        case 1:
            depositFunds();
            break;
        case 2:
            withdrawFunds();
            break;
        case 3:
            printf("\n\t\t\tYour Balance is .2%f ", balance);
            break;

        default:
            printf("\n\t\tInvalid Option!!!");
            Beep(610,500);
        }
    printf("\n\n\tDo you wish to perform another transaction?... Press1[Yes], 0[No]");
    scanf("%d", &contTxn);
    }

}

void withdrawFunds(){
    while(amount % 500 != 0){
        printf("\nEnter Amount to Withdraw: ");
        scanf("%d", &amount);
        if(amount % 500 != 0)
            printf("\nPlease Enter amount in multiples of 500");
    }
    if (balance < amount){
        printf("\n\n\t\t\t\ Insufficient Funds!!!");
        amount = 1;
    }
    else {
        balance -= amount;
        printf("\nYou have withdrawn NGN%d. Your new balance is %.2f", amount, balance);
        printf("\n\t\t\t============* THANK YOU FOR BANKING WITH X-NOVA. *============");
        amount = 1;
        }
}

void depositFunds(){
    printf("\nPlease Enter the amount to deposit: ");
    scanf("%d", &amount);
    balance +=amount;
    printf("You have deposited NGN%d. Your new balance is %.2f", amount, balance);
    amount = 1;
}


