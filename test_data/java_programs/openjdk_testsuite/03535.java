

import java.io.*;

class T7022711 {
    public static void main (String args[]) throws Exception {
        try (DataInputStream is = new DataInputStream(new FileInputStream("x"))) {
            while (true) {
                is.getChar();  
            }
        } catch (EOFException e) {
        }
    }
}

