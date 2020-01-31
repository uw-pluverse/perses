




public class ResourceShadow {

    static final String str = "asdf";  

    
    String test1() {
        String ret = null;
        switch (str) {
            case str: 
                try (SilentCloseable str = new SilentCloseable()) {
                    SilentCloseable tr = new SilentCloseable(str);
                    ret = str.getClass().getSimpleName();
                }
                break;
            default:
                ret = "";
        }
        return ret;
    }

    
    String test2() {
        String ret = null;
        try (SilentCloseable str = new SilentCloseable()) {
            class temp {

                String str = "I am not a SilentCloseable";

                public void printSTR() {
                    System.out.println(str);
                }

                public String getSTR() {
                    return str;
                }
            }
            temp tmp = new temp();
            SilentCloseable tr = new SilentCloseable(tmp.getSTR());
            ret = tr.getMsg();
        }
        return ret;
    }

    public static void main(String... args) {
        ResourceShadow t = new ResourceShadow();
        if (t.test1().compareTo("SilentCloseable") != 0) {
            throw new RuntimeException("FAIL-test1");
        }
        if (t.test2().compareTo("I am not a SilentCloseable") != 0) {
            throw new RuntimeException("FAIL-test2");
        }
    }
}

class SilentCloseable implements AutoCloseable {

    SilentCloseable testres = null;
    String msg = "default";

    @Override
    public void close() {
    }

    public SilentCloseable() {
    }

    public SilentCloseable(String s) {
        msg = s;
    }

    public SilentCloseable(SilentCloseable tr) {
        testres = tr;
    }

    public String getMsg() {
        return msg;
    }
}

