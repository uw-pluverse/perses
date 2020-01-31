

@Deprecated
class Deprecation
{
}


class Deprecation2
{
    void m() {
        Object d = new Deprecation();
    }
}


@SuppressWarnings("deprecation")
class Deprecation3
{
    void m() {
        Object d = new Deprecation();
    }
}

class Deprecation4
{
    @SuppressWarnings("deprecation")
    void m() {
        Object d = new Deprecation();
    }
}

class Deprecation5
{
    void m() {
        @SuppressWarnings("deprecation")
            class Inner {
                void m() {
                    Object d = new Deprecation();
                }
            }
    }
}


class Deprecation6 extends Deprecation3
{
    void m() {
        Object d = new Deprecation();
    }
}
