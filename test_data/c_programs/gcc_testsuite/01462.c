



long long test (unsigned int sec, unsigned long long nsecs)
{
   return (long long)(long)sec * 1000000000L + (long long)(unsigned
   long)nsecs;
}
