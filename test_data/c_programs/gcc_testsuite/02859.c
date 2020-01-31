




typedef unsigned int cpp_num_part;
typedef struct cpp_num cpp_num;
struct cpp_num
{
   cpp_num_part high;
   cpp_num_part low;
   int unsignedp;
   int overflow;
};

static int
num_positive (cpp_num num, unsigned int precision)
{
   if (precision > (sizeof (cpp_num_part) * 8))
     {
       precision -= (sizeof (cpp_num_part) * 8);
       return (num.high & (cpp_num_part) 1 << (precision - 1)) == 0;
     }

   return (num.low & (cpp_num_part) 1 << (precision - 1)) == 0;
}

static cpp_num
num_trim (cpp_num num, unsigned int precision)
{
   if (precision > (sizeof (cpp_num_part) * 8))
     {
       precision -= (sizeof (cpp_num_part) * 8);
       if (precision < (sizeof (cpp_num_part) * 8))
         num.high &= ((cpp_num_part) 1 << precision) - 1;
     }
   else
     {
       if (precision < (sizeof (cpp_num_part) * 8))
         num.low &= ((cpp_num_part) 1 << precision) - 1;
       num.high = 0;
     }

   return num;
}


static cpp_num
num_rshift (cpp_num num, unsigned int precision, unsigned int n)
{
   cpp_num_part sign_mask;
   int x = num_positive (num, precision);

   if (num.unsignedp || x)
     sign_mask = 0;
   else
     sign_mask = ~(cpp_num_part) 0;

   if (n >= precision)
     num.high = num.low = sign_mask;
   else
     {

       if (precision < (sizeof (cpp_num_part) * 8))
         num.high = sign_mask, num.low |= sign_mask << precision;
       else if (precision < 2 * (sizeof (cpp_num_part) * 8))
         num.high |= sign_mask << (precision - (sizeof (cpp_num_part) * 8));

       if (n >= (sizeof (cpp_num_part) * 8))
         {
           n -= (sizeof (cpp_num_part) * 8);
           num.low = num.high;
           num.high = sign_mask;
         }

       if (n)
         {
           num.low = (num.low >> n) | (num.high << ((sizeof (cpp_num_part) * 8) - n));
           num.high = (num.high >> n) | (sign_mask << ((sizeof (cpp_num_part) * 8) - n));
         }
     }

   num = num_trim (num, precision);
   num.overflow = 0;
   return num;
}



cpp_num
num_lshift (cpp_num num, unsigned int precision, unsigned int n)
{
   if (n >= precision)
     {
       num.overflow = !num.unsignedp && !((num.low | num.high) == 0);
       num.high = num.low = 0;
     }
   else
     {
       cpp_num orig;
       unsigned int m = n;

       orig = num;
       if (m >= (sizeof (cpp_num_part) * 8))
         {
           m -= (sizeof (cpp_num_part) * 8);
           num.high = num.low;
           num.low = 0;
         }
       if (m)
         {
           num.high = (num.high << m) | (num.low >> ((sizeof (cpp_num_part) * 8) - m));
           num.low <<= m;
         }
       num = num_trim (num, precision);

       if (num.unsignedp)
         num.overflow = 0;
       else
         {
           cpp_num maybe_orig = num_rshift (num, precision, n);
           num.overflow = !(orig.low == maybe_orig.low && orig.high == maybe_orig.high);
         }
     }

   return num;
}

unsigned int precision = 64;
unsigned int n = 16;

cpp_num num = { 0, 3, 0, 0 };

int main()
{
   cpp_num res = num_lshift (num, 64, n);

   if (res.low != 0x30000)
     abort ();

   if (res.high != 0)
     abort ();

   if (res.overflow != 0)
     abort ();

   exit (0);
}
