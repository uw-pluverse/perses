




class FinallyCannotComplete {
    void m() {
        try {
        } finally {
            throw new Error();
        }
    }
}
