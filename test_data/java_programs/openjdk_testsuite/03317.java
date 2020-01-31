



import java.util.Collections;
import java.util.List;
import java.util.ArrayList;
import java.io.*;

public class LambdaTest2_SAM1 {
    private static List<String> strs = new ArrayList<String>();
    private static List<File> files = new ArrayList<File>();

    public static void main(String[] args) {
        strs.add("copy");
        strs.add("paste");
        strs.add("delete");
        strs.add("rename");

        files.add(new File("a.txt"));
        files.add(new File("c.txt"));
        files.add(new File("b.txt"));

        
        Collections.sort(files, (File f1, File f2) -> f1.getName().compareTo(f2.getName()));
        for(File f : files)
            System.out.println(f.getName());
        System.out.println();
        Collections.sort(files, (File f1, File f2) -> (int)(f1.length() - f2.length()));
        for(File f : files)
            System.out.println(f.getName() + " " + f.length());
        System.out.println();

        LambdaTest2_SAM1 test = new LambdaTest2_SAM1();

        
        test.methodMars((File f) -> {
            System.out.println("implementing Mars<File>.getAge(File f)...");
            return (int)f.length();
        });
        test.methodJupiter((int n) -> n+1);

        
        test.methodXY((List<String> strList) -> strList.size() );
        test.methodXYZ((List<String> strList) -> 20 );
    }

    
    void methodMars(Mars<File> m) {
        System.out.println("methodMars(): SAM type interface Mars object instantiated: " + m);
        System.out.println(m.getAge(new File("a.txt")));
    }

    
    void methodJupiter(Jupiter j) {
        System.out.println("methodJupiter(): SAM type interface Jupiter object instantiated: " + j);
        System.out.println(j.increment(33));
    }

    
    void methodXY(XY xy) {
        System.out.println("methodXY(): SAM type interface XY object instantiated: " + xy);
        System.out.println(xy.getTotal(strs));
    }

    
    void methodXYZ(XYZ xyz) {
        System.out.println("methodXYZ(): SAM type interface XYZ object instantiated: " + xyz);
        System.out.println(xyz.getTotal(strs));
    }
}
