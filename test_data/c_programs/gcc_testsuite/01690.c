
void test0(void);

extern void abort(void);

int main(int argc, char **argv)
{
   test0();
   return 0;
}

void test_address(void *c_ptr, int expected_value)
{
   if((*(int *)(c_ptr)) != expected_value)
      abort();
   return;
}
