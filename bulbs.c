#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;
void print_bulb(int bit);

int main(void)
{
    // Asking a string from the user
    string user_prompt = get_string("Message:  ");

    // Cycle for converting of symbol to number of ASCII chart
    for (int i = 0; i < strlen(user_prompt); i++)
    {
        int ascii_num = user_prompt[i];
        // Create an array to store counting for transformation into the binary system
        int bit[7];

        // Cycle for counting into zeros and ones
        for (int k = 0; k < BITS_IN_BYTE; k++)
        {
            bit[k] = ascii_num % 2;
            ascii_num /= 2;
        }
        // Cycle for output of the sequence of zeros and ones in reverse
        for (int l = 7; l > -1; l--)
        {
            int bit2 = bit[l];
            print_bulb(bit2);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
