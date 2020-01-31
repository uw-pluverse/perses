

extern void abort ();
extern void exit (int);




int main(void)
{
  int listElem[4]={30,2,10,5};
  int listSmall[2];
  int i, j;
  int posGreatest=-1, greatest=-1;

  for (i=0; i<2; i++) {
    listSmall[i] = listElem[i];
    if (listElem[i] > greatest) {
      posGreatest = i;
      greatest = listElem[i];
    }
  }

  for (i=2; i<4; i++) {
    if (listElem[i] < greatest) {
      listSmall[posGreatest] = listElem[i];
      posGreatest = 0;
      greatest = listSmall[0];
      for (j=1; j<2; j++)
 if (listSmall[j] > greatest) {
   posGreatest = j;
   greatest = listSmall[j];
 }
    }
  }

  if (listSmall[0] != 5 || listSmall[1] != 2)
    abort ();
  exit (0);
}
