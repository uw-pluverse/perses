



class LambdaConv22<U> {

    interface Factory<T> { T make(); }

    U make() { return null; }

    void test(U u) {
        Factory<U> fu1 = () -> u;
        Factory<U> fu2 = this::make;
    }
}
