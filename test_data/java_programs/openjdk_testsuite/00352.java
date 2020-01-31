



import java.util.List;
import java.util.ArrayList;

class ArrayTypearg {
    private void foo() {
        List<Object[]> list = new ArrayList<Object[]>();
        Object o1 = list.get(0)[0];
    }
}
