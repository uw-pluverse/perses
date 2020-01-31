



import java.util.*;

public class ParenVerify {

    public static void main(String argss[]) {
        for(Iterator<Integer> i  = test("Foo"); i.hasNext(); )
            System.out.println(i.next());
    }
    static HashMap<String, LinkedList<Integer>> m
        = new HashMap<String, LinkedList<Integer>>();

    public static Iterator<Integer> test(String s) {
        LinkedList<Integer> lst = new LinkedList<Integer>();
        lst.add(new Integer(12));
        m.put("Hello", lst);

        
        
        
        lst = (m.get("Hello"));
        return lst.iterator();
    }
}
