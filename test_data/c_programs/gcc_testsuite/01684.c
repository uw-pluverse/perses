
int i;
void test_globals(void);

extern void abort(void);

int main(int argc, char **argv)
{

   if(i != 2)
      abort();
   test_globals();
   return 0;
}
