



@interface D {
    int value() default 2;
}

@interface T {
    int[] a();
    D[] b();
}

@interface U {
    T[] value();
}

@T(a=3, b=@D(12))
@U(@T(a=14, b=@D()))
class X {
}
