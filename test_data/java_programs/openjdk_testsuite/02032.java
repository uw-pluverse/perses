



public class CompileErrorWithIteratorTest {

    private static final String TestCollectionSrc =
        "package pkg;\n" +

        "import java.util.Iterator;\n" +
        "import java.util.NoSuchElementException;\n" +

        "public class TestCollection<E> implements Iterable<E> {\n" +
        "    public testCollectionIterator iterator() {\n" +
        "        return  new testCollectionIterator();\n" +
        "    }\n" +
        "    class testCollectionIterator implements Iterator<E> {\n" +
        "        public boolean hasNext() { return true; }\n" +
        "        public E next() throws NoSuchElementException\n" +
        "        {\n" +
        "            return null;\n" +
        "        }\n" +
        "        public void remove() {}\n" +
        "    }\n" +
        "}";

    private static final String TestSrc =
        "import pkg.TestCollection;\n" +
        "\n" +
        "public class Test {\n" +
        "\n" +
        "    public static void main(String[] args) {\n" +
        "        TestCollection<String>  tc1 = new TestCollection<String>();\n" +
        "        for (String s : tc1) {\n" +
        "            System.out.println(s);\n" +
        "        }\n" +
        "      }\n" +
        "}";

    public static void main(String args[]) throws Exception {
        new CompileErrorWithIteratorTest().run();
    }

    void run() throws Exception {
        compile();
    }

    void compile() throws Exception {
        ToolBox.JavaToolArgs javacParams =
                new ToolBox.JavaToolArgs()
                .setSources(TestCollectionSrc, TestSrc);
        ToolBox.javac(javacParams);
    }

}
