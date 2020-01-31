



import java.nio.file.Path;
import java.nio.file.Paths;


public class StackMapTest {

    class Test {
        void method0(boolean aboolean) throws Exception {
            label_0:
            while (true) {
                if (aboolean) ;
                else break label_0;
            }
        }
    }

    public static void main(String args[]) throws Exception {



        Path pathToClass = Paths.get(System.getProperty("test.classes"),
                "StackMapTest$Test.class");
        ToolBox.JavaToolArgs javapArgs =
                new ToolBox.JavaToolArgs().setAllArgs("-v", pathToClass.toString());


        if (!ToolBox.javap(javapArgs).contains("StackMapTable: number_of_entries = 2"))
            throw new AssertionError("The number of entries of the stack map "
                    + "table should be equal to 2");
    }

}
