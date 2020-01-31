



import java.util.*;

public class LambdaConv05 {

    static void assertTrue(boolean cond) {
        if (!cond)
            throw new AssertionError();
    }

    int count = 0;

    void sort(List<String> data) {
      Collections.sort(data,
                       (String a, String b) -> { LambdaConv05.this.count++; return a.length()-b.length(); });
    }

    public static void main(String[] args) {
        ArrayList<String> arr = new ArrayList<>();
        arr.add("Three");
        arr.add("Four");
        arr.add("One");
        LambdaConv05 sorter = new LambdaConv05();
        sorter.sort(arr);
        assertTrue(arr.get(0).equals("One"));
        assertTrue(arr.get(1).equals("Four"));
        assertTrue(arr.get(2).equals("Three"));
        assertTrue(sorter.count == 2);
    }
}
