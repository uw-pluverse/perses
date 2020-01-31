

int
gang ()
{
 for (int i = 0; i < 10; i++)
    {
    }

  return 1;
}

int
worker ()
{
 for (int i = 0; i < 10; i++)
    {
    }

  return 1;
}

int
vector ()
{
 for (int i = 0; i < 10; i++)
    {
    }

  return 1;
}

int
seq ()
{
  return 1;
}

int
main ()
{
  int red = 0;
 {

 for (int i = 0; i < 10; i++)
      red += gang ();

 for (int i = 0; i < 10; i++)
      red += worker ();

 for (int i = 0; i < 10; i++)
      red += vector ();


 for (int i = 0; i < 10; i++)
      red += gang ();

 for (int i = 0; i < 10; i++)
      red += gang ();

 for (int i = 0; i < 10; i++)
      red += gang ();


 for (int i = 0; i < 10; i++)
      red += worker ();

 for (int i = 0; i < 10; i++)
      red += worker ();

 for (int i = 0; i < 10; i++)
      red += worker ();


 for (int i = 0; i < 10; i++)
      red += vector ();

 for (int i = 0; i < 10; i++)
      red += vector ();

 for (int i = 0; i < 10; i++)
      red += vector ();


 for (int i = 0; i < 10; i++)
      red += seq ();

 for (int i = 0; i < 10; i++)
      red += seq ();

 for (int i = 0; i < 10; i++)
      red += seq ();
  }

  return 0;
}
