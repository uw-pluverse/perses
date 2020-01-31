







class LambdaBodyNeitherValueNorVoidCompatible {
    interface I {
        String f(String x);
    }

    static void foo(I i) {}

    void m() {
        foo((x) -> {
            if (x == null) {
                return;
            } else {
                return x;
            }
        });
    }
}
