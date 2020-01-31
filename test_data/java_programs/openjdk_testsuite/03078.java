

class TargetType14 {

    interface SAM<X> {
        X m(int i, int j);
    }

    static void test() {
        SAM<Integer> s1 = (i, j) -> i + j;
        m((i, j) -> i + j);
        SAM<Integer> s2 = m2((i, j) -> i + j); 
        SAM<Integer> s3 = m2((i, j) -> "" + i + j); 
    }

    static void m(SAM<Integer> s) { }
    static <X> SAM<X> m2(SAM<X> s) { return null; }
}
