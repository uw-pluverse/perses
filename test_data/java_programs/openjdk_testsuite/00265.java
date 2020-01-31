



import java.lang.Comparable;

class A<X extends Number & Comparable<Y>, Y> {
    A<Integer,Integer> a;
    B<Y,X> b;
}
class B<Y, X extends Number & Comparable<Y>> {
    A<X,Y> a;
    B<Short,Short> b;
}
