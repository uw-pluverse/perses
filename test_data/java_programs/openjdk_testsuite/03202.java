



interface MyFI {
    void accept();
}

public class LambdaWithBinOpConstRefToConstString {
    public static void main(String[] args) {
        final String CONSTANT_STRING_VALUE = "mwmwm";

        MyFI consumeStrings = () -> {
            System.out.println(" local constant: " + CONSTANT_STRING_VALUE);
        };
    }
}
