



public class ConstValInlining {

    void test() throws Exception {
        Class checksClass = Class.forName("test_ff");
        test_ff obj = new test_ff();
        String reflected_fnl_str = (String)checksClass.getField("fnl_str").get(obj);

        T t = new T();

        
        if (t.fnl_str.equals(reflected_fnl_str))
            throw new Exception("FAILED: compiler failed to inline a qualified nonstatic constant");

        
        t.test(reflected_fnl_str);
    }

    static class T extends test_ff {
        void test(String reflected) throws Exception {
            
            if (fnl_str.equals(reflected))
                throw new Exception("FAILED: compiler failed to inline an unqualified nonstatic constant");
        }
    };

    public static void main(String args[]) throws Exception {
        new ConstValInlining().test();
    }
}
