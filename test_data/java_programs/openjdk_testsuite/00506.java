



class Comparator<T> {}
class Arrays {
    public static <U, T extends U> void sort(T[] a, Comparator<U> c) {
        throw new Error();
    }
}

class JSR14Bug {
    public static void main(String[] args) {
        Object[] oa = null;
        Arrays.sort(oa, new Comparator() {});
    }
}
