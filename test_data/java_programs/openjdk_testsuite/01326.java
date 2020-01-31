



class VarMightAlreadyBeAssigned {
    void m(boolean b) {
        final int i;
        if (b)
            i = 3;
        i = 4;
    }
}
