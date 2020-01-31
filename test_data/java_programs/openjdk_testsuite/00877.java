



public enum UserValue {
    UP(0),
    DOWN(1);

    final int oldMode;

    private UserValue(int mode) {
        this.oldMode = mode;
    }

    public static UserValue valueOf(int rm) {
        return UP;
    }
}
