



public interface CannotChangeAssertionsStateAfterInitialized {
    default void m() {
        assert false;
    }

    public static void main(String[] args) {
        ClassLoader cl = CannotChangeAssertionsStateAfterInitialized.class.getClassLoader();
        cl.setClassAssertionStatus(CannotChangeAssertionsStateAfterInitialized.class.getName(), true);
        new CannotChangeAssertionsStateAfterInitialized() {}.m();
    }

}
