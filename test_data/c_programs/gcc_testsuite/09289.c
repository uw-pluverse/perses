


int value_compare ();

int
list_compare (int * list1)
{
  if (list1)
    value_compare ();
}

int func1 (int * f){}

int
value_compare (int * a)
{
    if (a)
        list_compare (a);
}

int
func2 (const int * fb)
{
  func1 ((int *) fb);
}
