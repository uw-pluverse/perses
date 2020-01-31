



class TargetType01 {

    interface Func<A,B> {
        B call(A a);
    }

    interface F_I_I extends Func<Integer,Integer> {}
    interface F_S_S extends Func<String,String> {}

    static Integer M(F_I_I f){ return null; }
    static String M(F_S_S f){ return null; }

    static {
        M(x1 -> {
            return M( x2 -> {
                return x1 + x2;
            });
        }); 
    }
}
