







void
add_bignums (int *out, int *x, int *y)
{
    int p, sum;
    int carry;

    p = 0;
    for (; *x; x++, y++, out++, p++)
    {
 if (p)
     sum = *x + *y + carry;
 else
     sum = *x + *y;

 if (sum < 0)
 {
     carry = 1;
     sum -= 2147483647;
 }
 else
     carry = 0;
    }
}
