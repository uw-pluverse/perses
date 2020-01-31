

class T6863465c {
    static class x { static interface y {} }
    static class z extends x implements c.b {}
    static class a { static interface b { static interface d {} } }
    static class c extends a implements z.y, z.d {}
}
