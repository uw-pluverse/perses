



interface MyFunctionalInterface1 {
    int invokeMethodReference();
}

public class MethodInvoker {
    public static void main(String[] args) throws Exception {
        MethodInvoker.invoke();
        System.out.println("Passed!");
    }
    public static void invoke() throws Exception {
        MethodSupplier ms = new MethodSupplier();
        MyFunctionalInterface1 fi = ms::m;
        if (fi.invokeMethodReference() != 123) {
            throw new Exception();
        }
    }
    static class MethodSupplier {
        private int m() {
            return 123;
        }
    }
}
