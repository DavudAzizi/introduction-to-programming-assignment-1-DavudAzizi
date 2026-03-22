#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
int main(void) {
    string s = get_string("Text: ");
    int l = 0, w = 1, sn = 0;
    for (int i = 0, n = strlen(s); i < n; i++) {
        if (isalpha(s[i])) l++;
        else if (isspace(s[i])) w++;
        else if (s[i] == '.' || s[i] == '!' || s[i] == '?') sn++;
    }
    float L = (float)l / w * 100, S = (float)sn / w * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1) printf("Before Grade 1\n");
    else if (index >= 16) printf("Grade 16+\n");
    else printf("Grade %i\n", index);
}
