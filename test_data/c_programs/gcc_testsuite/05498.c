

int
foo2 (distance, i, j)
     int distance;
     int i, j;
{
 int t = distance;
 if (t <= 0)
   t = ((t) >= 0 ? (t) : -(t));
 return t;
}
