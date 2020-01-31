

import java.util.List;

class T7177306e {

    <Z, U extends List<Z>> void m(List<U> lu) { }

    void test(List<List<?>> llw) {
       m(llw);
    }
}
