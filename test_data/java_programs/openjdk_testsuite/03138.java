
import java.util.*;

class MethodReference52 {

    interface Clone1 {
        int[] m();
    }

    interface Clone2 {
        Object m();
    }

    interface WrongClone {
        long[] m();
    }

    interface GetClass {
        Class<? extends List> m();
    }

    interface WrongGetClass {
        Class<List<String>> m();
    }

    void test(int[] iarr, List<String> ls) {
        Clone1 c1 = iarr::clone; 
        Clone2 c2 = iarr::clone; 
        WrongClone c3 = iarr::clone; 
        GetClass c4 = ls::getClass; 
        WrongGetClass c5 = ls::getClass; 
    }
}
