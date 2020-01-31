


import java.util.*;

class TargetType20 {

    interface SAM2<X> {
      List<X> f();
    }

    class Test {
       <Z> void call(SAM2<Z> x, SAM2<Z> y) { }
       { call(() -> Collections.emptyList(), () -> new ArrayList<String>()); }
    }
}
