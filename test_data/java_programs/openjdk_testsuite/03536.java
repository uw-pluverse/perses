



import java.io.File;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.List;

class T7178324 {
    public static void main(String[] args) throws Exception {
        List<File> files = new ArrayList<>();
        for (File f : files)
            try (FileInputStream is = new FileInputStream(f)) {
        }
    }
}
