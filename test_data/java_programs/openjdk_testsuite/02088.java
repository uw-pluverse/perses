



public class DeeplyChainedNonPolyExpressionTest {
    static class JSO {

        JSO put(String s, Object y) {
            return null;
        }

        JSO put(java.lang.String x, java.util.Collection<String> y) {
            return null;
        }

        JSO put(java.lang.String x, int y) {
            return null;
        }

        JSO put(java.lang.String x, long y) {
            return null;
        }

        JSO put(java.lang.String x, double y) {
            return null;
        }

        JSO put(java.lang.String x, java.util.Map<String, String> y) {
            return null;
        }

        JSO put(java.lang.String x, boolean y) {
            return null;
        }
    }

    static class JSA {

        JSA put(Object o) {
            return null;
        }

        JSA put(int i, Object x) {
            return null;
        }

        JSA put(boolean x) {
            return null;
        }

        JSA put(int x) {
            return null;
        }

        JSA put(int i, int x) {
            return null;
        }

        JSA put(int x, boolean y) {
            return null;
        }

        JSA put(int i, long x) {
            return null;
        }

        JSA put(long x) {
            return null;
        }

        JSA put(java.util.Collection<String> x) {
            return null;
        }

        JSA put(int i, java.util.Collection<String> x) {
            return null;
        }

        JSA put(int i, java.util.Map<String, String> x) {
            return null;
        }

        JSA put(java.util.Map<String, String> x) {
            return null;
        }

        JSA put(int i, double x) {
            return null;
        }

        JSA put(double x) {
            return null;
        }
    }

    public static void main(String [] args) {
    }
    public static void foo() {
         new JSO()
          .put("s", new JSA())
          .put("s", new JSA())
          .put("s", new JSO()
            .put("s", new JSO()
              .put("s", new JSA().put("s"))
              .put("s", new JSA())
              .put("s", new JSO()
                .put("s", new JSO()
                  .put("s", new JSA().put("s").put("s"))
                  .put("s", new JSA())
                  .put("s", new JSO()
                    .put("s", new JSO()
                      .put("s", new JSA().put("s").put("s").put("s")
                            .put("s").put("s").put("s")
                            .put("s").put("s"))
                      .put("s", new JSA())
                      .put("s", new JSO()
                        .put("s", new JSO()
                          .put("s", new JSA().put("s"))
                          .put("s", new JSA())
                        )
                      )
                    )
                  )
                )
                .put("s", new JSO()
                  .put("s", new JSA().put("s"))
                  .put("s", new JSA())
                  .put("s", new JSO()
                  .put("s", new JSO()
                    .put("s", new JSA().put("s").put("s"))
                    .put("s", new JSA())
                    .put("s", new JSO()
                      .put("s", new JSO()
                        .put("s", new JSA().put("s").put("s").put("s")
                                .put("s").put("s").put("s")
                                .put("s").put("s"))
                        .put("s", new JSA())
                        .put("s", new JSO()
                          .put("s", new JSO()
                            .put("s", new JSA().put("s"))
                            .put("s", new JSA()))
                          )
                        )
                      )
                    )
                  )
                )
              )
            )
          );
  }
}
