


struct bovid
{
  float red;
  int green;
  void *blue;
};

static int
__attribute__((noinline))
ox (struct bovid *cow)
{
  cow->red = cow->red + cow->green + cow->green;
  return 0;
}

int something;

static int
__attribute__((noinline))
ox_improved (struct bovid *calf)
{
  if (something > 0)
    calf->red = calf->red + calf->green;
  else
    calf->red = calf->green + 87;
  something = 77;
  return 0;
}


int main (int argc, char *argv[])
{
  struct bovid cow;

  cow.red = 7.4;
  cow.green = 6;
  cow.blue = &cow;

  ox (&cow);

  ox_improved (&cow);
  return 0;
}
