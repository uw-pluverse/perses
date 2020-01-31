




extern float fminf (float, float);

void test(int a, float *b, int n)
{
    if (n < 10) {
        *b = a*fminf(0.0,1.0*a);
    }
}
