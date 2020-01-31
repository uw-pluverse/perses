



import java.util.HashMap;
import java.util.Map;

public class T8068430 {
    public static void main(String[] args) {
        Map<Integer, String> mp = new HashMap<>();
        mp.put(1, "a");
        mp.put(2, "b");
        mp.put(3, "c");
        mp.put(4, "d");
        System.out.println(mp.entrySet().stream().reduce(0,
                (i, e) -> i + e.getKey(),
                (i1, i2) -> i1 + i2));
    }
}
