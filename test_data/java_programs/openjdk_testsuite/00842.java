

public class UnresolvableClassNPEInAttrTest {
    public static void main(String[] args) {
        new Undefined() {
            void test() {
                new Object() {};
            }
        };
    }
}
