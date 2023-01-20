#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Exception for more than one digit put into command-line
    if (argc != 2 || only_digits(argv[1]) == true)
    {
        return 1;
    }

    string user_prompt = get_string("plaintext:  ");

    printf("ciphertext: ");
    // Execution for every alphabetical char rotation with the cipher condition
    for (int i = 0; i < strlen(user_prompt); i++)
    {
        char c = user_prompt[i];
        printf("%c", rotate(c, atoi(argv[1])));
    }
    printf("\n");

    // Return without any mistake
    return 0;
}

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];

        // Check the expression added by a user as a command-line argument. Is it contains a non-numeric?
        if (isdigit(c) == 0)
        {
            return true;
        }
    }
    return false;
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        // Make the shift to the alphabetical index (from 0 to 26) for uppercase letters
        int index = c - 65;
        int b = (index + n) % 26;
        return b + 65;
    }
    else if (islower(c))
    {
        // Make the shift to the alphabetical index (from 0 to 26) for lowercase letters
        int index = c - 97;
        int b = (index + n) % 26;
        return b + 97;
    }
    else
    {
        return c;
    }
}