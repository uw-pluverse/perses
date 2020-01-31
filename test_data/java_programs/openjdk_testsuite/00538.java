



package cast.crash;

import java.util.*;

interface SN extends Set<Number>{}
interface LI extends List<Integer>{}

class CastCrash {
    void f(LI l) {
        SN sn = (SN) l;
    }
}
