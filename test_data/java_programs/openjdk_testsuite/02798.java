

import java.io.IOException;

class T6199153 {

    static class A {
        public <T extends IOException> void m() throws T {}
    }

    static class B extends A {
        public void m() throws IOException {}
    }
}

