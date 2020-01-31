





public class Pos11 {

    public static String results = "";
    public static String sExpected = "-AB:A-AB:B-CD:C-AB:C-CD:D-Throwable:D-CD:E" +
            "-AB:E-Exception:Exception-Throwable:Exception";

    enum TestExceptions {
        A("A"),
        B("B"),
        C("C"),
        D("D"),
        E("E"),
        U("U");

        String exType;
        TestExceptions(String type) {
            this.exType = type;
        }
    }

    public static void main(String... args) {
        Pos11 pos11 = new Pos11();
        for(TestExceptions t : TestExceptions.values()) {
            pos11.rethrower(t.exType);
        }
        if (results.compareTo(sExpected) != 0)
            throw new RuntimeException("FAIL: final strings did not match:\n"
                    + results + "!=\n" + sExpected);
        System.out.println("PASS");
    }

    void rethrower(String T) {
        try { 
            try { 
                try { 
                    try { 
                        switch (T) {
                        case "A":
                            throw new A();
                        case "B":
                            throw new B();
                        case "C":
                            throw new C();
                        case "D":
                            throw new D();
                        case "E":
                            throw new E();
                        default:
                            throw new Exception(
                                    new Throwable());
                        }
                    } catch ( final C|D cd) {
                        results=results.concat("-CD:" + cd.getClass().getSimpleName());
                        throw cd;
                    }
                } catch (final A|B ab) {
                    results=results.concat("-AB:" + ab.getClass().getSimpleName());
                }
            } catch (final Exception e ) {
                results=results.concat("-Exception:" + e.getClass().getSimpleName());
                throw e;
            }
        } catch (Throwable t) {
            results=results.concat("-Throwable:" + t.getClass().getSimpleName());
        }
    }

    
    static class A extends Exception {}

    
    static class B extends Exception {}

    
    static class C extends B {}

    
    static class D extends Error {}

    
    static class E extends C {}

}

