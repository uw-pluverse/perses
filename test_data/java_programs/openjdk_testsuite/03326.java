



import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class LambdaTest1 {
    public static void main(String[] args) {

        LambdaTest1 test = new LambdaTest1();

        test.method2((int n) -> { });
        test.method2((int n) -> { });
        test.method2((int n) -> { return; }); 
        test.method2((int n) -> { System.out.println(n); }); 
        test.method2(n -> { System.out.println(n); }); 

        test.method3(()-> { System.out.println("implementing VoidVoid.vvMethod()"); });
        test.method3(() -> {});

        test.method4(()-> 42);
        test.method4(()-> { return 42; });

        test.method5((int n)-> n+1);
        test.method5((int n) -> 42);
        test.method5((int n) -> { return 42; });
        test.method5(
            (int n) -> { 
                if(n > 0)
                    return n++;
                else
                    return n--;
            }
        );

        Runnable r = ()-> { System.out.println("Runnable.run() method implemented"); };
        r.run();
        ((Runnable)()-> { System.out.println("Runnable.run() method implemented"); }).run();
    }

    void method2(VoidInt a) {
        System.out.println("method2()");
        final int N = 1;
        int n = 2; 
        System.out.println("method2() \"this\":" + this);
        ((Runnable)
            ()->{
                System.out.println("inside lambda \"this\":" + this);
                System.out.println("inside lambda accessing final variable N:" + N);
                System.out.println("inside lambda accessing effectively final variable n:" + n);
            }
        ).run();
        
        a.viMethod(2);
    }

    void method3(VoidVoid a) {
        System.out.println("method3()");
        a.vvMethod();
    }

    void method4(IntVoid a) {
        System.out.println("method4()");
        System.out.println(a.ivMethod());
    }

    void method5(IntInt a) {
        System.out.println("method5()");
        System.out.println(a.iiMethod(5));
    }


    
    interface VoidInt {
        void viMethod(int n);
    }

    interface VoidVoid {
        void vvMethod();
    }

    interface IntVoid {
        int ivMethod();
    }

    interface IntInt {
        int iiMethod(int n);
    }
}
