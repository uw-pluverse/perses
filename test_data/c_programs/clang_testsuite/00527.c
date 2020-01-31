int crc32b(int a, char b)
{
        return __builtin_arm_crc32b(a,b);
}
int crc32cb(int a, char b)
{
        return __builtin_arm_crc32cb(a,b);
}
int crc32h(int a, short b)
{
        return __builtin_arm_crc32h(a,b);
}
int crc32ch(int a, short b)
{
        return __builtin_arm_crc32ch(a,b);
}
int crc32w(int a, int b)
{
        return __builtin_arm_crc32w(a,b);
}
int crc32cw(int a, int b)
{
        return __builtin_arm_crc32cw(a,b);
}
int crc32d(int a, long b)
{
        return __builtin_arm_crc32d(a,b);
}
int crc32cd(int a, long b)
{
        return __builtin_arm_crc32cd(a,b);
}
