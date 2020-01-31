



import java.util.ArrayList;
import java.io.IOException;

public class AnonymousSubclassTest {
    public static void main(String... args) throws Exception {
        new AnonymousSubclassTest().run();
    }

    
    
    final String foo =
        "public class Foo {" +
        "  void m() { Foo f = new Foo() {}; }" +
        "}";

    
    
    
    
    final String test1 =
        "public class Test1 {" +
        "  void m() {"+
        "    Foo f1 = new Foo();"+
        "    Foo f2 = new Foo$1(f1) {};"+
        "  }" +
        "}";

    final String test2 =
        "public class Test2 {" +
        "  class T extends Foo$1 {" +
        "    public T(Foo f) { super(f); }" +
        "  }"+
        "}";

    void compOk(String code) throws Exception {
        ToolBox.javac(new ToolBox.JavaToolArgs().setSources(code));
    }

    void compFail(String code) throws Exception {
        ArrayList<String> errors = new ArrayList<>();
        ToolBox.JavaToolArgs args = new ToolBox.JavaToolArgs();
        args.setSources(code)
            .appendArgs("-cp", ".", "-XDrawDiagnostics")
            .set(ToolBox.Expect.FAIL)
            .setErrOutput(errors);
        ToolBox.javac(args);

        if (!errors.get(0).contains("cant.inherit.from.anon")) {
            System.out.println(errors.get(0));
            throw new Exception("test failed");
        }
    }

    void run() throws Exception {
        compOk(foo);
        compFail(test1);
        compFail(test2);
    }
}
