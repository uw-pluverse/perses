


unsigned f1 (unsigned x, unsigned z)
{
    unsigned y = x + z;
    y = y + x;
    y = y + x;
    y = y + x;
    y = y + x;
    y = y + x;
    y = y + x;
    return y;
}



unsigned f2 (unsigned x, unsigned z)
{
    unsigned y = x + z;
    y = y + x;
    y = y + x;
    y = y + x;
    y = y + z;
    y = y + z;
    y = y + z;
    y = y + z;
    return y;
}




unsigned f3 (unsigned x, unsigned z, unsigned k)
{
    unsigned y = x + z;
    y = y + x;
    y = y + z;
    y = y + z;
    y = y + k;
    return y;
}




unsigned f4 (unsigned x, unsigned z, unsigned k)
{
    unsigned y = k + x;
    y = y + z;
    y = y + z;
    y = y + z;
    y = y + z;
    y = y + z;
    y = y + z;
    y = y + z;
    y = y + z;
    return y;
}


unsigned f5 (unsigned x, unsigned y, unsigned z)
{
    return x + y + y + y + y + y + y + z + z + z + z + z + z + z + z + z;

}
