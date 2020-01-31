





public class ResInNestedExpr {

    static final int expected = 5;
    static int closed = 0;

    static void closing(String clazz) {
        closed++;
    }

    static void checkClosedCount() {
        if (expected != closed) {
            throw new RuntimeException("Did not find enough closed resources."
               + "Expected " + expected + ", but found " + closed);
        }
    }
    
    static String[] expectedOutput = {
        "aResource::bResource::cResource", 
        "aResource::bResource::cResource&aResource::cResource", 
        "aResource::bResource::cResource&aResource::cResource"}; 

    static void compare(String s1, String s2) {
        if (s1.compareTo(s2) != 0) {
            throw new RuntimeException(s1 + "!=" + s2);
        }
    }

    String test1() {
        String ret = null;
        try (bResource br = new bResource(new cResource());
                aResource ar = new aResource(br)) {
            ret = ar.getClass().getSimpleName() + "::" +
                  ar.getB().getClass().getSimpleName() + "::" +
                  ar.getB().getC().getClass().getSimpleName();
        }
        return ret;
    }

    String test2() {
        String ret = null;
        try (aResource ar = new aResource(new bResource(new cResource()), new cResource())) {
            String abc = ar.getClass().getSimpleName() + "::" +
                         ar.getB().getClass().getSimpleName() + "::" +
                         ar.getB().getC().getClass().getSimpleName();
            String ac = ar.getClass().getSimpleName() + "::" +
                        ar.getC().getClass().getSimpleName();
            ret = abc + "&" + ac;
        }
        return ret;
    }

    String test3() {
        String ret = null;
        try (bResource br = new bResource(new cResource());
                aResource ar = new aResource(br, new cResource())) {
            String abc = ar.getClass().getSimpleName() + "::" +
                         ar.getB().getClass().getSimpleName() + "::" +
                         ar.getB().getC().getClass().getSimpleName();
            String ac = ar.getClass().getSimpleName() + "::" +
                        ar.getC().getClass().getSimpleName();
            ret = abc + "&" + ac;
        }
        return ret;
    }

    public static void main(String... args) {
        ResInNestedExpr t = new ResInNestedExpr();
        int eo = 0;
        compare(expectedOutput[eo++], t.test1());
        compare(expectedOutput[eo++], t.test3());
        compare(expectedOutput[eo++], t.test2());
        ResInNestedExpr.checkClosedCount();
    }

    
    static class aResource implements AutoCloseable {

        bResource bR;
        cResource cR;

        public aResource() {
            bR = null;
            cR = null;
        }

        public aResource(bResource br) {
            bR = br;
        }

        public aResource(cResource cr) {
            cR = cr;
        }

        public aResource(bResource br, cResource cr) {
            bR = br;
            cR = cr;
        }

        public bResource getB() {
            return bR;
        }

        public cResource getC() {
            return cR;
        }

        @Override
        public void close() {
            ResInNestedExpr.closing(this.getClass().getName());
        }
    }

    
    static class bResource implements AutoCloseable {

        cResource cR;

        public bResource() {
            cR = null;
        }

        public bResource(cResource cr) {
            cR = cr;
        }

        public cResource getC() {
            return cR;
        }

        @Override
        public void close() {
            ResInNestedExpr.closing(this.getClass().getName());
        }
    }

    
    static class cResource implements AutoCloseable {

        public cResource() {
        }

        @Override
        public void close() {
            ResInNestedExpr.closing(this.getClass().getName());
        }
    }
}

