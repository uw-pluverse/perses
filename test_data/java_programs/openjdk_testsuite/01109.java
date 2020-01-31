



class MulticatchCantBeAssigned{
    void e1() throws NullPointerException { }
    void e2() throws IllegalArgumentException { }

    void m() {
        try {
            e1();
            e2();
        } catch (final NullPointerException | IllegalArgumentException e) {
            e = new RuntimeException();
        }
    }
}
