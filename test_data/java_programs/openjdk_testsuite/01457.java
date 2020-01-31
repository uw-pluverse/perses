




import java.io.*;

class ResourceClosed {
    void m() throws IOException {
        try (Writer out = new StringWriter()) {
            out.close();
        }
    }
}
