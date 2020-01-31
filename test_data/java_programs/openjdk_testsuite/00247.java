



public class T6199146 {
    static class Test2 <T extends I1 & I2> { }

    static interface I1 {
        int getFoo();
    }

    static interface I2 {
        float getFoo();
    }
}
