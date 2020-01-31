



public enum Enum3 {
    red, green, blue;

    public static void main(String[] args) {
        for (int i=0; i<3; i++) {
            Enum3 v = values()[i];
            switch (v) {
            case red:
                if (i == 0) continue;
                break;
            case green:
                if (i == 1) continue;
                break;
            case blue:
                if (i == 2) continue;
                break;
            default:
                break;
            }
            throw new Error();
        }
    }
}
