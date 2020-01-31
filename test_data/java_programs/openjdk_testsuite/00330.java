





class T {

    class U<Y> extends T {
        <B> U(B b) {}
    }

    public static void main(String[] args) {
        new T().new <Integer>U<Integer>("");
    }
}
