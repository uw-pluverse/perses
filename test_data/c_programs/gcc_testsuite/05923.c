


float f1_float (float x, float z)
{
    float y = x + z;
    y = y + x;
    y = y + x;
    y = y + x;
    y = y + x;
    y = y + x;
    y = y + x;
    y = y + x;
    return y;
}

float f1_float2 (float x)
{
    float y = x + 3 * x + x;
    return y;
}

int f1_int (int x)
{
    int y = x + 4 * x + x;
    return y;
}
