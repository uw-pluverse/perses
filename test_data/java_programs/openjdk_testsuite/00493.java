

class T6910550e {
    static class Pair<X,Y> {}

    <X> void m(Pair<X,X> x) {}
    <X,Y> void m(Pair<X,Y> y) {}

   { m(new Pair<String,String>());
     m(new Pair<String,Integer>()); }
}
