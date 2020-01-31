



@interface Anno {
    String value();
}

class B {
    @Anno(value=A.a)
    public static final int b = 0;
}

class A {
    @Deprecated
    public static final String a = "a";
}
