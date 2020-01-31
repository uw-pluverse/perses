

class BadConv04 {

    interface I1 {
        int m();
    }

    interface I2 {
        long m();
    }

    interface SAM extends I1, I2 {}

    SAM s = ()-> { };
}
