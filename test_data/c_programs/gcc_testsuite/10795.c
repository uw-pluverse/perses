



const int a = 5;
extern void clone_me (int *);

int
main(void)
{
  int i;
  for (i=0;i<100;i++)
   clone_me ((int *)&a);
  return 0;
}
