#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>


int key = 0;
int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }


    key = atoi(argv[1]);

    string word = get_string("plaintext: ");


    for (int i = 0, n = strlen(word); i < n; i++)
    {


        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            word[i] -= 65;
            word[i] = (word[i] + key) % 26;
            word[i] += 65;
        }


        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] -= 97;
            word[i] = (word[i] + key) % 26;
            word[i] += 97;
        }
    }


    printf("ciphertext: %s\n", word);


    return 0;
}