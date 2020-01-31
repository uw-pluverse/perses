


public class CrashLambdaExpressionWithNonAccessibleIdTest {
    void m() {
        m1(()-> {
            new A(){
                public void m11() {}
            };
        });

    }

    void m1(Runnable r) {}
}
