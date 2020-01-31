




class Base {
    int m() {
        return 0;
    }
}

class OverrideIncompatibleReturn extends Base {
    String m() {
        return null;
    }
}

