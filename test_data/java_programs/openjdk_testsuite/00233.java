

class Neg06 {

   static class CSuperFoo<X> {}
   static class CFoo<X extends Number> extends CSuperFoo<X> {}

   CSuperFoo<String> csf1 = new CFoo<>();
}
