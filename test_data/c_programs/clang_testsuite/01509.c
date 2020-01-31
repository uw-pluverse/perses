int test1 = sizeof(struct{char qq[((char*)-1LL) + 1 == 0 ? 1 : -1];});
int test2 = sizeof(struct{char qq[((char*)-1LL) + 1 < (char*) -1 ? 1 : -1];});
