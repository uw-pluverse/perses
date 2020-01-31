



import java.util.ArrayList;
import java.util.List;

public class T6500701 {

    private static void test() {
        List list = new ArrayList();
        list.add("");
        List<Integer> aList = new ArrayList<Integer>();
        aList.addAll(list);
        for (Object a : aList) {
            System.out.println(a);
        }
    }

    public static void main(String[] args) {
        test();
    }
}
