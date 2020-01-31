



class FooBar {
    public String toString(){
        return null;
    }
}

public class StringConversion {

    static void check(int testid, String have, String expect)
                throws Exception {
        if ((have == null && have != expect) ||
                (have != null && !have.equals(expect))) {
            String msg =
                "TEST " + testid + ": HAVE \"" +
                have + "\" EXPECT \"" + expect + "\"";
            System.out.println("StringConversion: " + msg);
            throw new Exception(msg);
        }
    }

    public static void main(String[] args) throws Exception {

        String s;
        String n = null;
        Object o = null;
        FooBar m = new FooBar();

        

        
        s = "foo" + n;
        check(11, s, "foonull");
        s = n + "bar";
        check(12, s, "nullbar");
        s = "foo" + o;
        check(13, s, "foonull");
        s = o + "bar";
        check(14, s, "nullbar");

        
        s = "" + n;
        check(21, s, "null");
        s = n + "";
        check(22, s, "null");
        s = "" + o;
        check(23, s, "null");
        s = o + "";
        check(24, s, "null");

        

        
        s = "foo" + m;
        check(31, s, "foonull");
        s = m + "bar";
        check(32, s, "nullbar");

        
        s = "" + m;
        check(43, s, "null");
        s = m + "";
        check(44, s, "null");

        
        

        s = "polymorph";
        char[] ca = {'i', 's', 'm'};

        check(51, s + ca, s + ca.toString());
        check(52, ca + s, ca.toString() + s);

        System.out.println("OK");
    }
}
