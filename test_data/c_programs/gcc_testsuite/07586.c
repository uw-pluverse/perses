


void f () __attribute__((weak_import));

typedef void PF (void);

void f(void){};

PF* g (void) { return f; }

int main()
{
 (*g())();
 return 0;
}
