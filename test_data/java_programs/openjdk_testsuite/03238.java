

public class AbstractClass_neg {

    abstract class SAM {
        abstract int m();
    }

    void test() {
        SAM s = ()-> 6;
    }
}
