


typedef struct
{
  int data16;
}
list_data;
void
fn1 (list_data * p1)
{
    p1->data16 = p1->data16 & 1 & p1->data16 >> 1;
}
