int a = __alignof__(long long);

struct {int a;} b;

int c = __alignof__(b.a);