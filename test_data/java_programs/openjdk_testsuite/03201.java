



class LambdaConv06 {

    private int t() {
        return a((final Object indexed) -> {
            return b(new R() {
                public String build(final Object index) {
                    return "";
                }
            });
        });
    }

    private int a(R r) {return 0;}
    private String b(R r) {return null;}

    public static interface R {
        public String build(Object o);
    }
}
