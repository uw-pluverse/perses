





struct S { int v; };
struct S s;

void __attribute__((externally_visible))
func1 (void)
{
  struct S *p = &s;
}

int main() { return 0; }
