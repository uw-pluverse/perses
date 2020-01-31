





unsigned int buggy(unsigned int min, unsigned int max)
{
    if (max < 16384) {
        unsigned short num16 = 0;
        num16 = min + (long) ((double) (max - min + 1.0) * (num16 / (65535 + 1.0)));
        return num16;
    }
    return 0;
}
