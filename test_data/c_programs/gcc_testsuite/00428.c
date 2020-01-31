







unsigned long long
func (float a)
{
  const float dfa = a;
  const unsigned int hi = dfa / 0x1p32f;
  const unsigned int lo = dfa - (float) hi * 0x1p32f;
  return ((unsigned long long) hi << (4 * 8)) | lo;
}
