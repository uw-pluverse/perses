

import java.util.ArrayList;
import java.util.List;


class Unchecked
{
    void m() {
        List l = new ArrayList<String>();
        l.add("abc");
    }
}


@SuppressWarnings("unchecked")
class Unchecked2
{
    void m() {
        List l = new ArrayList<String>();
        l.add("abc");
    }
}

class Unchecked3
{
    @SuppressWarnings("unchecked")
    void m() {
        List l = new ArrayList<String>();
        l.add("abc");
    }
}

class Unchecked4
{
    void m() {
        @SuppressWarnings("unchecked")
            class Inner {
                void m() {
                    List l = new ArrayList<String>();
                    l.add("abc");
                }
            }
    }
}


class Unchecked5 extends Unchecked2
{
    void m() {
        List l = new ArrayList<String>();
        l.add("abc");
    }
}
