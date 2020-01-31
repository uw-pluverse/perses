

interface C {
   default String u() { return "C"; }
   default String name() {
      SAM s = ()->u()+"C";
      return s.m();
   }
}
