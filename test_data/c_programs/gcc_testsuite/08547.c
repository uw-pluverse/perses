



extern __attribute__((visibility ("hidden"))) int n;

int
mach_error_type(int sub)
{
 if (sub >= n)
     return 1;
 return 0;
}
