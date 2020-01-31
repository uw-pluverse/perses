






extern void abort (void);
typedef long unsigned int size_t;
extern void *memset (void *, int, size_t);

char buffer[32];
int argc = 1;

void
main_test (void)
{
  memset (buffer, argc, 0);
  memset (buffer, argc, 1);
  memset (buffer, argc, 2);
  memset (buffer, argc, 3);
  memset (buffer, argc, 4);
  memset (buffer, argc, 5);
  memset (buffer, argc, 6);
  memset (buffer, argc, 7);
  memset (buffer, argc, 8);
  memset (buffer, argc, 9);
  memset (buffer, argc, 10);
  memset (buffer, argc, 11);
  memset (buffer, argc, 12);
  memset (buffer, argc, 13);
  memset (buffer, argc, 14);
  memset (buffer, argc, 15);
  memset (buffer, argc, 16);
  memset (buffer, argc, 17);
}
