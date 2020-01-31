

interface A {
   default String u() { return "A"; }
   default String name() {
      SAM s = ()->u()+"A";
      return s.m();
   }
}
