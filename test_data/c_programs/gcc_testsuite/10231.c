


struct list {
  void (*compare)();
} *listPtr;

static void (*compare)();

__attribute__((transaction_safe))
static void func () {
  listPtr->compare();
  compare();
}
