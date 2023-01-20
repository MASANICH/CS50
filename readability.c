#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

string userPromptReceiver(void);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = userPromptReceiver();

    // Calculating the Coleman-Liau formula:
    float index = 0.0588 * (count_letters(text) / (count_words(text) * 0.01)) - 0.296 * (count_sentences(text) / (count_words(
                      text) * 0.01)) - 15.8;

    // Exceptions for grades less than 1 and more than 16:
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        int print = round(index);

        // Exceptions for outputs with value only above 1
        if (print > 1)
        {
            printf("Grade %i\n", print);
        }
    }
}

string userPromptReceiver(void)
{
    string text;

    do
    {
        text = get_string("Text: "); // Ask users' prompt
    }
    // Check-expression of users' prompt
    while (isspace(/* Access to the last element of the string */ text[strlen(text) - 1]) != 0 || isspace(text[0]) != 0);
    return text;
}

int count_letters(string text)
{
    int count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        char c = text[i];

        // Check the expression for the user's prompt. Is char in lower or uppercase?
        if ((isupper(c) == 0 || islower(c) == 1) != (isupper(c) == 1 || islower(c) == 0))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        char c = text[i];

        // Check the expression for the user's prompt. Is char a whitespace?
        if (isspace(c) != 0)
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // Check the expression for the user's prompt. Is char a dot, question mark, or exclamation point?
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}