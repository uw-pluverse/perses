struct t
{
  int aMember;
};

struct t *const aPointer = 0;

void foo()
{
  int anInt = (aPointer == 0) ? 0 : aPointer->aMember;
}
