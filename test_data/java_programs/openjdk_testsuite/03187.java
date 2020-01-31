
class TargetType04 {

    interface S<X extends Number, Y extends Number> {
       Y m(X x);
    }

    S<Integer, Integer> s1 = i -> { return i; }; 
    S<Double, Integer> s2 = i -> { return i; }; 
    S<Integer, Double> s3 = i -> { return i; }; 
}
