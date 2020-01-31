

import java.util.List;

class T7177306b {

    <T, S extends List<T>> List<T> m(List<? super T> arg1, S arg2, Class<Object> arg3) { return arg2; }

    void test(List<Integer> li, List<String> ls, Class c) {
        m(li, ls, c);
        
    }
}
