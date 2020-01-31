



class Superclass {
  public Superclass() throws java.io.IOException {}
}

class Subclass extends SuperclassConstructorException {}

class SuperclassConstructorException {

  public static void main(String args[]) {
    try {
      Object x = new Superclass(){};
      Object y = new Subclass();
    } catch (java.io.IOException e) {};
  }
}
