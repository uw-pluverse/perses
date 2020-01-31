

void gang (void);
void worker (void);
void vector (void);


void seq (void)
{
  gang ();
  worker ();
  vector ();
  seq ();

  int red;

 for (int i = 0; i < 10; i++)
    red ++;

 for (int i = 0; i < 10; i++)
    red ++;

 for (int i = 0; i < 10; i++)
    red ++;

 for (int i = 0; i < 10; i++)
    red ++;
}

void vector (void)
{
  gang ();
  worker ();
  vector ();
  seq ();

  int red;

 for (int i = 0; i < 10; i++)
    red ++;

 for (int i = 0; i < 10; i++)
    red ++;

 for (int i = 0; i < 10; i++)
    red ++;

 for (int i = 0; i < 10; i++)
    red ++;
}

void worker (void)
{
  gang ();
  worker ();
  vector ();
  seq ();

  int red;

 for (int i = 0; i < 10; i++)
    red ++;

 for (int i = 0; i < 10; i++)
    red ++;

 for (int i = 0; i < 10; i++)
    red ++;

 for (int i = 0; i < 10; i++)
    red ++;
}

void gang (void)
{
  gang ();
  worker ();
  vector ();
  seq ();

  int red;

 for (int i = 0; i < 10; i++)
    red ++;

 for (int i = 0; i < 10; i++)
    red ++;

 for (int i = 0; i < 10; i++)
    red ++;

 for (int i = 0; i < 10; i++)
    red ++;
}
