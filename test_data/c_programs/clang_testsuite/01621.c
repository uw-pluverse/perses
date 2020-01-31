struct
{
   int a : 1;
   short b : 1;
} t;
static int arr[(sizeof(t) == 8) ? 1 : -1];
