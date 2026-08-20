#ifdef DEBUG
int level = 2;
#else
int level = 0;
#endif

int main(void) {
#if defined(A) && !defined(B)
  return level;
#elif defined(C)
  return 1;
#else
  return 0;
#endif
}
