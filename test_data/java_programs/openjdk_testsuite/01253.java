




class IncompatibleTypes1<V> {
    <T> IncompatibleTypes1<Integer> m() {
        return null;
    }

    IncompatibleTypes1<? extends String> o = m();
}
