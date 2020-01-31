



class T4711570 {
    public static int fi() {
        return fi();
    }

    public static void gi() {
        fi();
        gi();
    }

    public static <T> int f() {
        return f();
    }

    public static <T> void g() {
        f();    
        int i = f(); 
        g();    
    }
    

    public static <T> void h() {
        g();    
    }

    public static <T> int f(T x) {
        return f(x);
    }

    public static <T> void g(T x) {
        f(x);
        g(x);   
    }

    public static <T> void h(T x) {
        g(x);   
    }
}
