int test1()
{
  int x = 6;
  int y = x/2;
  int z;
  while(y > 0) {
    if(y < x) {
      x = x/y;
      y = y-1;
    }else{
      z = x - y;
    }
    x = x - 1;
    x = x - 1;
  }
  z = x+y;
  z = 3;
  return 0;
}
int test2()
{
  int x,y,z;
  x = 10; y = 100;
  if(x > 0){
    y = 1;
  }else{
    while(x<=0){
      x++;
      y++;
    }
  }
  z = y;
  return 0;
}
int test3()
{
  int x,y,z;
  x = y = z = 1;
  if(x>0) {
    while(x>=0){
      while(y>=x) {
        x = x-1;
        y = y/2;
      }
    }
  }
  z = y;
  return 0;
}
int test4()
{
  int y = 3;
  while(y > 0) {
    if(y < 3) {
      while(y>0)
        y ++;
    }else{
      while(y<10)
        y ++;
    }
  }
  return 0;
}
int test5()
{
  int x,y,z,a,b,c;
  x = 1;
  y = 2;
  z = 3;
  a = 4;
  b = 5;
  c = 6;
  if ( x < 10 ) {
     if ( y < 10 ) {
        if ( z < 10 ) {
           x = 4;
        } else {
           x = 5;
        }
        a = 10;
     } else {
       x = 6;
     }
     b = 10;
  } else {
    x = 7;
  }
  c = 11;
  return 0;
}
