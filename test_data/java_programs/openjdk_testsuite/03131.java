



public class SelfInitializerInLambdaTestb {

    final Runnable r1;

    final Runnable r2 = ()-> System.out.println(r1);

    SelfInitializerInLambdaTestb() {
        r1 = ()->System.out.println(r1);
    }
}
