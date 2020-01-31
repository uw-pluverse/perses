



class X1 extends Throwable {}

class X2 extends Throwable {}

interface I1
{
   int f(int i, int j) throws X1;
}

interface I2 extends I1
{
   int f(int i, int j) throws X1,X2;
}
