



import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class LambdaTest1 {

    private static String assertionStr = "";

    private static void assertTrue(boolean b) {
        if(!b)
            throw new AssertionError();
    }

    private static void test1(Runnable r) {
        r.run();
    }

    void test2(Object o) {
        if(o instanceof Runnable)
            ((Runnable)o).run();
    }

    Runnable test3() {
        return ()-> { assertionStr += "Runnable6"; };
    }

    public static void main(String[] args) {

        
        
        Runnable r = ()-> { assertionStr += "Runnable1 "; };
        r.run();

        
        ((Runnable)()-> { assertionStr += "Runnable2 "; }).run();

        Object o = (Runnable)()-> {};

        o = (Runnable)()-> {
                switch (assertionStr) {
                    case "Runnable1 Runnable2 ":
                        assertionStr += "Runnable3 ";
                        break;
                    default:
                        throw new AssertionError();
                }
                return;
            };

        
        test1(()-> { assertionStr += "Runnable4 "; return; });

        LambdaTest1 test = new LambdaTest1();
        test.test2((Runnable)()-> { assertionStr += "Runnable5 "; });

        
        r = test.test3();
        r.run();

        assertTrue(assertionStr.equals("Runnable1 Runnable2 Runnable4 Runnable5 Runnable6"));

        
        List<Integer> list = new ArrayList<Integer>();
        list.add(4);
        list.add(10);
        list.add(-5);
        list.add(100);
        list.add(9);
        Collections.sort(list, (Integer i1, Integer i2)-> i2 - i1);
        String result = "";
        for(int i : list)
            result += i + " ";
        assertTrue(result.equals("100 10 9 4 -5 "));

        Collections.sort(list,
            (i1, i2) -> {
                String s1 = i1.toString();
                String s2 = i2.toString();
                return s1.length() - s2.length();
             });
        result = "";
        for(int i : list)
            result += i + " ";
        assertTrue(result.equals("9 4 10 -5 100 "));
    }
}
