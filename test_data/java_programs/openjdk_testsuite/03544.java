



import java.io.IOException;
import java.io.OutputStream;

public class T7032633 {
    void test() throws IOException {
        try (OutputStream out = System.out) {
            out.flush();
        }
    }
}
