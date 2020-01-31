



public class T5105890 {
    public static final String str1  = (false ? "YYY" : null  );
    public static final String str2  = (true  ? null  : "YYY" );
    public static void main(String[] args) {
        if (str1 != null)
            throw new RuntimeException("str1 != null");
        if (str2 != null)
            throw new RuntimeException("str2 != null");
    }
}
