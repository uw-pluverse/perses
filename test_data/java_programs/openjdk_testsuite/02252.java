

class T5017953 {

    int f = 0;
    void test(int i) {}

    {   test(NonExistentClass.f ++);
        test(1 + NonExistentClass.f);
        test(NonExistentClass.f + 1);
        test(NonExistentClass.f + NonExistentClass.f);
        test(NonExistentClass.f += 1);
        test(f += NonExistentClass.f);
    }
}
