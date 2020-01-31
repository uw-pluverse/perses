



public class ConstValInit {

    public final String fnl_str = "Test string";

    public final int fnl_int = 1;

    public static void main(String args[]) throws Exception {

        Class checksClass = Class.forName("ConstValInit");
        ConstValInit checksObject = (ConstValInit)(checksClass.newInstance());
        String reflected_fnl_str = (String)checksClass.getField("fnl_str").get(checksObject);
        if (!checksObject.fnl_str.equals(reflected_fnl_str)) {
            throw new Exception("FAILED: ordinary and reflected field values differ");
        }

    }

    void foo() {
        
        
        switch (1) {
            case fnl_int: break;
        }
    }

}
