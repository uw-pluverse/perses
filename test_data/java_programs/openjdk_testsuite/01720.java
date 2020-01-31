
import java.util.List;

class Neg09 {
    interface I {
        default List<String> m() { return null; }
    }

    static class C1 {
        public List m() { return null; } 
    }

    static class C2 extends C1 implements I { }

    static class C3 implements I {
        public List m() { return null; } 
    }
}
