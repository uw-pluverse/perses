extern void abort(void);

typedef struct myCDerived
{
   int cInt;
   double cDouble;
   float cFloat;
   short cShort;
   void *ptr;
}myCDerived_t;






void testDerivedPtrs(myCDerived_t *cDerivedPtr,
                     myCDerived_t *derivedArray, int arrayLen,
                     myCDerived_t *derived2d, int dim1, int dim2);

int main(int argc, char **argv)
{
   myCDerived_t cDerived;
   myCDerived_t derivedArray[10];
   myCDerived_t derived2DArray[2][3];
   int i = 0;
   int j = 0;

   cDerived.cInt = 1;
   cDerived.cDouble = 2.0;
   cDerived.cFloat = 3.0;
   cDerived.cShort = 4;


   cDerived.ptr = 0;

   for(i = 0; i < 10; i++)
   {
      derivedArray[i].cInt = (i+1) * 1;
      derivedArray[i].cDouble = (i+1) * 1.0;
      derivedArray[i].cFloat = (i+1) * 1.0;
      derivedArray[i].cShort = (i+1) * 1;

      derivedArray[i].ptr = 0;
   }

   for(i = 0; i < 2; i++)
   {
      for(j = 0; j < 3; j++)
      {
         derived2DArray[i][j].cInt = ((i*2) * 1) + j;
         derived2DArray[i][j].cDouble = ((i*2) * 1.0) + j;
         derived2DArray[i][j].cFloat = ((i*2) * 1.0) + j;
         derived2DArray[i][j].cShort = ((i*2) * 1) + j;

         derived2DArray[i][j].ptr = 0;
      }
   }


   testDerivedPtrs(&cDerived, derivedArray, 10,
                   derived2DArray[0], 3, 2);

   return 0;
}
