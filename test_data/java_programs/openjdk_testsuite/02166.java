



class T6881645 {
   Object o = new Object() {
       <Z> void m (Class<Z> x) {}
       void test() {
           m((Class)null);
       }
   };
}

