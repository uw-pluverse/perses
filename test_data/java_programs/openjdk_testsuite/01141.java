




class UnsafeUseOfVarargsParam {
    @SafeVarargs static <X> void m(X... x) {
        Object[] o = x;
    }
}
