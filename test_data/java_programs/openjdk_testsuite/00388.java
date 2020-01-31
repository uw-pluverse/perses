



class T8034147 {
    static class One<X extends Two<? super X>> {}
    static class Two<Y extends Three<? extends Y>> implements Three<Y> {}
    interface Three<Z> {}
}
