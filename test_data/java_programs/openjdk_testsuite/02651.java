



public class DefAssignBoolean_14 {

    public static void main(String[] args) {

        boolean b1, b2;
        boolean r = false;
        boolean f = false;
        boolean t = true;

        if ((t || (b2 = f)) ? f || (b2 = f) : t);
        else
            r = b2;

    }
}
