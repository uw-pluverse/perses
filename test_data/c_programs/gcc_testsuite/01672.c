double fabs (double);


void changeF90Globals(void);

extern void abort(void);


extern int myf90int;
float myF90Real;
int myF90Array3D[10][5][18];
int myF90Array2D[2][3];
int myVariable;
int c3;
int c4;

int main(int argc, char **argv)
{
   myf90int = 1;
   myF90Real = 1.0;
   myVariable = 2;
   c3 = 3;
   c4 = 4;
   myF90Array3D[2][3][4] = 1;
   myF90Array2D[1][2] = 2;


   changeF90Globals();

   if(myf90int != 2)
      abort();
   if(fabs(myF90Real-3.0) > 0.00000000)
      abort();
   if(myVariable != 4)
      abort();
   if(c3 != 6)
      abort();
   if(c4 != 2)
      abort();
   if(myF90Array3D[2][3][4] != 2)
      abort();
   if(myF90Array2D[1][2] != 3)
      abort();

   return 0;
}
