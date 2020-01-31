




import java.io.*;

class ResourceNotReferenced {
    void m() throws IOException {
        try (Writer out = new StringWriter()) {
        }
    }
}
