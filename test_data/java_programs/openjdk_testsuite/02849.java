



public class InnerTruth {

    static final boolean DEBUG = true;

    public static void main(String[] args) throws Exception {
        InnerTruth me = new InnerTruth();
    }

    InnerTruth() throws Exception {
        new Inner().doIt();
        if (DEBUG) {
            System.out.println("OK");
        } else {
            System.out.println("FAILED in outer");
            throw new Exception("FAILED in outer");
        }
    }

    class Inner {
        public void doIt() throws Exception {
            if (DEBUG) {
                System.out.println("OK");
            } else {
                System.out.println("FAILED in inner");
                throw new Exception("FAILED in inner");
            }
        }
    }
}
