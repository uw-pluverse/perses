



public class SuperMeth {
  public static void main(String[] ignore) {
    int h = new Outer().hashCode();
  }
}

class Outer {
    Inner inner = new Inner();
    class Inner {
        public int hashCode() { return Outer.super.hashCode(); }
    }
    public int hashCode() { return inner.hashCode(); }
}
