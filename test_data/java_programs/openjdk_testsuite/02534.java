



import com.sun.tools.classfile.*;
import java.io.File;

public class CombinationsTargetTest2 extends ClassfileTestHelper {

    
    int testcount = 0;

    
    enum srce  {
        src1("(repeating) type annotations on on field in method body",true),
        src2("(repeating) type annotations on type parameters, bounds and  type arguments", true),
        src3("(repeating) type annotations on type parameters of class, method return value in method", true),
        src4("(repeating) type annotations on field in anonymous class", false),
        src5("(repeating) type annotations on field in anonymous class", false),
        src6("(repeating) type annotations on void method declaration", false),
        src7("(repeating) type annotations in use of instanceof", true),
        src8("(repeating) type annotations in use of instanceof in method", true);

        String description;
        Boolean local;

        srce(String desc, Boolean b) {
            this.description = this + ": " +desc;
            this.local = b;
        }
    }


    String[] ETypes={"TYPE", "FIELD", "METHOD", "PARAMETER", "CONSTRUCTOR",
                     "LOCAL_VARIABLE", "ANNOTATION_TYPE", "PACKAGE"};

    
    Boolean hasInnerClass=false;
    String innerClassname="";

    public static void main(String[] args) throws Exception {
        new CombinationsTargetTest2().run();
    }

    void run() throws Exception {
        
        Boolean As= false, BDs=true, ABMix=false;
        int testrun=0;
        Boolean [][] bRepeat = new Boolean[][]{{false,false,false},
                                               {true,false,false}, 
                                               {false,true,false}, 
                                               {true,true,false},  
                                               {false,false,true}  
        };

        for(Boolean[] bCombo : bRepeat) {
            As=bCombo[0]; BDs=bCombo[1]; ABMix=bCombo[2];
            for(String et : ETypes) {
               switch(et) {
                   case "METHOD":
                       test( 8, 0, 0, 0, As, BDs, ABMix, "CLASS",   et, ++testrun, srce.src1);
                       test( 0, 8, 0, 0, As, BDs, ABMix, "RUNTIME", et, ++testrun, srce.src1);
                       test( 2, 0, 2, 0, As, BDs, ABMix, "CLASS",   et, ++testrun, srce.src5);
                       test( 0, 2, 0, 2, As, BDs, ABMix, "RUNTIME", et, ++testrun, srce.src5);
                       test( 0, 0, 2, 0, As, BDs, ABMix, "CLASS", et, ++testrun, srce.src6);
                       test( 0, 0, 0, 2, As, BDs, ABMix, "RUNTIME", et, ++testrun, srce.src6);
                       test( 2, 0, 0, 0, As, BDs, ABMix, "CLASS", et, ++testrun, srce.src7);
                       test( 0, 2, 0, 0, As, BDs, ABMix, "RUNTIME", et, ++testrun, srce.src7);
                       test( 4, 0, 0, 0, As, BDs, ABMix, "CLASS", et, ++testrun, srce.src8);
                       test( 0, 4, 0, 0, As, BDs, ABMix, "RUNTIME", et, ++testrun, srce.src8);
                       break;
                   case "FIELD":
                       test( 8, 0, 0, 0, As, BDs, ABMix, "CLASS",   et, ++testrun, srce.src1);
                       test( 8, 0, 0, 0, As, BDs, ABMix, "CLASS",   et, ++testrun, srce.src2);
                       test( 6, 0, 0, 0, As, BDs, ABMix, "CLASS",   et, ++testrun, srce.src3);
                       test( 2, 0, 2, 0, As, BDs, ABMix, "CLASS",   et, ++testrun, srce.src4);
                       test( 0, 8, 0, 0, As, BDs, ABMix, "RUNTIME", et, ++testrun, srce.src1);
                       test( 0, 8, 0, 0, As, BDs, ABMix, "RUNTIME", et, ++testrun, srce.src2);
                       test( 0, 6, 0, 0, As, BDs, ABMix, "RUNTIME", et, ++testrun, srce.src3);
                       test( 0, 2, 0, 2, As, BDs, ABMix, "RUNTIME", et, ++testrun, srce.src4);
                       break;
                   default:
                       test( 0, 2, 0, 0, As, BDs, ABMix, "RUNTIME", et, ++testrun, srce.src4);
                       test( 0, 2, 0, 0, As, BDs, ABMix, "RUNTIME", et, ++testrun, srce.src5);
                       break;
               }
            }
        }
    }

    public void test(int tinv, int tvis, int inv, int vis, Boolean Arepeats,
                     Boolean BDrepeats, Boolean ABmix, String rtn, String et2,
                     Integer N, srce source) throws Exception {
        ++testcount;
        expected_tvisibles = tvis;
        expected_tinvisibles = tinv;
        expected_visibles = vis;
        expected_invisibles = inv;
        File testFile = null;
        String tname="Test" + N.toString();
        hasInnerClass=false;
        String testDef = "Test " + testcount + " parameters: tinv=" + tinv +
                ", tvis=" + tvis + ", inv=" + inv + ", vis=" + vis +
                ", Arepeats=" + Arepeats + ", BDrepeats=" + BDrepeats +
                ", ABmix=" + ABmix + ", retention: " + rtn + ", anno2: " +
                et2 + ", src=" + source + "\n    " + source.description;

        println(testDef);
        
        String sourceString = sourceString(tname, rtn, et2, Arepeats,
                                           BDrepeats, ABmix, source);
        testFile = writeTestFile(tname+".java", sourceString);
        
        File classFile = null;
        try {
            classFile = compile(testFile);
        } catch (Error err) {
            System.err.println("Failed compile. Source:\n" + sourceString);
            throw err;
        }
        
        if(hasInnerClass) {
            StringBuffer sb = new StringBuffer(classFile.getAbsolutePath());
            classFile=new File(sb.insert(sb.lastIndexOf(".class"),innerClassname).toString());
            println("classfile: " + classFile.getAbsolutePath());
        }
        ClassFile cf = ClassFile.read(classFile);

        
        test(cf);

        for (Field f : cf.fields) {
            if(source.local)
                test(cf, f, true);
            else
                test(cf,f);
        }
        for (Method m: cf.methods) {
            if(source.local)
                test(cf, m, true);
            else
                test(cf, m);
        }
        countAnnotations();
        if (errors > 0) {
            System.err.println( testDef );
            System.err.println( "Source:\n" + sourceString );
            throw new Exception( errors + " errors found" );
        }
        println("Pass");
    }

    
    String sourceString(String testname, String retentn, String annot2,
                        Boolean Arepeats, Boolean BDrepeats, Boolean ABmix,
                        srce src) {

        String As = "@A", Bs = "@B", Ds = "@D";
        if(Arepeats) As = "@A @A";
        if(BDrepeats) {
            Bs = "@B @B";
            Ds = "@D @D";
        }
        if(ABmix) { As = "@A @B"; Bs = "@A @B"; Ds = "@D @D"; }

        
        
        String source = new String();
        String imports = new String("import java.lang.annotation.*; \n" +
            "import static java.lang.annotation.RetentionPolicy.*; \n" +
            "import static java.lang.annotation.ElementType.*; \n" +
            "import java.util.List; \n" +
            "import java.util.HashMap; \n" +
            "import java.util.Map; \n\n");

            String sourceBase = new String("@Retention("+retentn+")\n" +
            "@Target({TYPE_USE,_OTHER_})\n" +
            "@Repeatable( AC.class )\n" +
            "@interface A { }\n\n" +

            "@Retention("+retentn+")\n" +
            "@Target({TYPE_USE,_OTHER_})\n" +
            "@interface AC { A[] value(); }\n\n" +

            "@Retention("+retentn+")\n" +
            "@Target({TYPE_USE,_OTHER_})\n" +
            "@Repeatable( BC.class )\n" +
            "@interface B { }\n\n" +

            "@Retention("+retentn+")\n" +
            "@Target({TYPE_USE,_OTHER_})\n" +
            "@interface BC { B[] value(); } \n\n" +

            "@Retention("+retentn+")\n" +
            "@Target({TYPE_USE,TYPE_PARAMETER,_OTHER_})\n" +
            "@Repeatable(DC.class)\n" +
            "@interface D { }\n\n" +

            "@Retention("+retentn+")\n" +
            "@Target({TYPE_USE,TYPE_PARAMETER,_OTHER_})\n" +
            "@interface DC { D[] value(); }\n\n");

        
        switch(src) {
            case src1: 
                    
                source = new String(
                    "// " + src.description + "\n" +
                    "class " + testname + " {\n" +
                    "" + testname +"(){} \n" +
                    "// type usage in method body \n" +
                    "String test("+testname+" this, " +
                       "String param, String ... vararg) { \n" +
                    "    _As_ _Bs_\n    Object o = new _As_ _Bs_  String _As_ _Bs_  [3]; \n" +
                    "        return (_As_ _Bs_  String) null; \n" +
                    "} \n" +
                    "} \n").concat(sourceBase).replace("_OTHER_", annot2).replace("_As_",As).replace("_Bs_",Bs) +
                    "\n\n";
                    break;
            case src2: 
                    
                source = new String( source +
                    "// " + src.description + "\n" +
                    "class " + testname + "<T extends Object> {\n" +
                    "    Map<List<String>, Integer> map =\n" +
                    "        new HashMap<_As_ _Bs_ List<_As_ _Bs_ String>, _As_ _Bs_ Integer>();\n" +
                    "    Map<List<String>, Integer> map2 = new _As_ _Bs_ HashMap<>();\n" +
                    "    String test(" + testname + "<T> this) { return null;}\n" +
                    "    <T> String genericMethod(T t) { return null; }\n" +
                    "}\n").concat(sourceBase).replace("_OTHER_", annot2).replace("_As_",As).replace("_Bs_",Bs) +
                    "\n\n";
                break;
            case src3: 
                    
                source = new String( source +
                    "// " + src.description + "\n" +
                    "class "+ testname + "{\n" +
                    "    <E extends Comparable> Map<List<E>, E > foo(E e) {\n" +
                    "        class maptest <E> {\n" +                  
                    "            Map<List<E>,E> getMap() { \n" +
                    "                Map<List<E>,E> Em = new HashMap<List<_As_ _Bs_ _Ds_ E>,_As_ _Bs_ _Ds_ E>();\n" +
                    "                return Em;\n" +
                    "            }\n" +
                    "        }\n" +
                    "        return new maptest<E>().getMap();\n" +
                    "   }\n" +
                    "   Map<List<String>,String> shm = foo(new String(\"hello\"));\n" +
                    "}\n").concat(sourceBase).replace("_OTHER_", annot2).replace("_As_",As).replace("_Bs_",Bs).replace("_Ds_",Ds) +
                    "\n\n";
                    hasInnerClass=true;
                    innerClassname="$1maptest";
                break;
            case src4: 
                    
                source = new String( source +
                    "// " + src.description + "\n" +
                    "class "+ testname + "{\n" +
                    "    void mtest( "+ testname + " t){  }\n" +
                    "    public void test() {\n" +
                    "        mtest( new "+ testname + "() {\n" +
                    "            _As_ _Bs_ String data2 = \"test\";\n" +
                    "        });\n" +
                    "    }\n" +
                    "}\n").concat(sourceBase).replace("_OTHER_", annot2).replace("_As_",As).replace("_Bs_",Bs) +
                    "\n\n";
                    hasInnerClass=true;
                    innerClassname="$1";
                break;
            case src5: 
                    
                source = new String( source +
                    "// " + src.description + "\n" +
                    "class "+ testname + "{\n" +
                    "    void mtest( "+ testname + " t){  }\n" +
                    "    public void test() {\n" +
                    "        mtest( new "+ testname + "() {\n" +
                    "            _As_ _Bs_ String m2(){return null;};\n" +
                    "        });\n" +
                    "    }\n" +
                    "}\n").concat(sourceBase).replace("_OTHER_", annot2).replace("_As_",As).replace("_Bs_",Bs) +
                    "\n\n";
                    hasInnerClass=true;
                    innerClassname="$1";
                break;
            case src6: 
                    
                source = new String( source +
                    "// " + src.description + "\n" +
                    "class "+ testname + "{\n" +
                    "    _As_ _Bs_ public void test() { }\n" +
                    "}\n").concat(sourceBase).replace("_OTHER_", annot2).replace("_As_",As).replace("_Bs_",Bs) +
                    "\n\n";
                    hasInnerClass=false;
                break;
            case src7: 
                    
                source = new String( source +
                    "// " + src.description + "\n" +
                    "class "+ testname + "{\n" +
                    "    String data = \"test\";\n" +
                    "    boolean dataIsString = ( data instanceof _As_ _Bs_ String);\n" +
                    "}\n").concat(sourceBase).replace("_OTHER_", annot2).replace("_As_",As).replace("_Bs_",Bs) +
                    "\n\n";
                    hasInnerClass=false;
                break;
            case src8: 
                    
                source = new String( source +
                    "// " + src.description + "\n" +
                    "class "+ testname + "{\n" +
                    "    String data = \"test\";\n" +
                    "    Boolean isString() { \n" +
                    "        if( data instanceof _As_ _Bs_ String )\n" +
                    "            return true;\n" +
                    "        else\n" +
                    "            return( data instanceof _As_ _Bs_ String );\n" +
                    "    }\n" +
                    "}\n").concat(sourceBase).replace("_OTHER_", annot2).replace("_As_",As).replace("_Bs_",Bs) +
                    "\n\n";
                    hasInnerClass=false;
                break;

        }
        return imports + source;
    }
}
