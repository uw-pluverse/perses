




enum _eq_bool
{
  false,
  true
} __attribute__((mode (byte)));

typedef enum _eq_bool bool;

bool foo (void);
bool bar (void);

bool test (void)
{
  return foo () || bar ();
}
