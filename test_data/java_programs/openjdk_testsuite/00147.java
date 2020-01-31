

import java.util.List;

class T8015505 {

    <Z> List m() { return null; }

    void test() {
        List<?> l = m();
    }
}
