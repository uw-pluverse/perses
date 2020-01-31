



import java.util.Iterator;

public class Foreach implements Iterable<Integer> {

    public Iterator<Integer> iterator() {
        return new Iterator<Integer>() {
            int next = 1;
            public boolean hasNext() {
                return next <= (1 << 12);
            }
            public void remove() {
                throw new UnsupportedOperationException();
            }
            public Integer next() {
                try {
                    return new Integer(next);
                } finally {
                    next <<= 1;
                }
            }
        };
    }

    public static void main(String[] args) {
        int sum;

        sum = 0;
        int[] a = new int[12];
        for (int i=0; i<12; i++) a[i] = 1<<i;
        for (int i : a) {
            if (i > 400) break;
            if (i == 16) continue;
            sum += i;
        }
        if (sum != 495)
            throw new AssertionError("cogito ergo " + sum);

        sum = 0;
        Iterable<Integer> x = new Foreach();
        for (Integer j : x)
            sum += j.intValue();
        if (sum != 8191)
            throw new AssertionError("cogito ergo " + sum);

        System.out.println("success!");
    }
}
