

public class LambdaTest1_neg2 {
    static void method() {
        ((Runnable)
            ()-> {
                Object o = this; 
            }
        ).run();
    }
}
