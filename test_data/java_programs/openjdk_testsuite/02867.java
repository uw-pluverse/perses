



interface MyFunctionalInterface2 {
    int invokeMethodReference();
}

public class MethodSupplier {
    public static void main(String[] args) throws Exception {
        MethodInvoker.invoke();
        System.out.println("Passed!");
    }
    private int m() {
        return 4321;
    }
    static class MethodInvoker {
        public static void invoke() throws Exception {
            MethodSupplier ms = new MethodSupplier();
            MyFunctionalInterface2 fi = ms::m;
            if (fi.invokeMethodReference() != 4321) {
                throw new Exception();
            }
        }
    }
}
