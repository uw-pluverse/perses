



public class T7040883 {

    <Z> Z[] getListeners(Class<Z> z) { return null; }

    void test(String s) {
        int i = getListeners(s.getClass()).length;
    }
}
