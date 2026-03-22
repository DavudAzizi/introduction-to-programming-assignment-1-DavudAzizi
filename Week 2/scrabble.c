#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string w1 = get_string("Player 1: "), w2 = get_string("Player 2: ");
    int s1 = 0, s2 = 0;
    for (int i = 0, n = strlen(w1); i < n; i++) if (isalpha(w1[i])) s1 += POINTS[toupper(w1[i]) - 'A'];
    for (int i = 0, n = strlen(w2); i < n; i++) if (isalpha(w2[i])) s2 += POINTS[toupper(w2[i]) - 'A'];
    if (s1 > s2) printf("Player 1 wins!\n"); else if (s2 > s1) printf("Player 2 wins!\n"); else printf("Tie!\n");
}
