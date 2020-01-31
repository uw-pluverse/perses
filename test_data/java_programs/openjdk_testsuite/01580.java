



class AX1 {
    static class Z {
        Z() {
            throw new Error("WRONG");
        }
    }
}
class AX {
    static class Z {
        Z() {
            System.out.println("correct");
        }
    }
}
class Y extends AX.Z {
    class AX extends AX1 {
    }
}

public class CyclicInheritance4 {
    public static void main(String[] args) {
        new Y();
    }
}
