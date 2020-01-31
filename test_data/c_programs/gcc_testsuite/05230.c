

int t(int a) __attribute__ ((const));
void q (void);
void
threading(int a,int b)
{
 if (t(a))
 {
   if (t(a))
     q();
 }
}
