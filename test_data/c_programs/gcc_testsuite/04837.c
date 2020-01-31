


extern int foo (int);
extern int bar (int, int);
extern int flagA;
extern int flagB;
extern int flagC;
extern int flagD;

int
fn_1 (int flag)
{
  int x = 4, y = 5;
  if (flag)
    x = 3;
    y = 2;
  return x * y;
}

int
fn_2 (int flag, int x, int y)
{
  if (flag)
    x++; y++;

  return x * y;
}

int
fn_3 (int flag)
{
  int x = 4, y = 5;
  if (flag)
    x = 3;
  else
    x = 2;
    y = 2;
  return x * y;
}

void
fn_4 (double *a, double *b, double *c)
{
  int i = 0;
  while (i < 10)
    a[i] = b[i] * c[i];
    i++;
}

void
fn_5 (double *a, double *b, double *sum, double *prod)
{
  int i = 0;
  for (i = 0; i < 10; i++)
    sum[i] = a[i] * b[i];
    prod[i] = a[i] * b[i];
}


int fn_6 (int a, int b, int c)
{
 int err;


 if ((err = foo (a)) != 0)
  goto fail;
 if ((err = foo (b)) != 0)
  goto fail;
  goto fail;
 if ((err = foo (c)) != 0)
  goto fail;


fail:
 return err;
}

int fn_7 (int p, int q, int r, int s, int t)
{
  if (bar (p, q))
    {
      if (p)
        q++; r++;
      t++;
    }
  return p + q + r + s + t;
}

int fn_8 (int a, int b, int c)
{

  if (a) return b; else return c;
}

void fn_9 (int flag)
{
  if (flag)
    foo (0);
    foo (1);
}

void fn_10 (int flag)
{
  if (flag)
    if (flag / 2)
      {
        foo (0);
        foo (1);
      }
    foo (2);
  foo (3);
}

void fn_11 (void)
{
  if (flagA)
    if (flagB)
      if (flagC)
        foo (0);
        bar (1, 2);
}

void fn_12 (void)
{
  if (flagA)
    if (flagB)
      if (flagC)
        foo (0);
      bar (1, 2);
}

void fn_13 (void)
{
  if (flagA)
    if (flagB)
      if (flagC)
        foo (0);
    bar (1, 2);
}




void fn_14 (void)
{
  int i;
  for ((i) = (0); (i) < (10); (i++))
    foo (i);
    bar (i, i);
}



void fn_15 (void)
{
  int i;
  for ((i) = (0); (i) < (10); (i++))
    foo (i);
    bar (i, i);
}


void fn_16_spaces (void)
{
  int i;
  for (i = 0; i < 10; i++)
    while (flagA)
      if (flagB)
        foo (0);
        foo (1);
}

void fn_16_tabs (void)
{
  int i;
  for (i = 0; i < 10; i++)
    while (flagA)
      if (flagB)
 foo (0);
 foo (1);
}

void fn_17_spaces (void)
{
  int i;
  for (i = 0; i < 10; i++)
    while (flagA)
      if (flagB)
        foo (0);
    foo (1);
}

void fn_17_tabs (void)
{
  int i;
  for (i = 0; i < 10; i++)
    while (flagA)
      if (flagB)
 foo (0);
    foo (1);
}

void fn_18_spaces (void)
{
  int i;
  for (i = 0; i < 10; i++)
    while (flagA)
      if (flagB)
        foo (0);
      foo (1);
}

void fn_18_tabs (void)
{
  int i;
  for (i = 0; i < 10; i++)
    while (flagA)
      if (flagB)
 foo (0);
      foo (1);
}


int fn_19 (void) { if (flagA) return 1; else return 0; }




void
fn_20 (unsigned int l)
{
  unsigned int i;

  for (i = 0; i < 10; i++)
    {
      unsigned int n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;

      for (n0 = 0; n0 < l; n0++)
 for (n1 = 0; n1 < l; n1++)
   for (n2 = 0; n2 < l; n2++)
     for (n3 = 0; n3 < l; n3++)
       for (n4 = 0; n4 < l; n4++)
  for (n5 = 0; n5 < l; n5++)
    for (n6 = 0; n6 < l; n6++)
      for (n7 = 0; n7 < l; n7++)
        for (n8 = 0; n8 < l; n8++)
   for (n9 = 0; n9 < l; n9++)
     for (n10 = 0; n10 < l; n10++)
       for (n11 = 0; n11 < l; n11++)
         {
    if (flagA)
      foo (0);
    foo (1);
         }
      foo (2);
    }
}




void fn_21 (void)
{
  foo (0);
  if (flagA)
    {
      foo (1);


      {
 foo (2);
 if (flagB)
   {
     if (flagC)
       foo (3);
     else
       foo (4);
   }
 else if (flagD)
   foo (5);
 else
   foo (6);
      }

    }
}



int fn_22 (void)
{
  int err = 0;
  do { err = foo (0); if (err) goto out; } while (0);
  do { err = foo (1); if (err) foo (2); else foo (3); foo (4); } while (0);



 out:
  return err;
}


void fn_23 (void) { foo (0); foo (1); if (flagA) foo (2); foo (3); foo (4); }



void fn_24 (void)
{
  foo (0);
  if (flagA)
  foo (1);
  foo (2);
}
void fn_25 (int c, int lower_bound, int upper_bound)
{
  { while (flagA) { if (flagB) { if (lower_bound < 0) lower_bound = 0; lower_bound = lower_bound * 10 + c - '0'; } } };
}




void fn_26 (void)
{
  if (flagA) {
    if (flagB) foo (0); }
  foo (1);
}




void fn_27 (void)
{
       if (flagA)
  foo (0);
         foo (1);
}



void fn_28 (void)
{
  if (flagA)
    foo (0);
  else
    foo (1);;
}




void fn_29 (void)
{
  if (flagA)
    if (flagB)
      foo (0);;
    foo (1);
}



void fn_30 (void)
{
  if (flagA)
    foo (0);



    foo (1);
}


void fn_31 (void)
{
  if (flagA)
    foo (0);
  else if (flagB)
    foo (1);
  else if (flagC)
    foo (2);
  else
    foo (3);
}


int
fn_32 (int flag)
{
  int x = 4, y = 5;

 if (flag)
    x = 3;
    y = 2;

 return x * y;
}



void
fn_33_k_and_r_style (void)
{
  int i;
  for (i = 0; i < 10; i++) {
    if (flagB) {
      foo(0);
      foo(1);
    } else {
      foo(2);
      foo(3);
    }
    foo(4);
  }
}

void
fn_33_stroustrup_style (void)
{
  int i;
  for (i = 0; i < 10; i++) {
    if (flagA) {
      foo(0);
      foo(1);
    }
    else {
      foo(2);
      foo(3);
    }
    foo(4);
  }
}

void
fn_33_allman_style (void)
{
  int i;
  for (i = 0; i < 10; i++)
  {
    if (flagA)
    {
      foo(0);
      foo(1);
    }
    else
    {
      foo(2);
      foo(3);
    }
    foo(4);
  }
}

void
fn_33_whitesmiths_style (void)
{
    int i;
    for (i = 0; i < 10; i++)
        {
        if (flagA)
            {
            foo(0);
            foo(1);
            }
        else
            {
            foo(2);
            foo(3);
            }
        foo(4);
        }
}

void
fn_33_horstmann_style (void)
{
    int i;
    for (i = 0; i < 10; i++)
    { if (flagA)
        { foo(0);
            foo(1);
        }
        else
        { foo(2);
            foo(3);
        }
        foo(4);
    }
}

void
fn_33_ratliff_banner_style (void)
{
    int i;
    for (i = 0; i < 10; i++) {
       if (flagA) {
           foo(0);
           foo(1);
           }
       else {
            foo(2);
            foo(3);
            }
       foo(4);
       }
}

void
fn_33_lisp_style (void)
{
  int i;
  for (i = 0; i < 10; i++) {
    if (flagA) {
        foo(0);
        foo(1); }
    else {
        foo(2);
        foo(3); }
    foo(4); }
}





void
fn_34_indent_dash_gnu (void)
{
  int i;
  while (flagA)
    for (i = 0; i < 10; i++)
      {
 if (flagB)
   {
     foo (0);
     foo (1);
   }
 else
   {
     foo (2);
     foo (3);
   }
 foo (4);
      }
  foo (5);
}


void fn_34_indent_dash_kr(void)
{
    int i;
    while (flagA)
 for (i = 0; i < 10; i++) {
     if (flagB) {
  foo(0);
  foo(1);
     } else {
  foo(2);
  foo(3);
     }
     foo(4);
 }
    foo(5);
}


void
fn_34_indent_dash_orig(void)
{
    int i;
    while (flagA)
 for (i = 0; i < 10; i++) {
     if (flagB) {
  foo(0);
  foo(1);
     } else {
  foo(2);
  foo(3);
     }
     foo(4);
 }
    foo(5);
}







void fn_34_indent_linux_style(void)
{
 int i;
 while (flagA)
  for (i = 0; i < 10; i++) {
   if (flagB) {
    foo(0);
    foo(1);
   } else {
    foo(2);
    foo(3);
   }
   foo(4);
  }
 foo(5);
}


int fn_35 (int v)
{
    int res = 28;

    if (v == 2)
    {
        res = 27;
    } else
    {
        res = 18;
    }
    return res;
}






void
fn_36 (void)
{

 if (flagA) {
  foo(0);
  foo(1);
  foo(2);
 } else

 {
  foo(3);
  foo(4);
  foo(5);
 }
 foo(6);
}




void
fn_37 (void)
{
  int i;




  while (flagA);
    foo (0);

  if (flagA)
    ;
  else if (flagB);
    foo (0);
  while (flagA)
              ;
    foo (0);

  if (flagA)
    ;
  else if (flagB)
    foo (1);
    foo (2);

  if (flagA)
    foo (1);
  else if (flagB)
    foo (2);
    foo (3);

  if (flagB)
              ;
    {
      foo (0);
    }

  if (flagB)
              ;
   {
     foo (0);
   }


  if (flagB)
    ;
  else; foo (0);

  if (flagC); foo (2);

  if (flagA)
    ; {
      foo (1);
    }

  if (flagB) ;
    return;

  if (flagB) ;
    foo (1);

  for (i = 0; i < 10; i++);
    foo (2);

  for (i = 0; i < 10; i++);
    foo (2);

  for (i = 0; i < 10; i++);
    {
      foo (3);
    }

  for (i = 0; i < 10; i++);
  {
    foo (3);
  }

  while (i++); {
    foo (3);
  }

  if (i++); {
    foo (3);
  }

  if (flagA) {
    foo (1);
  } else
    if (flagB)
       foo (2);
    foo (3);

  if (flagA)
    foo (1);
  else if (flagB);
    foo (2);

  for (i = 0;
       i < 10;
       i++);
    foo (i);

  if (flagA)
  {
    foo (1);
  }
  else if (flagB);
  {
    foo (2);
  }



}




void
fn_38 (void)
{
  int i = 0;

  while (flagA)
    ;
    foo (0);

  if (flagB)
    ;
    {
      foo (0);
    }

  while (flagC);
  foo (2);

  if (flagA)
    while (flagC++);
  else
    foo (2);

  if (i)
    while (i++ < 10000);
  foo (5);

  if (i) while (i++ < 10000);
  foo (5);

  if (flagA) {
    foo (1);
  } else
  if (flagB)
    foo (2);
  foo (3);

  if (flagA)
    {
    foo (1);
    } else
  if (flagB)
    foo (2);
  foo (3);

  for (i = 0;
       i < 10;
       i++
  );
  foo (i);
}




void
fn_39 (void)
{
  int i;

  if (flagA)
    ;
  if (flagB)
    ;

  if (flagA)
    if (flagB)
      foo (0);
    else
      foo (1);
  else
    foo (2);

  for (i = 0;
       i < 10;
       i++);
  foo (i);

  do foo (0); while (flagA);
}



void pr69122 (void)
{
  if (flagA)
       foo (0);
       foo (1);
}
void
fn_40_a (const char *end, const char *thousands, int thousands_len)
{
  int cnt;

  while (flagA)
    if (flagA
        && ({ for (cnt = 0; cnt < thousands_len; ++cnt)
              if (thousands[cnt] != end[cnt])
                break;
              cnt < thousands_len; })
        && flagB)
      break;
}




void
fn_40_b (const char *end, const char *thousands, int thousands_len)
{
  int cnt;

  while (flagA)
    if (flagA
        && ({ for (cnt = 0; cnt < thousands_len; ++cnt)
                if (thousands[cnt] != end[cnt])
                  break;
              cnt < thousands_len; })
        && flagB)
      break;
}




void
fn_41_a (void)
{
  if (flagA)
    {
    }
  else if (flagB)
  fail:
    foo (0);

  foo (1);
  if (!flagC)
    goto fail;
}




void
fn_41_b (void)
{
  if (flagA)
    {
    }
  else if (flagB)
   fail:
    foo (0);

  foo (1);
  if (!flagC)
    goto fail;
}
int
fn_42_a (int locked)
{


    int i;

    if (locked)
        i = foo (0);
    else
        i = foo (1);

        if (i > 0)
        return 1;
    return 0;

}




int
fn_42_b (int locked)
{


    int i;

    if (locked)
        i = foo (0);
    else
        i = foo (1);

        if (i > 0)
        return 1;
    return 0;

}
int
fn_42_c (int locked, int i)
{


    if (locked)
                  ;

        if (i > 0)
        return 1;
    return 0;

}



int pr70085 (int x, int y)
{
  if (x > y)
    return x - y;


    if (x == y)
      return 0;


  return -1;
}
void
test43_a (void)
{
  if (flagA) {
    foo (1);
  } else if (flagB)
 foo (2);
 foo (3);
}






void
test43_b (void)
{
  if (flagA) {
    foo (1);
  } else if (flagB)
  foo (2);
  foo (3);
}






void
test43_c (void)
{
  if (flagA) {
    foo (1);
  } else if (flagB)
   foo (2);
   foo (3);
}



void
test43_d (void)
{
  if (flagA) {
    foo (1);
  } else if (flagB)
    foo (2);
    foo (3);
}



void
test43_e (void)
{
  if (flagA) {
    foo (1);
  } else if (flagB)
      foo (2);
      foo (3);
}



void
test43_f (void)
{
  if (flagA) {
    foo (1);
  } else if (flagB)
         foo (2);
         foo (3);
}



void
test43_g (void)
{
  if (flagA) {
    foo (1);
  } else if (flagB)
            foo (2);
            foo (3);
}
void
test44_a (void)
{
  if (flagA) {
    foo (1);
  } else
 foo (2);
 foo (3);
}






void
test44_b (void)
{
  if (flagA) {
    foo (1);
  } else
  foo (2);
  foo (3);
}






void
test44_c (void)
{
  if (flagA) {
    foo (1);
  } else
   foo (2);
   foo (3);
}



void
test44_d (void)
{
  if (flagA) {
    foo (1);
  } else
    foo (2);
    foo (3);
}



void
test44_e (void)
{
  if (flagA) {
    foo (1);
  } else
        foo (2);
        foo (3);
}
