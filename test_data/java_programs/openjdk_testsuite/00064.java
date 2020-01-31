


class T8058511a {
    <Z> void choose(Z z1, Z z2) { }

    void test(Class<Double> cd, Class<? extends double[]> cdarr) {
        choose(cd, cdarr);
    }
}
