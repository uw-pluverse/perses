



public class DefAssignBoolean_11 {

    public static void main(String[] args) {

        boolean b1, b2;
        boolean r = false;
        boolean f = false;
        boolean t = true;

        if ((t && (b1 = t)) ? t : t && (b1 = f))
            r = b1;
    }
}
