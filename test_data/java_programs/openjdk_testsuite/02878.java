


import java.io.Serializable;
import java.util.List;

class Intersection02 {

    interface P<X> { }

    void test(List<String> ls) {
        Object o1 = (List<String> & Serializable)ls;
        Object o2 = (List<String> & Serializable & P<String>)ls;
    }
}
