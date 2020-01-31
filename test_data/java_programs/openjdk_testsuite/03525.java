

import java.io.*;

public class ResourceRedecl {

    public void test() {
        
        
        
        try {
        } catch (Exception exParam1) {
            Object exParam1 = new Object();
            try (java.io.FileInputStream exParam1 = new java.io.FileInputStream("foo.txt")) {
                Object exParam1 = new Object();
            } catch (IOException exParam1) {
            }
        }

        
        
        try (java.io.FileInputStream exParam2 = new java.io.FileInputStream("bar.txt")) {
            Object exParam2 = new Object();
            try (BufferedReader br = new BufferedReader(new FileReader("zee.txt"))) {
            } catch (IOException exParam2) {
            }
        } catch (Exception ex) {
        }
    }
}

