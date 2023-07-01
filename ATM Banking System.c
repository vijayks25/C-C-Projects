#include <stdio.h>
#include <windows.h>
#include <time.h>

int main() {
    int pin = 9876;
    int option, entered_pin, count = 0;
    int amount = 1;
    float balance = 8765;
    int continue_transaction = 1;

    time_t now;
    time(&now);

    printf("\n");
    printf("\t\t\t\t\t       %s", ctime(&now));
    printf("\n\t\t\t************ WELCOME TO MY ATM ************");

    while (pin != entered_pin) {
        printf("\nPlease enter your PIN: ");
        scanf("%d", &entered_pin);

        if (entered_pin != pin) {
            Beep(500, 450);
            printf("Invalid PIN!");
        }

        count++;

        if (count == 3 && pin != entered_pin) {
            exit(0);
        }
    }

    while (continue_transaction != 0) {
        printf("\n\t\t\t************* AVAILABLE TRANSACTIONS ************");
        printf("\n\n\t\t1. Withdrawal");
        printf("\n\t\t2. Deposit");
        printf("\n\t\t3. Check Balance");
        printf("\n\n\t\t4. Please select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n\t\tEnter the amount: ");
                scanf("%d", &amount);

                if (balance < amount) {
                    printf("\n\tSorry, insufficient balance.");
                    amount = 1;
                    break;
                } else {
                    balance -= amount;
                    printf("\n\t\tYou have withdrawn Rs.%d. Your new balance is %.2f", amount, balance);
                    amount = 1;
                    break;
                }

            case 2:
                printf("\n\t\tPlease enter the amount: ");
                scanf("%d", &amount);
                balance += amount;
                printf("\n\t\tYou have deposited Rs.%d. Your new balance is %.2f", amount, balance);
                printf("\n\t\t************ Thank you for banking with us! ************");
                amount = 1;
                break;

            case 3:
                printf("\n\t\tYour balance is Rs.%.2f", balance);
                break;

            default:
                Beep(500, 450);
                printf("\n\t\tInvalid option!");
        }
    }

    printf("\n\t\tDo you wish to perform another transaction? Press 1 for Yes, 0 for No: ");
    scanf("%d", &continue_transaction);

    return 0;
}
