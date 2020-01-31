



class TargetType18 {

    interface Folder<T> {
        public T fold(T a, T b);
    }


    public static <T> Folder<T> max() {
        return (a, b) -> (((Comparable)a).compareTo(b)<0)? b: a;
    }
}
