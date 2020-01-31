



public class DefAssignBoolean_13 {

    public static void main(String[] args) {

        boolean b1, b2;
        boolean r = false;
        boolean f = false;
        boolean t = true;

        if ((t && (b1 = t)) ? f : t || (b1 = f));
        else
            r = b1;

    }
}
