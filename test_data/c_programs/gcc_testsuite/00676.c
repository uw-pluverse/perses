


void
func_leaf (void)
{
  int a = 0;
}

void
func_no_leaf (void)
{
  int a = 0;
  func_leaf ();
}

void
func1 (void)
{
  int a = 0;
  func_no_leaf ();
}





__attribute__ ((optimize("no-omit-frame-pointer")))
void
func2 (void)
{
  int a = 0;
  func_no_leaf ();
}

void
func3 (void)
{
  int a = 0;
  func_no_leaf ();
}
