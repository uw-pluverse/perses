


int *a, *b, *c;
int something;

void foo()
{
  int i, j;


 for (int i=0; i < 1000; i++)
    a[i] = b[j];


 for (; i < 5; ++i)
    a[i] = i;


 for (int i=0; ; ++i)
    a[i] = i;


 for (int i=0; i < 1234; )
    a[i] = i*2;

 i = 5;


  struct S {
    int i;
  };
 for (struct S ss = { 0 }; ss.i <= 1000; ++ss.i)
    a[ss.i] = b[ss.i];

 for (float f=0.0; f < 15.0; ++f)
    a[(int)f] = (int) f;


 for (int *i=c; i < &c[100]; ++i)
    *a = '5';


 for (int i=j; i == 5; ++i)
    a[i] = b[i];


 for (int i=0; i+j < 1234; ++i)
    a[i] = b[i];


 for (int i=0; 1234 < i + j; ++i)
    a[i] = b[i];


 for (int i=0; 1234 + j < i; ++i)
    a[i] = b[i];



 for (int i=0; (char)i < 1234; ++i)
    a[i] = b[i];

 for (int i=255; i != something; --i)
    a[i] = b[i];

 for (int i=100; i != 5; i += something)
    a[i] = b[i];


 for (int i=0; i < 100; j++)
    a[i] = b[i];


 for (int i=0; i < 100; j = i + 1)
    a[i] = b[i];


 for (int i=0; i < 100; i = j + 1)
    a[i] = b[i];

 for (int i=0; i < 100; i = i + 5)
    a[i] = b[i];


 for (int i=0; i < 100; i *= 5)
    a[i] = b[i];

 for (int i=0; i < 100; i -= j)
    a[i] = b[i];

 for (int i=0; i < 100; i = i + j)
    a[i] = b[i];

 for (int i=0; i < 100; i = j + i)
    a[i] = b[i];

 for (int i=0; i < 100; ++i, ++j)
    a[i] = b[i];

 for (int *point=0; point < b; ++point)
    *point = 555;

 for (int *point=0; point > b; --point)
    *point = 555;
}
