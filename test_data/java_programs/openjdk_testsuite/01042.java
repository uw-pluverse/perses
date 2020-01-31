



public class StringAppendAccessMethodOnLHS {

    

    private String s = "";

    class Inner {
        void m() {
            s += "a";
            s += 'a';  
        }
    }

    void test () {
        Inner o = new Inner();
        o.m();
    }

    public static void main(String[] args) throws Exception {
        StringAppendAccessMethodOnLHS o = new StringAppendAccessMethodOnLHS();
        o.test();
        if (!o.s.equals("aa")) throw new Exception();
    }

}
