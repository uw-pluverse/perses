






class CantApplyDiamond1<X> {

    CantApplyDiamond1(CantApplyDiamond1<? super X> lz) { }

    void test(CantApplyDiamond1<Integer> li) {
       CantApplyDiamond1<String> ls = new CantApplyDiamond1<>(li);
    }
}
