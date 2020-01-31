



interface SAM {
    int m();
}

interface SuperI {
    public default int foo() { return 1234; }
}

interface I extends SuperI {
}

interface T extends I {
    public default SAM boo() { return I.super::foo; }
}

public class IllegalBridgeModifier {
    public static void main(String argv[])throws Exception {
        T t = new T(){};
        if (t.boo().m() != 1234) {
            throw new Exception("Failed test");
        }
    }
}
