



class VarargsAndWildcardParameterizedTypeTest {
    interface I<T> {
        String m(T... t);
    }

    void m() {
        I<? super Integer> i = null;
        i.m(Integer.valueOf(1), Integer.valueOf(1));
    }
}
