

class BadTargetType {

    static void m1(Object o) {}
    void m2(Object o) {}

    static Object l1 = (int pos)-> { };
    Object l2 = (int pos)-> { };

    {
        m1((int pos)-> { });
        m2((int pos)-> { });
    }
}
