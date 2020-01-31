



import java.io.*;

class UnreachableCatch1 {

    void test() {
        try {
            if (true) {
                throw new FileNotFoundException();
            }
            else {
                throw new EOFException();
            }
        }
        catch(FileNotFoundException fnf) { }
        catch(EOFException eof) { }
        catch(IOException ex) { } 
    }
}
