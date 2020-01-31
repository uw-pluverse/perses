



public class Boxing1 {

    static Boolean _Boolean = true;
    static boolean _boolean = _Boolean;

    static Byte _Byte = (byte)3;
    static byte _byte = _Byte;

    static Character _Character = 'a';
    static char _char = _Character;

    static Short _Short = (short)4;
    static short _short = _Short;

    static Integer _Integer = 5;
    static int _int = _Integer;

    static Long _Long = 12L;
    static long _long = _Long;

    static Float _Float = 1.2f;
    static float _float = _Float;

    static Double _Double = 1.34;
    static double _double = _Double;

    public static void main(String[] args) {
        _Double = _Integer + _Integer + 0.0d;
        if (_Double != 10) throw new Error();

        _Integer = 2;
        _float = _Integer;
        if (_float != 2.0f) throw new Error();

        _int = 12;
        _Float = _int + 0.0f;
        if (_Float != 12.0f) throw new Error();

        _Integer = 8;
        _float = (float)_Integer;
        if (_float != 8.0f) throw new Error();

        _int = 9;
        _Float = (Float)(_int + 0.0f);
        if (_Float != 9.0f) throw new Error();

        if (_Boolean) ; else throw new Error();
        if (!_Boolean) throw new Error();

        if (_Integer >= _Long) throw new Error();

        _Character = 'a';
        String s1 = ("_" + _Character + "_").intern();
        if (s1 != "_a_") throw new Error(s1);

        
        if (_Integer++ != 8) throw new Error();
        if (_Integer++ != 9) throw new Error();
        if (++_Integer != 11) throw new Error();
        if ((_Integer += 3) != 14) throw new Error();
        if ((_Integer -= 3) != 11) throw new Error();

        Integer i = 0;
        i = i + 2;
        i += 2;
        if (i != 4) throw new Error();

        int j = 0;
        j += i;
        if (j != 4) throw new Error();

        Integer a[] = new Integer[1];
        a[0] = 3;
        a[0] += 3;
        if (a[0] != 6) throw new Error();

        Froobie x = new Froobie();
        Froobie y = new Froobie();
        x.next = y;
        x.next.i = 4;
        x.next.i += 4;
        if (--x.next.i != 7) throw new Error();
        if (x.next.i-- != 7) throw new Error();
        if (x.next.i != 6) throw new Error();

        boxIndex();
        boxArray();
    }

    static void boxIndex() {
        String[] a = { "hello", "world" };
        Integer i = 0;
        System.out.println(a[i]);
    }

    static void boxArray() {
        Integer[] a2 = { 0, 1, 2, 3 };
        for (int i : a2)
            System.out.println(i);
    }

    static class Froobie {
        Froobie next = null;
        Integer i = 1;
    }

    static class Scott {
        Integer i[];
        Integer j[];
        Integer k;

        int q = i[j[k]]++;
    }

    class T4974939 {
        void f() {
            Byte b = 12;
            Byte c = 'a';

            Short s = 'b';
            Short t = 12;

            Character d = 12;
        }
    }
}
