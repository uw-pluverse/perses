
f1()
{
 int b=(-2147483647 -1);
 return b>=(-2147483647 -1);
}

f2()
{
 int b=(-2147483647 -1)+1;
 return b>= (unsigned)(2147483647 +2);
}

f3()
{
 int b=2147483647;
 return b>=2147483647;
}

f4()
{
 int b=-1;
 return b>=(2147483647 *2U +1U);
}

main ()
{
 if((f1()&f2()&f3()&f4())!=1)
  abort();
  exit(0);
}
