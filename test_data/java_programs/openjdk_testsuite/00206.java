



class Super<X,Y> {
    private Super(Integer i, Y y, X x) {}
    public Super(Number n, X x, Y y) {}
}

class Test {
    Super<String,Integer> ssi1 = new Super<>(1, "", 2);
}
