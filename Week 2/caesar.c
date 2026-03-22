#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) return 1;
    for (int i = 0; i < strlen(argv[1]); i++) if (!isdigit(argv[1][i])) return 1;
    int k = atoi(argv[1]);
    string s = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(s); i++) {
        if (isupper(s[i])) printf("%c", (s[i] - 'A' + k) % 26 + 'A');
        else if (islower(s[i])) printf("%c", (s[i] - 'a' + k) % 26 + 'a');
        else printf("%c", s[i]);
    }
    printf("\n");
}
