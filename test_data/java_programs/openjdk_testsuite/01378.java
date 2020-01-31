




import java.io.*;

class TryResourceNotSupported {
    void m() {
        try (Writer out = new StringWriter()) {
            out.println("Hello World");
        }
    }
}
