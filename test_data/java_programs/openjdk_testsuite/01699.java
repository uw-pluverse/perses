

class T6554097 {
    @SuppressWarnings("serial") final Throwable[] v1 = { new Throwable() {} };
    @SuppressWarnings("serial")       Throwable[] v2 = { new Throwable() {} };

    public static void m1() throws Throwable {
            @SuppressWarnings("serial") final Throwable[] v3 = { new Throwable() {} };
            @SuppressWarnings("serial")       Throwable[] v4 = { new Throwable() {} };
    }

    final Throwable[] v5 = { new Throwable() {} };
          Throwable[] v6 = { new Throwable() {} };

    public static void m2() throws Throwable {
        final Throwable[] v7 = { new Throwable() {} };
                  Throwable[] v8 = { new Throwable() {} };
    }
}

