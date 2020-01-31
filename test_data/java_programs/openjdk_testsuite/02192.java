

public class T8021112b {
    public static final String D1 = Dep.D;
    public static final String D2 = "";
    public static final Object[] o = {
        new Object() {
            Dep d;
        }
    };
}

@Deprecated class Dep {
    public static final String D = T8021112b.D2;
}
