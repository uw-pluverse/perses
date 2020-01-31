



class StaticBlockScope {

    static {
        Object A = new Object () {
                Object B = C;
            };
    }

    static final Object C
        = new Object () {
                Object D = null;
            };

}
