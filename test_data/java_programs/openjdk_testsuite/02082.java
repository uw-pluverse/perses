



class UplevelFromAnonInSuperCall {
  int x;
  class Dummy {
     Dummy(Object o) {}
  }
  class Inside extends Dummy {
    Inside() {
       super(new Object() { int r = x; });
    }
  }
}
