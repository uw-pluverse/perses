




void maskdata (int * data, int len)
{
   int i = len;
   for (; i > 0; i -= 2)
    {
      data[i] &= 0xff00ff;
      data[i + 1] &= 0xff00ff;
    }
}
