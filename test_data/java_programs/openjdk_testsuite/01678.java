



package ThrowsIntersection_1;

class Ex1 extends Exception {}
class Ex2 extends Exception {}

interface a {
  int m1() throws Ex1;
}

interface b {
  int m1() throws Ex2;
}


abstract class c1 implements a, b {}
abstract class c2 implements b, a {}

class d extends c1 {
  public int m1() {
    return 1;
  }
}

class e extends c2 {
  public int m1() {
    return 1;
  }
}
