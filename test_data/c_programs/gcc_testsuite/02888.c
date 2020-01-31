typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

f(m)
{
  int i,s=0;
  for(i=0;i<m;i++)
    s+=i;
  return s;
}

main()
{
  exit (0);
}
