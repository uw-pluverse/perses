

public class LambdaTest2_neg1 {

    public static void main(String[] args) {
        LambdaTest2_neg1 test = new LambdaTest2_neg1();
        
        test.methodQooRoo((Integer i) -> { });
    }

    void methodQooRoo(QooRoo<Integer, Integer, Void> qooroo) { }
}
