



class Test<T,E> {
    public void check(T val){
        System.out.println("Second check method being called");
    }
    public E check(E val){
        System.out.println("First check method being called");
        return null;
    }
 }

class Test3 extends Test<String,String> { }

class ParametericMethodsTest3 {
      public void assertion2() {
            Test3 tRef = new Test3();
            tRef.check("");
      }
 }
