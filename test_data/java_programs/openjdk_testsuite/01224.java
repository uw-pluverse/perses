



import java.io.*;

class ResourceMayNotBeAssigned {
    void m(File f) {
        try (Writer out = new StringWriter()) {
            out = null;
        }
    }
}
