





int tf = 1;

void f(int x, unsigned int y)
{



  x > (tf?64:(tf!=x));
  y > (tf?64:(tf!=x));
  x > (tf?(tf!=x):64);
  y > (tf?(tf!=x):64);

  x > (tf?64:(tf==x));
  y > (tf?64:(tf==x));
  x > (tf?(tf==x):64);
  y > (tf?(tf==x):64);

  x > (tf?64:(tf>x));
  y > (tf?64:(tf>x));
  x > (tf?(tf>x):64);
  y > (tf?(tf>x):64);

  x < (tf?64:(tf<x));
  y < (tf?64:(tf<x));
  x < (tf?(tf<x):64);
  y < (tf?(tf<x):64);

  x > (tf?64:(tf>=x));
  y > (tf?64:(tf>=x));
  x > (tf?(tf>=x):64);
  y > (tf?(tf>=x):64);

  x > (tf?64:(tf<=x));
  y > (tf?64:(tf<=x));
  x > (tf?(tf<=x):64);
  y > (tf?(tf<=x):64);

  x > (tf?64:(tf&&x));
  y > (tf?64:(tf&&x));
  x > (tf?(tf&&x):64);
  y > (tf?(tf&&x):64);

  x > (tf?64:(tf||x));
  y > (tf?64:(tf||x));
  x > (tf?(tf||x):64);
  y > (tf?(tf||x):64);

  x > (tf?64:(!tf));
  y > (tf?64:(!tf));
  x > (tf?(!tf):64);
  y > (tf?(!tf):64);

}
