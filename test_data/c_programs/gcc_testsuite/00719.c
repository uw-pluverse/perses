


__attribute__((visibility("protected")))
int n_common;

__attribute__((weak, visibility("protected")))
int n_weak_common;

__attribute__((visibility("protected")))
int n_init = -1;

__attribute__((weak, visibility("protected")))
int n_weak_init = -1;

int
f1 ()
{

  return n_common;
}

int
f2 ()
{

  return n_weak_common;
}

int
f3 ()
{

  return n_init;
}

int
f4 ()
{

  return n_weak_init;
}
