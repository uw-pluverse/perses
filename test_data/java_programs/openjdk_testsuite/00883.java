



class T6724345 {

    interface I {
        void i();
    }

    class U {
        {
        I i = E.V;
        i.i();
        E.V.i();
        }
    }

    enum E implements I {
        V {public void i() {}};
    }
}
