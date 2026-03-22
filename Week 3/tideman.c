void lock_pairs(void) {
    for (int i = 0; i < pair_count; i++) {
        if (!has_cycle(pairs[i].winner, pairs[i].loser))
            locked[pairs[i].winner][pairs[i].loser] = true;
    }
}
bool has_cycle(int winner, int loser) {
    if (loser == winner) return true;
    for (int i = 0; i < candidate_count; i++) {
        if (locked[loser][i] && has_cycle(winner, i)) return true;
    }
    return false;
}
