



import com.sun.tools.javac.util.List;
import com.sun.tools.javac.util.ListBuffer;
import java.util.Iterator;
import java.util.Objects;

public class ListBufferTest {
    public static void main(String... args) {
        testRemove();
        testCopiedEndsWithList_nil();
    }

    private static void testCopiedEndsWithList_nil() {
        ListBuffer<String> lb = new ListBuffer<>();

        lb.add("a");
        lb.add("b");
        lb.add("c");

        List<String> l1 = lb.toList();

        assertListEquals(l1, "a", "b", "c");
        assertEndsWithNil(l1);

        lb.add("d");

        List<String> l2 = lb.toList();
        assertListEquals(l2, "a", "b", "c", "d");
        assertEndsWithNil(l2);
        assertListEquals(l1, "a", "b", "c");
    }

    private static void testRemove() {
        ListBuffer<String> lb1 = new ListBuffer<>();

        lb1.add("a");
        lb1.add("b");
        lb1.add("c");

        assertListEquals(lb1.toList(), "a", "b", "c");
        assertEquals(lb1.next(), "a");
        assertListEquals(lb1.toList(), "b", "c");
        assertEquals(lb1.next(), "b");
        assertListEquals(lb1.toList(), "c");
        assertEquals(lb1.next(), "c");
        assertListEquals(lb1.toList());
        assertEquals(lb1.next(), null);

        lb1.add("d");

        assertEquals(lb1.next(), "d");
    }

    private static void assertEndsWithNil(List<?> list) {
        while (!list.isEmpty()) {
            list = list.tail;
        }

        if (list != List.nil()) throw new IllegalStateException("Not ending with List.nil()");
    }

    private static <T> void assertListEquals(Iterable<T> list, T... data) {
        int i = 0;
        Iterator<T> it = list.iterator();

        while (it.hasNext() && i < data.length) {
            assertEquals(it.next(), data[i++]);
        }

        if (it.hasNext()) {
            throw new IllegalStateException("Too many elements in the list");
        }

        if (i < data.length) {
            throw new IllegalStateException("Too few elements in the list");
        }
    }

    private static void assertEquals(Object expected, Object actual) {
        if (!Objects.equals(expected, actual)) {
            throw new IllegalStateException("Incorrect content. Expected: " + expected + ", actual: " + actual);
        }
    }
}
