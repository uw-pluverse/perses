



import java.io.*;

public class NewBeforeOuterConstructed extends PrintStream {
      private class NullOutputStream extends OutputStream {
              public NullOutputStream() {
                      super();
              }
              public void write(int b) { }
              public void write(byte b[]) { }
              public void write(byte b[], int off, int len) { }
              public void flush() { }
              public void close() { }
      }
       public NewBeforeOuterConstructed() {
                
                
                
                
              super(new NullOutputStream());
      }
}
