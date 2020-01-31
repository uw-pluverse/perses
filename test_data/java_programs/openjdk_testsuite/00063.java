


import java.util.List;

class T8058511c {
    void test(List<? extends double[]> l) {
        (true ? l.get(0) : l.get(0)).toString();
    }
}
