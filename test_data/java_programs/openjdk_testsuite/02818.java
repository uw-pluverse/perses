

public class CompileTimeErrorForNonAssignedStaticFieldTest {
    private final static int i;

    public CompileTimeErrorForNonAssignedStaticFieldTest()
            throws InstantiationException {
        throw new InstantiationException("Can't instantiate");
    }

    static class Inner {
        private final int j;
        public Inner(int x)
                throws InstantiationException {
            if (x == 0) {
                throw new InstantiationException("Can't instantiate");
            } else {
                j = 1;
            }
            System.out.println(j);
        }
    }

}
