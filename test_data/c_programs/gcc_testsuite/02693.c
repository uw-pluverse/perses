
typedef __int128 L;



float f;

int
main ()
{
  L i = f;
  if (i <= 10)
    do
      {
 ++i;
 asm ("");
      }
    while (i != 11);
  return 0;
}
