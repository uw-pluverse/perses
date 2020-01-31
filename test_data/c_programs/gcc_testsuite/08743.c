


int array[100];

int t(int);

static int
i_can_be_propagated_fully (int *a)
{
  int i;
  for (i=0;i<50;i++)
  {
    t(a[i]);
    t(a[i+1]);
    t(a[i+2]);
    t(a[i+3]);
  }
}
static int
i_can_be_propagated_fully2 (int *a)
{
  i_can_be_propagated_fully (a);
  i_can_be_propagated_fully (a);
  i_can_be_propagated_fully (a);
}
static int
i_can_not_be_propagated_fully (int *a)
{
  int i;
  for (i=0;i<50;i++)
  {
    t(a[i]);
    t(a[i+1]);
    t(a[i+2]);
    t(a[i+3]);
  }
}
int
i_can_not_be_propagated_fully2 (int *a)
{
  i_can_not_be_propagated_fully (a);
  i_can_not_be_propagated_fully (a);
  i_can_not_be_propagated_fully (a);
}
int
main()
{
  i_can_be_propagated_fully2 (array);
  i_can_be_propagated_fully2 (array);
  i_can_not_be_propagated_fully2 (array);
  i_can_not_be_propagated_fully2 (array);
}
