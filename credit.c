#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long get_card_num(void);
int count_luhns_algorithm(long card_num);
string check_type_of_card(long card_num);

int main(void)
{
    // Asks for clients' card number
    long card_num = get_card_num();

    // Addition of even and odd digits of the card number by Luhn's algorithm
    int check_sum = count_luhns_algorithm(card_num);

    // Check-expressions for users' prompt
    if (card_num < 999999999999 || (check_sum % 10) != 0 || check_sum == 70 || card_num > 5600000000000000)
    {
        printf("INVALID\n");
    }
    // If the checks passed ok, go to the definition of the card type
    else
    {
        printf("%s\n", check_type_of_card(card_num));
    }
}

long get_card_num(void)
{
    // Asking the user's prompt
    long user_input = get_long("Number: ");
    return user_input;
}

int count_luhns_algorithm(long card_num)
{
    long modulo = 100;
    long second_modulo = 1000;
    long div_first_digit = 10;   // Variable of the divisor to get an even digit
    long div_second_digit = 100; // Variable of the divisor to get an odd digit
    int answer = 0;

    // Cycle to call for any even digits (from the end) with step two and calculate the sum of all even digits (from the rear of the card number) multiplied by two
    for (int i = 0; i < 16; i += 2)
    {
        // Variable for allocation of only one digit
        long count = (card_num % modulo) / div_first_digit;
        int devide = count * 2;

        modulo *= 100;
        div_first_digit *= 100;

        // Condition for calculations with two-digit even numbers (from the rear of the card number)
        if ((devide) >= 10)
        {
            int temp = (devide) % 10;
            devide = ++temp;
        }
        // Addition of all multiplies
        answer += devide;
    }
    // Cycle to call for any odd digits (from the end) with step two and calculate the sum of all odd digits (from the rear of the card number)
    for (int i = 1; i < 16; i += 2)
    {
        // Variable for allocation of only one digit
        long count = (card_num % second_modulo) / div_second_digit;
        int devide = count;

        second_modulo *= 100;
        div_second_digit *= 100;

        // Condition for calculations with two-digit odd numbers (from the rear of the card number)
        if ((devide) >= 10)
        {
            int temp = (devide) % 10;
            devide = ++temp;
        }
        // Addition of all odd digits
        answer += devide;
    }
    return answer += card_num % 10;
}

string check_type_of_card(long card_num)
{
    string value = 0;

    // Expressions to definition type of a card
    if (((card_num % 1000000000000000) / 10000000000000) == 37)
    {
        value = ("AMEX");
    }
    else if (((card_num % 10000000000000000) / 100000000000000) == 51 || ((card_num % 10000000000000000) / 100000000000000) == 52 ||
             ((card_num % 10000000000000000) / 100000000000000) == 53 || ((card_num % 10000000000000000) / 100000000000000) == 54 ||
             ((card_num % 10000000000000000) / 100000000000000) == 55)
    {
        value = ("MASTERCARD");
    }
    else if (((card_num % 10000000000000) / 1000000000000) == 4 || ((card_num % 10000000000000000) / 1000000000000000) == 4)
    {
    }
    return value;
}