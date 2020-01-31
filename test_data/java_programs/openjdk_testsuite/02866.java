



interface MyFunctionalInterface3 {
    int invokeMethodReference();
}

public class ThirdClass {
    public static void main(String[] args) throws Exception {
        MethodInvoker.invoke();
        System.out.println("Passed!");
    }
    static class MethodSupplier {
        private int m() {
            return 999;
        }
    }

    static class MethodInvoker {
        public static void invoke() throws Exception {
            MethodSupplier ms = new MethodSupplier();
            MyFunctionalInterface3 fi = ms::m;
            if (fi.invokeMethodReference() != 999) {
                throw new Exception();
            }
        }
    }
}
