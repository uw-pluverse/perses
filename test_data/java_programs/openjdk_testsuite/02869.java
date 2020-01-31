
class BadNestedLambda {
    void test() {
        Runnable add = (int x) -> (int y) -> x + y;
    }
}
