#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

// Functions
int get_cents(void)
{
    // Initialization of users' prompt variable
    int user_prompt;

    do
    {
        // Asks a prompt from the user
        user_prompt = get_int("Change owed: ");
    }
    // Check-expression for users' prompt
    while (user_prompt < 0);

    return user_prompt;
}

int calculate_quarters(int cents)
{
    // This function calculate how many quarters the cashier should change
    int answer_count_cent_coins = cents / 25;
    return answer_count_cent_coins;
}

int calculate_dimes(int cents)
{
    // This function calculate how many dimes the cashier should change
    int answer_count_dime_coins = cents / 10;
    return answer_count_dime_coins;
}

int calculate_nickels(int cents)
{
    // This function calculate how many nickels the cashier should change
    int answer_count_nickel_coins = cents / 5;
    return answer_count_nickel_coins;
}

int calculate_pennies(int cents)
{
    // This function calculate how many pennies the cashier should change
    int answer_count_pennie_coins = cents / 1;
    return answer_count_pennie_coins;
}