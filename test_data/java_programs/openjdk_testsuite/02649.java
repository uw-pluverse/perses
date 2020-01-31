



public class DefAssignCond {
    public static void main (String[] args) {
        boolean t = true, f = false, b1, b2;
        if (t ? (b1 = t) : false)
            t = b1;
        if (f ? true : (b2 = f)) ;
        else
            f = b2;
    }
}
