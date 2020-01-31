



public class T7040104 {
    public static void main(String[] args) {
        T7040104 t = new T7040104();
        t.test1();
        t.test2();
        t.test3();
        if (t.npeCount != 3) {
            throw new AssertionError();
        }
    }

    int npeCount = 0;

    void test1() {
        Object a[];
        try {
            Object o = (a = null)[0];
        }
        catch (NullPointerException npe) {
            npeCount++;
        }
    }

    void test2() {
        Object a[][];
        try {
            Object o = (a = null)[0][0];
        }
        catch (NullPointerException npe) {
            npeCount++;
        }
    }

    void test3() {
        Object a[][][];
        try {
            Object o = (a = null)[0][0][0];
        }
        catch (NullPointerException npe) {
            npeCount++;
        }
    }
}
