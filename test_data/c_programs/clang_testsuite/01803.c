struct tea_cheese { unsigned magic; };
typedef struct tea_cheese kernel_tea_cheese_t;
extern kernel_tea_cheese_t _wonky_gesticulate_cheese;
void test1( void ) {
  kernel_tea_cheese_t *wonky = &_wonky_gesticulate_cheese;
  struct load_wine *cmd = (void*) &wonky[1];
  cmd = cmd;
  char *p = (void*) &wonky[1];
  kernel_tea_cheese_t *q = &wonky[1];
  kernel_tea_cheese_t r = *q;
}
void test1_b( void ) {
  kernel_tea_cheese_t *wonky = &_wonky_gesticulate_cheese;
  struct load_wine *cmd = (void*) &wonky[1];
  cmd = cmd;
  char *p = (void*) &wonky[1];
  *p = 1;
}
