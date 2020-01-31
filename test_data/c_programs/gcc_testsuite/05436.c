



extern int rand(void);

int get_data_for (int id)
{
  return rand();
}

int my_id;

int main()
{
  int res = get_data_for (my_id);
  switch (res)
    {
      case 0:
   return 666;
      default:
   return -1;
    }
}
