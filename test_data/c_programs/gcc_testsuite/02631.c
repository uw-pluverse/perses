static int strcmp(){return-1;}

main()
{
if(__builtin_strcmp("X","X\376")>=0)abort();
exit(0);
}
