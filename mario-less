#include <cs50.h>
#include <stdio.h>

int users_prompt_receiver(void);

int main(void)
{
    //  Make a variable with the prompt from the user
    int users_high = users_prompt_receiver();

    // The main cycle for the end of the line
    for (int i = 0; i < users_high; i++)
    {
        // Reversive cycle for space gaps
        for (int k = users_high; k > -1; k--)
        {
            if (k < i + 2)
            {
                break;
            }
            printf(" ");
        }
        // Cycle for hashes
        for (int l = 0; l < users_high; l++)
        {
            if (l > i)
            {
                break;
            }
            printf("#");
        }
        printf("\n");
    }
}

// Functions
int users_prompt_receiver(void)
{
    int users_prompt;

    do
    {
        // Ask users' prompt
        users_prompt = get_int("Please input height of the pyramid: ");
    }
    // Check-expression of users' prompt
    while (users_prompt < 1 || users_prompt > 8);

    return users_prompt;
}
