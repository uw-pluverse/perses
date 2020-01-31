

public class InvalidExpression4 {

    interface SAM {
        void m(int i);
    }

    void test() {
        SAM s = (Integer i) -> { }; 
    }
}
