

public class ErrorMessageTest {
    void f(Runnable r) {
        f(() -> { f(new MISSING() { public void run() {} }); });
    }
}
