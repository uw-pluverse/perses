



struct node234_Tag
{
  int t1;
  int kids[4];
  void *elems[3];
};

void *add234_internal(struct node234_Tag *n, int ei)
{
  int j;
  for (j = ei; j < 2 && n->elems[j+1];)
    j++;
  n->kids[j+1] = 0;
}
