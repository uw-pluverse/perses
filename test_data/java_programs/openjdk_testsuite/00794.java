



import static javax.tools.StandardLocation.CLASS_PATH;

public class T6415780 extends ToolTester {
    void test() {
        System.out.println(fm.getClassLoader(CLASS_PATH).toString()); 
    }

    public static void main(String... args) {
        T6415780 tester = new T6415780();
        tester.test();
    }
}
