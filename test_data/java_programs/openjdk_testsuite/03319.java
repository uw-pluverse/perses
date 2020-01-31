

public class LambdaTest1_neg3 {
    void method() {
        int n = 2; 
        ((Runnable)
            ()-> {
                int n2 = n; 
            }
        ).run();
        n++; 
    }
}
