



int glob = 1;

void __attribute__((constructor))
ctor1 ()
{
  glob += 1;
}


void __attribute__((constructor))
ctor2 ()
{
  glob -= 2;
}

int main (int argc, const char **argv)
{
  return glob;
}
