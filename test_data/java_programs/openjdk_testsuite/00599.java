



public class NewBeforeOuterConstructed3 {
    class Two extends NewBeforeOuterConstructed3 {
        {
            System.out.println(NewBeforeOuterConstructed3.this);
        }
    }
    class Three extends Two {
        {
            new Two();
        }
    }
    public static void main(String[] args) {
        NewBeforeOuterConstructed3 o = new NewBeforeOuterConstructed3();
        System.out.println(o + " " + o.new Three());
    }
}
