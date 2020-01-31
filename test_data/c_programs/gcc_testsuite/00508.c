






typedef unsigned char UChar;
typedef unsigned short UShort;
typedef unsigned int UWord;

typedef unsigned long SizeT;
typedef unsigned long Addr;

void *memmove(void *dst, const void *src, SizeT len)
{
  const Addr WS = sizeof(UWord);
  const Addr WM = WS - 1;


  SizeT n = len;
  Addr d = (Addr) dst;
  Addr s = (Addr) src;

  if (((s ^ d) & WM) == 0) {


    while ((s & WM) != 0 && n >= 1) {
      *(UChar *) d = *(UChar *) s;
      s += 1;
      d += 1;
      n -= 1;
    }

    while (n >= WS) {
      *(UWord *) d = *(UWord *) s;
      s += WS;
      d += WS;
      n -= WS;
    }
    if (n == 0)
      return dst;
  }
  if (((s | d) & 1) == 0) {

    while (n >= 2) {
      *(UShort *) d = *(UShort *) s;
      s += 2;
      d += 2;
      n -= 2;
    }
  }

  while (n >= 1) {
    *(UChar *) d = *(UChar *) s;
    s += 1;
    d += 1;
    n -= 1;
  }

  return dst;
}
