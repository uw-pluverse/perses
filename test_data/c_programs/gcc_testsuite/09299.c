






int main()
{
  if (__builtin_strcmp ("ABC" "DEF", "ABCDEF") != 0)
    link_error ();





  if (__builtin_strcmp ("XYZ" "DEF", "XYZDEF") != 0)
    link_error ();



  if (__builtin_strcmp ("ABC" "DEF", "ABCDEF") != 0)
    link_error ();

  return 0;
}
