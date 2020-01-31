

class T6863465a {
    static class a { static interface b {} }
    static class c extends a implements z.y {}
    static class x { static interface y {} }
    static class z extends x implements c.b {}
}
