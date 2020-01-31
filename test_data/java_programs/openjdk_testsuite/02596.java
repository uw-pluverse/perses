



import java.lang.annotation.ElementType;
import java.lang.annotation.Target;

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER })
@interface Advanced {}

class U {}
interface I {}

class ErasureTest {
     <T extends U & @Advanced I> void TestMethod(T arg1) { }
    public static void main(String argv[]) {
        ErasureTest t1 = new ErasureTest(){
            public <T extends @Advanced U & I> void TestMethod(T arg1) { }
        };

        ErasureTest t2 = new ErasureTest(){
            public <T extends U & @Advanced I> void TestMethod(T arg1) { }
        };
    }
}
