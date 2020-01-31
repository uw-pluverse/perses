



package ThrowsIntersection_4;



class Ex1 extends Exception {}
class Ex2 extends Exception {}

interface a {
  int m1() throws Ex1;
}

interface b {
  int m1() throws Ex2;
}


abstract class c implements a, b {}


class d extends c  {
  public int m1() throws Ex1 {
    return 1;
  }
}
