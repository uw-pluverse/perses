



public class FauxEnum3 extends SpecializedEnum {
}

enum SpecializedEnum {
    RED {
        boolean special() {return true;}
    },
    GREEN,
    BLUE;
    boolean special() {return false;}
}
