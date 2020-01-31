



class DUTry {
    void foo() {
        int c = 1;
        int a = 3;
        final int a1;

        try {
            if (a == 3)
                throw new Exception();
        } catch (Throwable e) {
            System.out.println(e);
            a1 = 6;
            System.out.println(a1);
        } finally {
            c = (a1=8) - 1;
            System.out.println(a1);
        }
    }
}
