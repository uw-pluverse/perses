




enum EnumTest {
    E1(0), E2(1, "x"), E3(2, "x", "y"), E4;

    EnumTest() { }
    EnumTest(int a, String... ba) { }
    boolean ok(int c, String... dc) { return true; }

    int valueOf(EnumTest A, EnumTest BA) { return 0; }
}



