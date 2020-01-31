const unsigned long Size = (1l << 60);
struct Chunk1 {
  char padding[Size];
  char more_padding[1][Size];
  char data;
};
int test1 = __builtin_offsetof(struct Chunk1, data);
struct Chunk2 {
  char padding[Size][Size][Size];
  char data;
};
int test2 = __builtin_offsetof(struct Chunk2, data);
