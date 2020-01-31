





void foo (int count, char* pca, char* pcb) {
    int i;
    if (count > 10)
        for (i = 0; i < count; ++i)
            pcb += i;
    else
        for (i = 0; i < count; ++i)
            pca += i;
    *pca = *pcb;
}
