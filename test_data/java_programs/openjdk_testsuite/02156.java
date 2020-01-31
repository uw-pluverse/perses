



class T7013865 {
    public <X extends Number> void m(X... args) { }
    public void m(Object... args) { }

    { m(null, null); }
}
