



public class DefAssignBoolean_12 {

    public static void main(String[] args) {

        boolean b1, b2;
        boolean r = false;
        boolean f = false;
        boolean t = true;

        if ((t || (b2 = f)) ? t && (b2 = t) : f)
            r = b2;

    }
}
