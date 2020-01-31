



public class DefAssignBoolean_5 {

    public static void main(String[] args) {

                boolean b3, b4;
                boolean r = false;
                boolean t = true;

                if ((t && (b3 = r)) != (t && (b3 = t)))
                    r = b3;
    }
}
