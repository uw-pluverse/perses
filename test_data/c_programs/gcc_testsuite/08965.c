


typedef _Atomic int AT1;


void
foo (void)
{
  _Atomic AT1 x1;
  _Atomic _Atomic int x2;
  AT1 _Atomic x3;
  _Atomic int _Atomic x4;
  _Atomic int _Atomic x5;
}

void a1(_Atomic AT1 t) { }
void a2(_Atomic _Atomic int t) { }
void a3(AT1 _Atomic t) { }
void a4(_Atomic int _Atomic t) { }
void a5(_Atomic int _Atomic t) { }

typedef _Atomic AT1 AAT1;
typedef _Atomic _Atomic int AAT2;
typedef AT1 _Atomic AT1A;
typedef _Atomic int _Atomic AT2A;
typedef _Atomic int _Atomic AIA;
