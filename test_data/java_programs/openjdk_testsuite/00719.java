
package test;

import java.lang.annotation.*;
import static test.TestGetElementReferenceData.Sub.*;

public class TestGetElementReferenceData {

    private static void test() {
        StringBuilder sb = new StringBuilder();
        sb.append(0);
        sb.reverse( );
        java.util.List<  String> l;
        utility();
        target(TestGetElementReferenceData :: test);
    }
    private static void target(Runnable r) { r.run(); }
    public static class Base {
        public static void utility() {}
    }
    public static class Sub extends @TypeAnnotation( ) Base {
    }
   @Deprecated( )
    public static class TypeParam<TT> {
    }
    @Target(ElementType.TYPE_USE)
    @interface TypeAnnotation {
    }
}
