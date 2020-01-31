



import java.util.ArrayList;
import java.util.List;

public class RelaxedArrays {
    static class StringList extends ArrayList<String> {
    }

    static <T> T select(T... tl) {
        return tl.length == 0 ? null : tl[tl.length - 1];
    }

    public static void main(String[] args) {
        List<String>[] a = new StringList[20];
        if (select("A", "B", "C") != "C") throw new Error();
    }
}
