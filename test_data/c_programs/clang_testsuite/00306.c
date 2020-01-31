void pr8880_cg_1(int *iptr) {
  int i, j;
  for (i = 2; i != 10 ; i++ )
    for (j = 3 ; j < 22; (void)({ ++j; break; j;})) {
      *iptr = 7;
    }
}
void pr8880_cg_2(int *iptr) {
  int i, j;
  for (i = 2; i != 10 ; i++ )
    for (j = 3 ; j < 22; (void)({ ++j; continue; j;})) {
      *iptr = 7;
    }
}
void pr8880_cg_3(int *iptr) {
  int i, j;
  for (i = 2 ; i != 10 ; i++ )
    for (j = 3 ; ({break; j;}); j++) {
      *iptr = 7;
    }
}
void pr8880_cg_4(int *iptr) {
  int i, j;
  for (i = 2 ; i != 10 ; i++ )
    for (j = 3 ; ({continue; j;}); j++) {
      *iptr = 7;
    }
}
void pr8880_cg_5(int x, int *iptr) {
  int y = 5;
  while(--x) {
    while(({ break; --y; })) {
      *iptr = 7;
    }
  }
}
void pr8880_cg_6(int x, int *iptr) {
  int y = 5;
  while(--x) {
    do {
      *iptr = 7;
    } while(({ break; --y; }));
  }
}
