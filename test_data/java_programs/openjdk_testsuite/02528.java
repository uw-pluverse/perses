


import java.lang.annotation.*;
import java.io.*;
import java.util.List;
import java.util.LinkedList;
import com.sun.tools.classfile.*;
import java.nio.file.Files;
import java.nio.charset.*;
import java.io.File;
import java.io.IOException;


import java.lang.annotation.*;
import static java.lang.annotation.RetentionPolicy.*;
import static java.lang.annotation.ElementType.*;


public class TestAnonInnerClasses extends ClassfileTestHelper {
    
    int errors = 0;
    int checks = 0;
    
    int tc = 0, xtc = 180; 
    File testSrc = new File(System.getProperty("test.src"));

    String[] AnnoAttributes = {
        Attribute.RuntimeVisibleTypeAnnotations,
        Attribute.RuntimeInvisibleTypeAnnotations,
        Attribute.RuntimeVisibleAnnotations,
        Attribute.RuntimeInvisibleAnnotations
    };

    
    String srcTemplate = "testanoninner.template";

    
    Boolean As= false, Bs=true, Cs=false, Ds=false, TAs=false,TBs=false;
    Boolean[][] bRepeat = new Boolean[][]{
                  {false, false, false, false, false, false},
                  {true,  false, true,  false, true,  false},
                  {false, true,  false, true,  false, true},
                  {true,  true,  true,  true,  true,  true}
    };
    
    List<String> failed = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        new TestAnonInnerClasses().run();
    }

    
    
    void check(String testcase, int vtaX, int itaX, int vaX, int iaX,
                                int vtaA, int itaA, int vaA, int iaA) {

        String descr = " checking " + testcase+" _TYPE_, expected: " +
            vtaX + ", " + itaX + ", " + vaX + ", " + iaX + "; actual: " +
            vtaA + ", " + itaA + ", " + vaA + ", " + iaA;
        String description;
        description=descr.replace("_TYPE_","RuntimeVisibleTypeAnnotations");
        if (vtaX != vtaA) {
            errors++;
            failed.add(++checks + " " + testcase + ": (vtaX) " + vtaX +
                       " != " + vtaA + " (vtaA)");
            println(checks + " FAIL: " + description);
        } else {
            println(++checks + " PASS: " + description);
        }
        description=descr.replace("_TYPE_","RuntimeInvisibleTypeAnnotations");
        if (itaX != itaA) {
            errors++;
            failed.add(++checks + " " + testcase + ": (itaX) " + itaX + " != " +
                       itaA + " (itaA)");
            println(checks + " FAIL: " + description);
        } else {
            println(++checks + " PASS: " + description);
        }
        description=descr.replace("_TYPE_","RuntimeVisibleAnnotations");
        if (vaX != vaA) {
            errors++;
            failed.add(++checks + " " + testcase + ": (vaX) " + vaX + " != " +
                       vaA + " (vaA)");
            println(checks + " FAIL: " + description);
        } else {
            println(++checks + " PASS: " + description);
        }
        description=descr.replace("_TYPE_","RuntimeInvisibleAnnotations");
        if (iaX != iaA) {
            errors++;
            failed.add(++checks + " " + testcase + ": (iaX) " + iaX + " != " +
                       iaA + " (iaA)");
            println(checks + " FAIL: " + description);
        } else {
            println(++checks + " PASS: " + description);
        }
        println("");
    }

    
    void report() {
        if (errors!=0) {
            System.err.println("Failed tests: " + errors +
                               "\nfailed test cases:\n");
            for (String t: failed) System.err.println("  " + t);
            throw new RuntimeException("FAIL: There were test failures.");
        } else
            System.out.println("PASSED all tests.");
    }

    void test(String ttype, ClassFile cf, Method m, Field f, boolean visible) {
        int vtaActual = 0,
            itaActual = 0,
            vaActual = 0,
            iaActual = 0,
            vtaExp = 0,
            itaExp = 0,
            vaExp = 0,
            iaExp = 0,
            index = 0,
            index2 = 0;
        String memberName = null,
            testcase = "undefined",
            testClassName = null;
        Attribute attr = null,
            cattr = null;
        Code_attribute CAttr = null;
        
        for (String AnnoType : AnnoAttributes) {
            try {
                switch (ttype) {
                    case "METHOD":
                        index = m.attributes.getIndex(cf.constant_pool,
                                                      AnnoType);
                        memberName = m.getName(cf.constant_pool);
                        if (index != -1)
                            attr = m.attributes.get(index);
                        
                        index2 = m.attributes.getIndex(cf.constant_pool,
                                                       Attribute.Code);
                        if (index2 != -1) {
                            cattr = m.attributes.get(index2);
                            assert cattr instanceof Code_attribute;
                            CAttr = (Code_attribute)cattr;
                            index2 = CAttr.attributes.getIndex(cf.constant_pool,
                                                               AnnoType);
                            if (index2 != -1)
                                cattr = CAttr.attributes.get(index2);
                        }
                        break;
                    case "FIELD":
                        index = f.attributes.getIndex(cf.constant_pool,
                                                      AnnoType);
                        memberName = f.getName(cf.constant_pool);
                        if (index != -1)
                            attr = f.attributes.get(index);
                        
                        index2 = cf.attributes.getIndex(cf.constant_pool,
                                                        Attribute.Code);
                        if (index2!= -1) {
                            cattr = cf.attributes.get(index2);
                            assert cattr instanceof Code_attribute;
                            CAttr = (Code_attribute)cattr;
                            index2 = CAttr.attributes.getIndex(cf.constant_pool,
                                                               AnnoType);
                            if (index2!= -1)
                                cattr = CAttr.attributes.get(index2);
                        }
                        break;

                    default:
                        memberName = cf.getName();
                        index = cf.attributes.getIndex(cf.constant_pool,
                                                       AnnoType);
                        if (index!= -1) attr = cf.attributes.get(index);
                        break;
                }
            }
            catch (ConstantPoolException cpe) { cpe.printStackTrace(); }
            try {
                testClassName=cf.getName();
                testcase = ttype + ": " + testClassName + ": " +
                           memberName + ", ";
            }
            catch (ConstantPoolException cpe) { cpe.printStackTrace(); }
            if (index != -1) {
                switch (AnnoType) {
                    case Attribute.RuntimeVisibleTypeAnnotations:
                        
                        RuntimeVisibleTypeAnnotations_attribute RVTAa =
                                (RuntimeVisibleTypeAnnotations_attribute)attr;
                        vtaActual += RVTAa.annotations.length;
                        break;
                    case Attribute.RuntimeVisibleAnnotations:
                        
                        RuntimeVisibleAnnotations_attribute RVAa =
                                (RuntimeVisibleAnnotations_attribute)attr;
                        vaActual += RVAa.annotations.length;
                        break;
                    case Attribute.RuntimeInvisibleTypeAnnotations:
                        
                        RuntimeInvisibleTypeAnnotations_attribute RITAa =
                                (RuntimeInvisibleTypeAnnotations_attribute)attr;
                        itaActual += RITAa.annotations.length;
                        break;
                    case Attribute.RuntimeInvisibleAnnotations:
                        
                        RuntimeInvisibleAnnotations_attribute RIAa =
                                (RuntimeInvisibleAnnotations_attribute)attr;
                        iaActual += RIAa.annotations.length;
                        break;
                }
            }
            
            if (index2 != -1) {
                switch (AnnoType) {
                    case Attribute.RuntimeVisibleTypeAnnotations:
                        
                        RuntimeVisibleTypeAnnotations_attribute RVTAa =
                                (RuntimeVisibleTypeAnnotations_attribute)cattr;
                        vtaActual += RVTAa.annotations.length;
                        break;
                    case Attribute.RuntimeVisibleAnnotations:
                        
                        RuntimeVisibleAnnotations_attribute RVAa =
                                (RuntimeVisibleAnnotations_attribute)cattr;
                        vaActual += RVAa.annotations.length;
                        break;
                    case Attribute.RuntimeInvisibleTypeAnnotations:
                        
                        RuntimeInvisibleTypeAnnotations_attribute RITAa =
                                (RuntimeInvisibleTypeAnnotations_attribute)cattr;
                        itaActual += RITAa.annotations.length;
                        break;
                    case Attribute.RuntimeInvisibleAnnotations:
                        
                        RuntimeInvisibleAnnotations_attribute RIAa =
                                (RuntimeInvisibleAnnotations_attribute)cattr;
                        iaActual += RIAa.annotations.length;
                        break;
                }
            }
        }

        switch (memberName) {
            
            case "test" : vtaExp=4;  itaExp=4;  vaExp=0; iaExp=0; tc++; break;
            case "mtest": vtaExp=4;  itaExp=4;  vaExp=1; iaExp=1; tc++; break;
            case "m1":    vtaExp=2;  itaExp=2;  vaExp=1; iaExp=1; tc++; break;
            case "m2":    vtaExp=4;  itaExp=4;  vaExp=1; iaExp=1; tc++; break;
            case "m3":    vtaExp=10; itaExp=10; vaExp=1; iaExp=1; tc++; break;
            case "tm":    vtaExp=6;  itaExp=6;  vaExp=1; iaExp=1; tc++; break;
            
            case "i_m1":  vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "i_m2":  vtaExp=4;  itaExp=4; vaExp=1; iaExp=1; tc++; break;
            case "i_um":  vtaExp=6;  itaExp=6; vaExp=1; iaExp=1; tc++; break;
            
            case "l_m1":  vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "l_m2":  vtaExp=4;  itaExp=4; vaExp=1; iaExp=1; tc++; break;
            case "l_um":  vtaExp=6;  itaExp=6; vaExp=1; iaExp=1; tc++; break;
            
            case "mm_m1": vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "mm_m2": vtaExp=4;  itaExp=4; vaExp=1; iaExp=1; tc++; break;
            case "mm_m3": vtaExp=10; itaExp=10;vaExp=1; iaExp=1; tc++; break;
            case "mm_tm": vtaExp=6;  itaExp=6; vaExp=1; iaExp=1; tc++; break;
            
            case "ia_m1": vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "ia_m2": vtaExp=4;  itaExp=4; vaExp=1; iaExp=1; tc++; break;
            case "ia_um": vtaExp=6;  itaExp=6; vaExp=1; iaExp=1; tc++; break;
            
            case "data":   vtaExp = 2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "odata1": vtaExp = 2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "pdata1": vtaExp = 2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "tdata":  vtaExp = 2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "sa1":    vtaExp = 6;  itaExp=6; vaExp=1; iaExp=1; tc++; break;
            
            case "i_odata1":  vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "i_pdata1":  vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "i_udata":   vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "i_sa1":     vtaExp=6;  itaExp=6; vaExp=1; iaExp=1; tc++; break;
            case "i_tdata":   vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            
            case "l_odata1":  vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "l_pdata1":  vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "l_udata":   vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "l_sa1":     vtaExp=6;  itaExp=6; vaExp=1; iaExp=1; tc++; break;
            case "l_tdata":   vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            
            case "mm_odata1": vtaExp = 2; itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "mm_pdata1": vtaExp = 2; itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "mm_sa1":    vtaExp = 6; itaExp=6; vaExp=1; iaExp=1; tc++; break;
            case "mm_tdata":  vtaExp = 2; itaExp=2; vaExp=1; iaExp=1; tc++; break;
            
            case "ia_odata1": vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "ia_pdata1": vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "ia_udata":  vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "ia_sa1":    vtaExp=6;  itaExp=6; vaExp=1; iaExp=1; tc++; break;
            case "ia_tdata":  vtaExp=2;  itaExp=2; vaExp=1; iaExp=1; tc++; break;
            case "IA":        vtaExp=4;  itaExp=4; vaExp=1; iaExp=1; tc++; break;
            case "IN":        vtaExp=4;  itaExp=4; vaExp=1; iaExp=1; tc++; break;
            
            default:          vtaExp = 0;  itaExp=0; vaExp=0; iaExp=0;    break;
        }
        check(testcase,vtaExp,   itaExp,   vaExp,   iaExp,
                       vtaActual,itaActual,vaActual,iaActual);
    }

    public void run() {
        ClassFile cf   = null;
        InputStream in = null;
        int testcount  = 1;
        File testFile  = null;
        
        for (Boolean[] bCombo : bRepeat) {
            As=bCombo[0]; Bs=bCombo[1]; Cs=bCombo[2];
            Ds=bCombo[3]; TAs=bCombo[4]; TBs=bCombo[5];
            String testname = "Test" + testcount++;
            println("Combinations: " + As + ", " + Bs + ", " + Cs + ", " + Ds +
                    ", " + TAs + ", " + TBs +
                    "; see " + testname + ".java");
            String[] classes = {testname + ".class",
                                testname + "$Inner.class",
                                testname + "$1Local1.class",
                                testname + "$1.class",
                                testname + "$1$1.class",
                                testname + "$1$InnerAnon.class"
            };
            
            String sourceString = getSource(srcTemplate, testname,
                                            As, Bs, Cs, Ds, TAs, TBs);
            System.out.println(sourceString);
            try {
                testFile = writeTestFile(testname+".java", sourceString);
            }
            catch (IOException ioe) { ioe.printStackTrace(); }
            
            File classFile = null;
            try {
                classFile = compile(testFile);
            }
            catch (Error err) {
                System.err.println("FAILED compile. Source:\n" + sourceString);
                throw err;
            }
            String testloc = classFile.getAbsolutePath().substring(
                   0,classFile.getAbsolutePath().indexOf(classFile.getPath()));
            for (String clazz : classes) {
                try {
                    cf = ClassFile.read(new File(testloc+clazz));
                }
                catch (Exception e) { e.printStackTrace();  }
                
                for (Method m: cf.methods) {
                    test("METHOD", cf, m, null, true);
                }
                for (Field f: cf.fields) {
                    test("FIELD", cf, null, f, true);
                }
            }
        }
        report();
        if (tc!=xtc) System.out.println("Test Count: " + tc + " != " +
                                       "expected: " + xtc);
    }


    String getSrcTemplate(String sTemplate) {
        List<String> tmpl = null;
        String sTmpl = "";
        try {
            tmpl = Files.readAllLines(new File(testSrc,sTemplate).toPath(),
                                      Charset.defaultCharset());
        }
        catch (IOException ioe) {
            String error = "FAILED: Test failed to read template" + sTemplate;
            ioe.printStackTrace();
            throw new RuntimeException(error);
        }
        for (String l : tmpl)
            sTmpl=sTmpl.concat(l).concat("\n");
        return sTmpl;
    }

    
    String getSource(String templateName, String testname,
                     Boolean Arepeats,  Boolean Brepeats,
                     Boolean Crepeats,  Boolean Drepeats,
                     Boolean TArepeats, Boolean TBrepeats) {
        String As  = Arepeats  ? "@A @A":"@A",
               Bs  = Brepeats  ? "@B @B":"@B",
               Cs  = Crepeats  ? "@C @C":"@C",
               Ds  = Drepeats  ? "@D @D":"@D",
               TAs = TArepeats ? "@TA @TA":"@TA",
               TBs = TBrepeats ? "@TB @TB":"@TB";

        
        String testsource = getSrcTemplate(templateName).replace("testname",testname);
        testsource = testsource.replace("_As",As).replace("_Bs",Bs).replace("_Cs",Cs);
        testsource = testsource.replace("_Ds",Ds).replace("_TAs",TAs).replace("_TBs",TBs);
        return testsource;
    }
}
