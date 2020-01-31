

extern void abort (void);

int arr[4][4] = {{0, 1, 1, -1}, {-1, -1, 1, -1}, {1, -1, 1, 1}, {1, -1, -1, 0}};
long long
foo ()
{
  long long ll = 0;
  ll += arr[1][0];
  ll += arr[1][1];
  return ll;
}
