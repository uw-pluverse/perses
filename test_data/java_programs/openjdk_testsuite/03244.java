

import java.util.Comparator;

public class InvalidExpression3 {

    void test() {
        Comparator<Integer> c2 = (Integer i1, Integer i2) -> { return "0"; }; 
    }
}
