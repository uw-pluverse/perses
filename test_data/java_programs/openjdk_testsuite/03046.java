

interface B {
   default String u() { return "B"; }
   default String name() {
      SAM s = ()->u()+"B";
      return s.m();
   }
}
