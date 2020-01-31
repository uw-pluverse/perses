

class T6557182 {

    <T extends Number & Comparable<String>> void test1(T t) {
        Comparable<Integer> ci = (Comparable<Integer>) t;
    }

    <T extends Number & Comparable<? extends Number>> void test2(T t) {
        Comparable<Integer> ci = (Comparable<Integer>) t;
    }
}
