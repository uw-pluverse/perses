


void ParseStringSidToSid(char *s, int* p) {
    int i = 0;

    while (*s) {
        while (*s && *s != '-')
            s++;
        if (*s== '-')
            s++;

        p[i++] = *s;
    }
}
