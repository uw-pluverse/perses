



import java.util.Collection;
import java.util.List;
import java.util.ArrayList;

public class LambdaTest2_SAM3 {
    private static List<String> strs = new ArrayList<String>();
    private static List<Integer> integers = new ArrayList<Integer>();

    public static void main(String[] args) {
        LambdaTest2_SAM3 test = new LambdaTest2_SAM3();

        
        test.methodFooBar(new FooBar() {
                public int getAge(Number n) {
                    System.out.println("getAge(Number n) called");
                    return 100;
                }
                public int getAge(Integer i) {
                    System.out.println("getAge(Integer i) called");
                    return 200;
                }
            }
        );

        
        test.methodDE(new DE(){
                public int getOldest(List<Integer > list) {
                    System.out.println("getOldest(List<Integer> list) called");
                    return 100;
                }
                public int getOldest(Collection<?> collection) {
                    System.out.println("getOldest(Collection<?> collection) called");
                    return 200;
                }
            }
        );

    }

    
    void methodFooBar(FooBar fb) {
        System.out.println("methodFooBar(): interface FooBar object instantiated: " + fb);
        System.out.println("result=" + fb.getAge(new Byte("10")));
        System.out.println("result=" + fb.getAge(new Integer(10)));
    }

    
    void methodDE (DE de) {
        System.out.println("methodDE(): interface DE object instantiated: " + de);
        System.out.println(de.getOldest(integers));
        System.out.println(de.getOldest(strs));
    }
}
