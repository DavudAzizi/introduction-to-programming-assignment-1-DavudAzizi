bool check(const char *word) {
    node *cursor = table[hash(word)];
    while (cursor != NULL) {
        if (strcasecmp(cursor->word, word) == 0) return true;
        cursor = cursor->next;
    }
    return false;
}
unsigned int hash(const char *word) {
    unsigned long h = 5381; int c;
    while ((c = tolower(*word++))) h = ((h << 5) + h) + c;
    return h % N;
}
