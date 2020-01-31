



public class SuperNew4 {
  void foo() {
    class One {
      One(Object o) {}
      One() {
        this(new Object() {
            { new One(null); }
          });
      }
    }
  }
}
