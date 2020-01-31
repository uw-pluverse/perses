



import java.util.List;
import java.util.ArrayList;

public class ListOfListTest {

    public static void main(String[] argv) {
        List<List<Integer>> ll = new ArrayList<List<Integer>>();
        List<Integer> il = new ArrayList<Integer>();
        ll.add(il);
        il.add(1);
        int sum = 0;
        for (Integer i : ll.get(0)) {
            sum = identity(sum) + i;
        }

        if (sum != 1) throw new Error(""+sum);

        enumsToo();
    }

    static int identity(Integer i) {
        switch (i) {
        case 0: return 0;
        default: return i;
        }
    }

    enum E { a, b, c, d, e };

    static class Box<T> {
        Box(T t) { this.t = t; }
        T t;
        T get() { return t; }
    }

    static void enumsToo() {
        Box<E> box = new Box<E>(E.c);
        switch (box.get()) {
        case a: throw new Error();
        case c: break;
        default: throw new Error();
        }
        Box<Integer> boxi = new Box<Integer>(12);
        switch (boxi.get()) {
        case 0: throw new Error();
        case 12: break;
        default: throw new Error();
        }
    }
}
