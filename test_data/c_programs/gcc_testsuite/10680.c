


union u { struct { int i; }; };

extern int foo (union u *);

int main() { return 0; }
