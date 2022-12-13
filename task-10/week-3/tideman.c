#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Loop through candidates
    for (int idx = 0; idx < candidate_count; idx++)
    {
        // Check name is valid
        if (strcmp(candidates[idx], name) == 0)
        {
            // Update ranks array with rank preference
            ranks[rank] = idx;
            return true;
        }
    }
    return false;

}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // for every candidate
    for (int idx = 0; idx < candidate_count; idx++)
    {
        //in candidates
        for (int idy = idx + 1; idy < candidate_count; idy++)
        {
            // Update number of voters who prefer [idx] to [idy]
            preferences[ranks[idx]][ranks[idy]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    //check every candidate
    for (int idx = 0; idx < candidate_count; idx++)
    {
        for (int idy = idx + 1; idy < candidate_count; idy++)
        {
            // is this preferred over the outer?
            if (preferences[idx][idy] > preferences[idy][idx])
            {
                //winner idx over idy
                pairs[pair_count].winner = idx;
                pairs[pair_count].loser = idy;
                pair_count++;
            }
            else if (preferences[idx][idy] < preferences[idy][idx])
            {
                //winner idy over idx
                pairs[pair_count].winner = idy;
                pairs[pair_count].loser = idx;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int idx = pair_count - 1; idx >= 0 ; idx--)
    {
        for (int idy = 0; idy <= idx - 1; idy++)
        {
            if ((preferences[pairs[idy].winner][pairs[idy].loser]) < (preferences[pairs[idy].winner][pairs[idy + 1].loser]))
            {
                pair temp = pairs[idy];
                pairs[idy] = pairs[idy + 1];
                pairs[idy + 1] = temp;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating
bool cycle(int end, int cycle_start)
{
    // Return true if there is a cycle created (Recursion base case)
    if (end == cycle_start)
    {
        return true;
    }
    // Loop through candidates (Recursive case)
    for (int idx = 0; idx < candidate_count; idx++)
    {
        if (locked[end][idx])
        {
            if (cycle(idx, cycle_start))
            {
                return true;
            }
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // Loop through pairs
    for (int idx = 0; idx < pair_count; idx++)
    {
        // If cycle function returns false, lock the pair
        if (!cycle(pairs[idx].loser, pairs[idx].winner))
        {
            locked[pairs[idx].winner][pairs[idx].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // Winner is the candidate with no arrows pointing to them
    for (int idx = 0; idx < candidate_count; idx++)
    {
        int false_count = 0;
        for (int idy = 0; idy < candidate_count; idy++)
        {
            if (!locked[idy][idx])
            {
                false_count++;
                if (false_count == candidate_count)
                {
                    printf("%s\n", candidates[idx]);
                }
            }
        }
    }
    return;
}

