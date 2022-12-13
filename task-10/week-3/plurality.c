#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    bool result = false;
    for (int idx = 0; idx < candidate_count; idx++)
    {
        if (!strcmp(candidates[idx].name, name))
        {
            candidates[idx].votes++;
            result = true;
        }
    }
    return result;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max_val = 0;
    int cnt = 0;
    int c[MAX] = {0};
    for (int idx = 0; idx < candidate_count; idx++)
    {
        if (candidates[idx].votes > max_val)
        {
            max_val = candidates[idx].votes;
            memset(&c, 0, sizeof(c));
            cnt = 0;
            c[cnt++] = idx;
        }
        else if (candidates[idx].votes == max_val)
        {
            c[cnt++] = idx;
        }
    }

    for (int idx = 0; idx < cnt; idx++)
    {
        printf("%s\n", candidates[c[idx]].name);
    }
    return;
}

