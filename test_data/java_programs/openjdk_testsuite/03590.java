



public enum Enum1 {
    red {
        public String toString() {
            return "correct";
        }
    };
    private Enum1() {}
    public static void main(String[] args) {
        System.out.println(red);
    }
}
