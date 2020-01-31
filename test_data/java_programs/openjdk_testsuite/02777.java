



public class NullQualifiedNew {

  class Nested {
    int j;
    Nested(int i){ j = i;}
  }

  public static void main(String[] args) {
    NullQualifiedNew e = null;
    e.new Nested(6);
  }

}
