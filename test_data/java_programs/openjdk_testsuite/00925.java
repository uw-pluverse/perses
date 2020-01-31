



import java.util.Iterator;


public class SpecIterable implements Iterable<String> {
    public static void main(String[] args) {
        int i = 0;
        for (String s : new SpecIterable()) {
            if (i++ == 4) break;
            System.out.println(s);
        }
        System.out.println("passed");
    }

    public Iterator<String> iterator() {
        return new Iterator<String>() {
                public void remove() {}
                public boolean hasNext() { return true; }
                public String next() { return "a"; }
            };
    }
}
