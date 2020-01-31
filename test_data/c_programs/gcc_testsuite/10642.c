extern int x[];
int *foo[] = { &x[0] };

int main() { return *foo[0]; }
