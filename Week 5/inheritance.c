person *create_family(int generations) {
    person *p = malloc(sizeof(person));
    if (generations > 1) {
        p->parent[0] = create_family(generations - 1);
        p->parent[1] = create_family(generations - 1);
        p->alleles[0] = p->parent[rand() % 2]->alleles[rand() % 2];
        p->alleles[1] = p->parent[rand() % 2]->alleles[rand() % 2];
    } else {
        p->parent[0] = NULL; p->parent[1] = NULL;
        p->alleles[0] = random_allele(); p->alleles[1] = random_allele();
    }
    return p;
}
