



class ExceptAlreadyCaught {
    void x() throws Exception { }

    void m() {
        try {
            x();
        } catch (Exception e) {
        } catch (Exception e) {
        }
    }
}
