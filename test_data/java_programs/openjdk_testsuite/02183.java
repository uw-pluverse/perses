
package test;



import static test.T8021112a.D;

@SuppressWarnings(D)
public class T8021112a {
    public static final String D = (String) "cast";
}

class Other {
    public static final String D = "cast";
    @SuppressWarnings(D)
    public static final String D2 = (String) "cast";
}
