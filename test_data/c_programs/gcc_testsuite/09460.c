



int
fn1 (int i)
{
  return ({ i; }) == ({ i; });
}

int
fn2 (int i)
{
  return ({ i + 1; }) != ({ i + 1; });
}
