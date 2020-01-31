







static int d = 4;
extern void abort (void);
extern void exit (int);

int main()
{

  if (d != 4)
    abort ();

  if (((200) / 2) != 100)
    abort ();

  exit (0);
}
