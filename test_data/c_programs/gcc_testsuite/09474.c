







int __attribute__((weak, visibility("hidden"))) weak_hidden[3];

int *f_weak_hidden ()
{
  return weak_hidden;
}
