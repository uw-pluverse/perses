



public class TreeMakerParamsIsGoofy {

    interface III { }

    interface UO {
        III m(III x);
    }

    public static void main(String[] args) {
        class BA implements III {
            BA(III b) {
            }
        }

        ts(BA::new);
    }

    static void ts(UO ba) {
    }
}
