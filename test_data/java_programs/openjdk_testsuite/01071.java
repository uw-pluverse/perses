



import com.sun.tools.javac.file.JavacFileManager;

public class TestName {
    public static void main(String... args) {
        final boolean PACKAGE = true;
        final boolean CLASS = true;
        JavacFileManager.testName("", PACKAGE, !CLASS);
        JavacFileManager.testName(".", !PACKAGE, !CLASS);
        JavacFileManager.testName("java.lang.", !PACKAGE, !CLASS);
        JavacFileManager.testName(".java.lang.", !PACKAGE, !CLASS);
        JavacFileManager.testName(".java.lang", !PACKAGE, !CLASS);
        JavacFileManager.testName("java.lang", PACKAGE, CLASS);
        JavacFileManager.testName("java.lang.Foo Bar", !PACKAGE, !CLASS);
        JavacFileManager.testName("java.lang.Foo+Bar", !PACKAGE, !CLASS);
        JavacFileManager.testName("java.lang.Foo$Bar", PACKAGE, CLASS);
        JavacFileManager.testName("Peter.von.der.Ah\u00e9", PACKAGE, CLASS);
    }
}
