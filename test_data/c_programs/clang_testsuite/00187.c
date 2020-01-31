void foo() {
  break;
}
void foo2() {
  continue;
}
int pr8880_9 (int first) {
  switch(({ if (first) { first = 0; break; } 1; })) {
  case 2: return 2;
  default: return 0;
  }
}
void pr8880_24() {
  for (({break;});;);
}
void pr8880_25() {
  for (({continue;});;);
}
