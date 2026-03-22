#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct { string name; int votes; } candidate;
candidate candidates[9];
int candidate_count;

bool vote(string name) {
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, name) == 0) { candidates[i].votes++; return true; }
    }
    return false;
}

void print_winner(void) {
    int max = 0;
    for (int i = 0; i < candidate_count; i++) if (candidates[i].votes > max) max = candidates[i].votes;
    for (int i = 0; i < candidate_count; i++) if (candidates[i].votes == max) printf("%s\n", candidates[i].name);
}
