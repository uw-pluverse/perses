



class T6586091 {
    static class A<T extends A<?>> {}
    static class B extends A<A<?>> {}

    A<A<?>> t = null;
    B c = (B)t;
}
