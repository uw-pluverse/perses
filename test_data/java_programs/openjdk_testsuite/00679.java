



public class EnclosingAccessCheck extends packone.Mediator {
    public void test() {
        getSecret().greet();
    }

    public static void main(String[] args) {
        new EnclosingAccessCheck().test();
    }
}
