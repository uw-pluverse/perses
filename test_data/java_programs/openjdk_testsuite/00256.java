



class NumberList<T extends Number> {}

class Test {
    <Y extends Number> void m() {
        static class Y {}
        class Y1<S extends NumberList<Y>> {}
    }
}
