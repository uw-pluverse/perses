




interface Comparable<T> { }
interface List<E> { }
class Comparator<T> { }

class Collections {
    public static <T extends Object & Comparable<T>>
    int binarySearch(List<T> list, T key) {
        throw new Error();
    }
    public static <T>
    int binarySearch(List<T> list, T key, Comparator<T> c) {
        throw new Error();
    }
}



class Record implements Comparable { }
class T {
    public static void main(String[] arg) {
        List records = null;
        Record x = null;
        int result = Collections.binarySearch(records, x);
    }
}
