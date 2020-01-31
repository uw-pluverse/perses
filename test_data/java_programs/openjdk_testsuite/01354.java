





class VarargsArgumentMismatch {
    void m(String s, Integer... is) {}
    { this.m("1", "2", "3"); }
}
