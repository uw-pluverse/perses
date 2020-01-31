



class LambdaConv12 {

    LambdaConv12(SAM s) {}

    interface SAM {
        public abstract void m();
    }

    void test() {
        new LambdaConv12(()-> { });
        new LambdaConv12(()-> { }) {};
    }
}
