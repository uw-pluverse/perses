

public class EffectivelyFinal_neg {

    void test() {
        String s = "a";
        String s2 = "a";
        int n = 1;
        ((Runnable)
            ()-> {
                s2 = "b"; 
                System.out.println(n);
                System.out.println(s);
                s = "b"; 
            }
        ).run();
        n = 2; 
    }
}
