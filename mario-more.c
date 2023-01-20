#include <cs50.h>
#include <stdio.h>

void make_cycle_for_hashes(int user_prompt_receiver, int i); // Initialization for hashes cycle
int user_prompt_receiver(void);

int main(void)
{
    int users_high = user_prompt_receiver(); // Make a variable for users' prompt

    for (int i = 0; i < users_high; i++) // Primary cycle for the end of line
    {
        for (int k = users_high; k > -1; k--) // Reversive cycle for space gaps
        {
            if (k < i + 2)
            {
                break;
            }
            printf(" ");
        }
        make_cycle_for_hashes(users_high, i); // First hashes cycle function call

        for (int j = 0; j < 2; j++)
        {
            if (j > 2)
            {
                break;
            }
            printf(" ");
        }

        make_cycle_for_hashes(users_high, i); // Second hashes cycle function call

        printf("\n");
    }
}

// Functions
int user_prompt_receiver(void)
{
    int user_prompt;

    do
    {
        user_prompt = get_int("Please input height of the pyramid: "); // Ask users' prompt
    }
    while (user_prompt < 1 || user_prompt > 8); // Check-expression of users' prompt

    return user_prompt;
}

// Body of hashes cycle
void make_cycle_for_hashes(int user_prompt_count, int i)
{
    for (int j = 0; j < user_prompt_count; j++)
    {
        if (j > i)
        {
            break;
        }
        printf("#");
    }
}