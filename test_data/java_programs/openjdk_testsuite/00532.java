



class T4711572 {
    static <T> boolean isOK(T x) {
        return isOK(x);
    }

    static <T> boolean isStillOK(T x) {
        return true && isOK(x);
    }

    static <T> boolean isNoMoreOK(T x) {
        return true && isNoMoreOK(x);
    }

    static <T> boolean isOKAgain(T x) {
        boolean res;
        return true && (res = isOKAgain(x));
    }
}
