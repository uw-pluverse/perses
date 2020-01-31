



public class GetClass {
    public static void main(String[] args) {
        Class<? extends Class<GetClass>> x = GetClass.class.getClass();
    }
}
