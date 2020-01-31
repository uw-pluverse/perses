




class CantApplyDiamond<T extends Number> {
    CantApplyDiamond(T t) { }
    <U> CantApplyDiamond(T t, U u) { }

    void m() {
        CantApplyDiamond<?> x = new CantApplyDiamond<>("");
    }
}
