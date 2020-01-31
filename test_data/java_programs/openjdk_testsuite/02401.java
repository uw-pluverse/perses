


import java.io.File;
import java.io.IOException;
import java.lang.annotation.Annotation;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import javax.tools.DiagnosticCollector;
import javax.tools.JavaFileObject;

import expectedFiles.ExpectedBase;
import expectedFiles.ExpectedContainer;
import java.util.Iterator;
import java.util.regex.Pattern;


public class ReflectionTest {

    static int errors = 0;
    
    static final String TESTPKG = "testpkg";
    static final String TESTMETHOD = "testMethod";
    static final String TESTFIELD = "testField";
    static final String PKGINFONAME = TESTPKG + ".package-info";
    static final String SUPERCLASS = "SuperClass";
    static final String TESTINTERFACE = "TestInterface";
    
    static final boolean DEBUG = false;
    static boolean CHECKORDERING;

    public static void main(String args[]) throws Exception {
        ReflectionTest test = new ReflectionTest();
        test.runTest();
    }

    public void runTest() throws Exception {

        ClassLoader parentClassLoader = getLoader();
        String className = "";
        Iterable<? extends JavaFileObject> files = null;

        for (SrcType srcType : SrcType.getSrcTypes()) {
            for (TestCase testCase : TestCase.values()) {
                className = testCase + "_" + srcType;
                debugPrint("*****************************************");
                System.out.println("Running Test for ClassName: " + className);

                
                
                if (testCase.name().contains("Inherited")
                        && (srcType != SrcType.CLASS)) {
                    continue;
                }

                
                files = testCase.getTestFiles(srcType, className);
                if (srcType == SrcType.PACKAGE) {
                    className = TESTPKG + "." + className;
                }
                DiagnosticCollector<JavaFileObject> diagnostics = new DiagnosticCollector<>();

                
                try {
                    Helper.compileCode(diagnostics, files);
                } catch (Exception ex) {
                    printTestSrc(files);
                    throw new RuntimeException(
                            "Exception when compiling class " + className, ex);
                }

                
                Class<?> c = loadClass(className, parentClassLoader, Helper.destDir);
                if (c != null) {
                    
                    


                    
                    
                    
                    
                    List<String> orderingTestFailures = Arrays.asList(
                            "SingleOnSuperContainerOnSub_Inherited_Legacy",
                            "SingleOnSuperContainerAndSingleOnSub_Inherited_Legacy",
                            "ContainerAndSingleOnSuperSingleOnSub_Inherited_Legacy",
                            "SingleAnnoWithContainer",
                            "SingleOnSuperContainerAndSingleOnSub_Inherited",
                            "RepeatableOnSuperSingleOnSub_Inherited",
                            "SingleOnSuperRepeatableOnSub_Inherited",
                            "ContainerOnSuperSingleOnSub_Inherited",
                            "SingleOnSuperContainerOnSub_Inherited",
                            "ContainerAndSingleOnSuperSingleOnSub_Inherited");
                    if (orderingTestFailures.contains(testCase.toString())) {
                        CHECKORDERING = false;
                    } else
                        CHECKORDERING = true;

                    checkAnnoValues(srcType, c);
                } else {
                    error("Could not load className = " + c);
                }
            }
        }

        if (getNumErrors() > 0) {
            System.err.println("Test failed with " + getNumErrors() + " errors");
            throw new RuntimeException();
        }
    }

    
    enum TestCase {
        BasicNonRepeatable_Legacy(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=0)\", "
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\"}, "
                + "getDeclAnnoVal = \"@Foo(value=0)\", "
                + "getAnnosArgs = {\"@Foo(value=0)\"}, "
                + "getDeclAnnosArgs = {\"@Foo(value=0)\"}) ",
        "@ExpectedContainer") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String testSrc = "";
                String pkgInfoContents = "";
                String contents = "";

                JavaFileObject pkgFileObj = null;
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = new StringBuilder();
                anno = Helper.ContentVars.BASEANNO.getVal();
                commonStmts.append(Helper.ContentVars.IMPORTEXPECTED.getVal())
                        .append(Helper.ContentVars.IMPORTSTMTS.getVal())
                        .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
                        .append(Helper.ContentVars.BASE.getVal());
                switch (srcType) {
                    case PACKAGE:
                        
                        testSrc = srcType.getTemplate().replace("#CN", className);
                        contents = testSrc;
                        srcFileObj = Helper.getFile(className, contents);

                        replaceVal = expectedVals + "\n" + anno;
                        pkgInfoContents = SrcType.PKGINFO.getTemplate()
                                .replace("#REPLACE1", replaceVal)
                                .replace("#REPLACE2", commonStmts);
                        pkgFileObj = Helper.getFile(PKGINFONAME, pkgInfoContents);

                        files = Arrays.asList(pkgFileObj, srcFileObj);
                        break;
                    default:
                        
                    
                        replaceVal = expectedVals + anno;
                        testSrc = srcType.getTemplate().replace("#CN", className)
                                .replace("#REPLACE", replaceVal);
                        contents = commonStmts + testSrc;
                        srcFileObj = Helper.getFile(className, contents);
                        files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        SingleAnnoInherited_Legacy(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=0)\", "
                + "getAnnotationsVals = {\"@Foo(value=0)\", \"ExpectedBase\", \"ExpectedContainer\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\"}, "
                + "getDeclAnnoVal = \"NULL\", "
                + "getAnnosArgs = {\"@Foo(value=0)\"}, "
                + "getDeclAnnosArgs = {})",
        "@ExpectedContainer") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = new StringBuilder();

                

                
                
                anno = Helper.ContentVars.BASEANNO.getVal();
                commonStmts.append(Helper.ContentVars.IMPORTEXPECTED.getVal())
                        .append(Helper.ContentVars.IMPORTSTMTS.getVal())
                        .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
                        .append(Helper.ContentVars.INHERITED.getVal())
                        .append(Helper.ContentVars.BASE.getVal());

                if (srcType == SrcType.CLASS) {
                    
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS).replace("#REPLACE", replaceVal);

                    
                    replaceVal = expectedVals;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className).replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        InheritedAnnoOnInterface_Legacy(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"NULL\", "
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\"},"
                + "getDeclAnnoVal = \"NULL\"," + "getAnnosArgs = {},"
                + "getDeclAnnosArgs = {})",
        "@ExpectedContainer") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = new StringBuilder();

                
                anno = Helper.ContentVars.BASEANNO.getVal();
                commonStmts.append(Helper.ContentVars.IMPORTEXPECTED.getVal())
                        .append(Helper.ContentVars.IMPORTSTMTS.getVal())
                        .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
                        .append(Helper.ContentVars.INHERITED.getVal())
                        .append(Helper.ContentVars.BASE.getVal());

                if (srcType == SrcType.CLASS) {
                    
                    replaceVal = commonStmts + "\n" + anno;
                    String interfaceContents = SrcType.INTERFACE.getTemplate()
                            .replace("#IN", TESTINTERFACE)
                            .replace("#REPLACE", replaceVal);

                    
                    replaceVal = expectedVals;
                    String classContents = SrcType.INTERFACEIMPL.getTemplate()
                            .replace("#CN", className).replace("#IN", TESTINTERFACE)
                            .replace("#REPLACE", replaceVal);

                    contents = interfaceContents + classContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        AnnoOnSuperAndSubClass_Inherited_Legacy(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=2)\", "
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=2)\"}, "
                + 
                "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=2)\"}, "
                + 
                "getDeclAnnoVal = \"@Foo(value=2)\", " 
                + "getAnnosArgs = {\"@Foo(value=2)\"}, "
                + "getDeclAnnosArgs = { \"@Foo(value=2)\" })", 
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"NULL\", "
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=2)\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=2)\"}, "
                + 
                "getDeclAnnoVal = \"NULL\", " + 
                "getAnnosArgs = {}, " + "getDeclAnnosArgs = {})") { 

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = new StringBuilder();

                
                
                
                commonStmts.append(Helper.ContentVars.IMPORTEXPECTED.getVal())
                        .append(Helper.ContentVars.IMPORTSTMTS.getVal())
                        .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
                        .append(Helper.ContentVars.INHERITED.getVal())
                        .append(Helper.ContentVars.BASE.getVal())
                        .append(Helper.ContentVars.INHERITED.getVal())
                        .append(Helper.ContentVars.CONTAINER.getVal());

                if (srcType == SrcType.CLASS) {
                    
                    anno = "@Foo(1)";
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS).replace("#REPLACE", replaceVal);

                    
                    anno = "@Foo(2)";
                    replaceVal = expectedVals + "\n" + anno;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className).replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        BasicContainer_Legacy(
        "@ExpectedBase(value = Foo.class, "
                + "getAnnotationVal = \"NULL\","
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnoVal = \"NULL\", " + "getAnnosArgs = {}, "
                + "getDeclAnnosArgs = {} )",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnoVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"} )") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String testSrc = "";
                String pkgInfoContents = "";
                String contents = "";

                JavaFileObject pkgFileObj = null;
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = new StringBuilder();

                anno = Helper.ContentVars.LEGACYCONTAINER.getVal();
                commonStmts.append(Helper.ContentVars.IMPORTEXPECTED.getVal())
                        .append(Helper.ContentVars.IMPORTSTMTS.getVal())
                        .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
                        .append(Helper.ContentVars.BASE.getVal())
                        .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
                        .append(Helper.ContentVars.CONTAINER.getVal());
                switch (srcType) {
                    case PACKAGE:
                        
                        testSrc = srcType.getTemplate().replace("#CN", className);
                        contents = testSrc;
                        srcFileObj = Helper.getFile(className, contents);

                        replaceVal = "\n" + expectedVals + "\n" + anno;
                        pkgInfoContents = SrcType.PKGINFO.getTemplate()
                                .replace("#REPLACE1", replaceVal)
                                .replace("#REPLACE2", commonStmts);
                        pkgFileObj = Helper.getFile(PKGINFONAME, pkgInfoContents);
                        files = Arrays.asList(pkgFileObj, srcFileObj);
                        break;
                    default:
                        
                        replaceVal = expectedVals + anno;
                        testSrc = srcType.getTemplate().replace("#CN", className)
                                .replace("#REPLACE", replaceVal);
                        contents = commonStmts + testSrc;
                        srcFileObj = Helper.getFile(className, contents);
                        files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        SingleAndContainerOnSuper_Legacy(
        "@ExpectedBase(value = Foo.class, "
                + "getAnnotationVal = \"@Foo(value=0)\","
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnoVal = \"@Foo(value=0)\", "
                + "getAnnosArgs = {\"@Foo(value=0)\"}, "
                + "getDeclAnnosArgs = {\"@Foo(value=0)\"} )",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnoVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"} )") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String testSrc = "";
                String pkgInfoContents = "";
                String contents = "";

                JavaFileObject pkgFileObj = null;
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = new StringBuilder();

                anno = Helper.ContentVars.BASEANNO.getVal() +
                       Helper.ContentVars.LEGACYCONTAINER.getVal();
                commonStmts.append(Helper.ContentVars.IMPORTEXPECTED.getVal())
                        .append(Helper.ContentVars.IMPORTSTMTS.getVal())
                        .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
                        .append(Helper.ContentVars.BASE.getVal())
                        .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
                        .append(Helper.ContentVars.CONTAINER.getVal());
                switch (srcType) {
                    case PACKAGE:
                        
                        testSrc = srcType.getTemplate().replace("#CN", className);
                        contents = testSrc;

                        srcFileObj = Helper.getFile(className, contents);

                        replaceVal = "\n" + expectedVals + "\n" + anno;
                        pkgInfoContents = SrcType.PKGINFO.getTemplate()
                                .replace("#REPLACE1", replaceVal)
                                .replace("#REPLACE2", commonStmts);
                        pkgFileObj = Helper.getFile(PKGINFONAME, pkgInfoContents);
                        files = Arrays.asList(pkgFileObj, srcFileObj);
                        break;
                    default:
                        
                        replaceVal = expectedVals + anno;
                        testSrc = srcType.getTemplate().replace("#CN", className)
                                .replace("#REPLACE", replaceVal);
                        contents = commonStmts + testSrc;

                        srcFileObj = Helper.getFile(className, contents);
                        files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        BasicContainer_Inherited_Legacy(
        "@ExpectedBase(value = Foo.class, "
                + "getAnnotationVal = \"NULL\","
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\"}, "
                + "getDeclAnnoVal = \"NULL\", "
                + "getAnnosArgs = {}, "
                + "getDeclAnnosArgs = {} )",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\"}, "
                + "getDeclAnnoVal = \"NULL\", "
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosArgs = {} )") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = getCommonStmts(false);

                
                
                

                if (srcType == SrcType.CLASS) {
                    
                    anno = Helper.ContentVars.LEGACYCONTAINER.getVal();
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    
                    replaceVal = expectedVals;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className)
                            .replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        ContainerOnSuperSingleOnSub_Inherited_Legacy(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=0)\", "
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", \"@Foo(value=0)\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\"},"
                + "getDeclAnnoVal = \"@Foo(value=0)\","
                + "getAnnosArgs = {\"@Foo(value=0)\"},"
                + "getDeclAnnosArgs = {\"@Foo(value=0)\"})",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", \"@Foo(value=0)\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\"},"
                + "getDeclAnnoVal = \"NULL\","
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnosArgs = {})") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = getCommonStmts(false);

                
                
                

                if (srcType == SrcType.CLASS) {
                    
                    anno = Helper.ContentVars.LEGACYCONTAINER.getVal();
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    
                    anno = Helper.ContentVars.BASEANNO.getVal();
                    replaceVal = expectedVals + "\n" + anno;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className)
                            .replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        
        
        ContainerAndSingleOnSuperSingleOnSub_Inherited_Legacy(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=0)\", "
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", \"@Foo(value=0)\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\"},"
                + "getDeclAnnoVal = \"@Foo(value=0)\","
                + "getAnnosArgs = {\"@Foo(value=0)\"},"
                + "getDeclAnnosArgs = {\"@Foo(value=0)\"})",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", \"@Foo(value=0)\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\"},"
                + "getDeclAnnoVal = \"NULL\","
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnosArgs = {})") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = getCommonStmts(false);

                
                
                

                if (srcType == SrcType.CLASS) {
                    
                    anno = Helper.ContentVars.LEGACYCONTAINER.getVal()
                            + "@Foo(3)";
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    
                    anno = Helper.ContentVars.BASEANNO.getVal();
                    replaceVal = expectedVals + "\n" + anno;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className).replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        
        
        SingleOnSuperContainerOnSub_Inherited_Legacy(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=0)\", "
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnoVal = \"NULL\","
                + "getAnnosArgs = {\"@Foo(value=0)\"},"
                + "getDeclAnnosArgs = {})",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnoVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\","
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"})") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";

                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = getCommonStmts(false);

                

                if (srcType == SrcType.CLASS) {
                    
                    anno = Helper.ContentVars.BASEANNO.getVal();
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    
                    anno = Helper.ContentVars.LEGACYCONTAINER.getVal();
                    replaceVal = expectedVals + "\n" + anno;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className).replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        
        
        SingleOnSuperContainerAndSingleOnSub_Inherited_Legacy(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=3)\", "
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", \"@Foo(value=3)\"}, "
                + "getDeclAnnosVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", \"@Foo(value=3)\"},"
                + "getDeclAnnoVal = \"@Foo(value=3)\","
                + "getAnnosArgs = {\"@Foo(value=3)\"},"
                + "getDeclAnnosArgs = {\"@Foo(value=3)\"})",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", \"@Foo(value=3)\"}, "
                + "getDeclAnnosVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", \"@Foo(value=3)\"},"
                + "getDeclAnnoVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\","
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"})") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";

                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = getCommonStmts(false);

                

                if (srcType == SrcType.CLASS) {
                    
                    anno = Helper.ContentVars.BASEANNO.getVal();
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    
                    anno = Helper.ContentVars.LEGACYCONTAINER.getVal()
                            + "@Foo(3)";
                    replaceVal = expectedVals + "\n" + anno;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className).replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        BasicRepeatable(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"NULL\", "
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\" }, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnoVal = \"NULL\","
                + "getAnnosArgs = {\"@Foo(value=1)\", \"@Foo(value=2)\"},"
                + "getDeclAnnosArgs = {\"@Foo(value=1)\", \"@Foo(value=2)\"})",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\","
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnoVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\","
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"} )") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String testSrc = "";
                String pkgInfoContents = "";
                String contents = "";

                JavaFileObject pkgFileObj = null;
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = new StringBuilder();

                anno = Helper.ContentVars.REPEATABLEANNO.getVal();
                commonStmts.append(Helper.ContentVars.IMPORTEXPECTED.getVal())
                        .append(Helper.ContentVars.IMPORTSTMTS.getVal())
                        .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
                        .append(Helper.ContentVars.REPEATABLE.getVal())
                        .append(Helper.ContentVars.BASE.getVal())
                        .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
                        .append(Helper.ContentVars.CONTAINER.getVal());
                switch (srcType) {
                    case PACKAGE:
                        
                        testSrc = srcType.getTemplate().replace("#CN", className);
                        contents = testSrc;
                        srcFileObj = Helper.getFile(className, contents);

                        replaceVal = expectedVals + "\n" + anno;
                        pkgInfoContents = SrcType.PKGINFO.getTemplate()
                                .replace("#REPLACE1", replaceVal)
                                .replace("#REPLACE2", commonStmts);
                        pkgFileObj = Helper.getFile(PKGINFONAME, pkgInfoContents);
                        files = Arrays.asList(pkgFileObj, srcFileObj);
                        break;
                    default:
                        
                        replaceVal = expectedVals + anno;
                        testSrc = srcType.getTemplate().replace("#CN", className)
                                .replace("#REPLACE", replaceVal);
                        contents = commonStmts + testSrc;
                        srcFileObj = Helper.getFile(className, contents);
                        files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        BasicContainerRepeatable(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"NULL\", "
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnoVal = \"NULL\","
                + "getAnnosArgs = {\"@Foo(value=1)\", \"@Foo(value=2)\"},"
                + "getDeclAnnosArgs = {\"@Foo(value=1)\", \"@Foo(value=2)\"})",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\","
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnosVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnoVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\","
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"} )") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String testSrc = "";
                String pkgInfoContents = "";
                String contents = "";

                JavaFileObject pkgFileObj = null;
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = new StringBuilder();

                anno = Helper.ContentVars.LEGACYCONTAINER.getVal();
                commonStmts.append(Helper.ContentVars.IMPORTEXPECTED.getVal())
                        .append(Helper.ContentVars.IMPORTSTMTS.getVal())
                        .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
                        .append(Helper.ContentVars.REPEATABLE.getVal())
                        .append(Helper.ContentVars.BASE.getVal())
                        .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
                        .append(Helper.ContentVars.CONTAINER.getVal());
                switch (srcType) {
                    case PACKAGE:
                        
                        testSrc = srcType.getTemplate().replace("#CN", className);
                        contents = testSrc;
                        srcFileObj = Helper.getFile(className, contents);

                        replaceVal = expectedVals + "\n" + anno;
                        pkgInfoContents = SrcType.PKGINFO.getTemplate()
                                .replace("#REPLACE1", replaceVal)
                                .replace("#REPLACE2", commonStmts);
                        pkgFileObj = Helper.getFile(PKGINFONAME, pkgInfoContents);
                        files = Arrays.asList(pkgFileObj, srcFileObj);
                        break;
                    default:
                        
                        replaceVal = expectedVals + anno;
                        testSrc = srcType.getTemplate().replace("#CN", className)
                                .replace("#REPLACE", replaceVal);
                        contents = commonStmts + testSrc;
                        srcFileObj = Helper.getFile(className, contents);
                        files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        BasicContainerRepeatable_Inherited(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"NULL\", "
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\"}, "
                + "getDeclAnnoVal = \"NULL\", "
                + "getAnnosArgs = {\"@Foo(value=1)\", \"@Foo(value=2)\"}, "
                + "getDeclAnnosArgs = {})",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = { \"ExpectedBase\", \"ExpectedContainer\"}, "
                + "getDeclAnnoVal = \"NULL\", "
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosArgs = {})") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = getCommonStmts(true);
                
                
                
                anno = Helper.ContentVars.LEGACYCONTAINER.getVal();

                if (srcType == SrcType.CLASS) {
                    
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    
                    replaceVal = expectedVals;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className)
                            .replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        RepeatableAnnoInherited(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"NULL\", "
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\"}, "
                + 
                "getDeclAnnoVal = \"NULL\", "
                + 
                "getAnnosArgs = {\"@Foo(value=1)\", \"@Foo(value=2)\"}, "
                + "getDeclAnnosArgs = {})", 
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = { \"ExpectedBase\", \"ExpectedContainer\"}, "
                + 
                "getDeclAnnoVal = \"NULL\", "
                + 
                "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosArgs = {})") { 

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = getCommonStmts(true);
                
                
                
                anno = Helper.ContentVars.REPEATABLEANNO.getVal();

                if (srcType == SrcType.CLASS) {
                    
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    
                    replaceVal = expectedVals;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className)
                            .replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        
        
        SingleAnnoWithContainer(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=0)\", "
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnosVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnoVal = \"@Foo(value=0)\","
                + "getAnnosArgs = {\"@Foo(value=0)\", \"@Foo(value=1)\", \"@Foo(value=2)\"},"
                + "getDeclAnnosArgs = {\"@Foo(value=0)\", \"@Foo(value=1)\",\"@Foo(value=2)\"})",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnosVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnoVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\","
                + "getDeclAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"})") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String testSrc = "";
                String pkgInfoContents = "";
                String contents = "";

                JavaFileObject pkgFileObj = null;
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = new StringBuilder();

                anno = Helper.ContentVars.BASEANNO.getVal() + " "
                        + Helper.ContentVars.LEGACYCONTAINER.getVal();
                commonStmts.append(Helper.ContentVars.IMPORTEXPECTED.getVal())
                        .append(Helper.ContentVars.IMPORTSTMTS.getVal())
                        .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
                        .append(Helper.ContentVars.REPEATABLE.getVal())
                        .append(Helper.ContentVars.BASE.getVal())
                        .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
                        .append(Helper.ContentVars.CONTAINER.getVal());
                switch (srcType) {
                    case PACKAGE:
                        
                        testSrc = srcType.getTemplate().replace("#CN", className);
                        contents = testSrc;
                        srcFileObj = Helper.getFile(className, contents);

                        replaceVal = expectedVals + "\n" + anno;
                        pkgInfoContents = SrcType.PKGINFO.getTemplate()
                                .replace("#REPLACE1", replaceVal)
                                .replace("#REPLACE2", commonStmts);
                        pkgFileObj = Helper.getFile(PKGINFONAME, pkgInfoContents);
                        files = Arrays.asList(pkgFileObj, srcFileObj);
                        break;
                    default:
                        
                        replaceVal = expectedVals + anno;
                        testSrc = srcType.getTemplate()
                                .replace("#CN", className)
                                .replace("#REPLACE", replaceVal);
                        contents = commonStmts + testSrc;
                        srcFileObj = Helper.getFile(className, contents);
                        files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        AnnoOnSuperAndSubClass_Inherited(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=1)\", "
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=1)\" }, "
                + 
                "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=1)\"}, "
                + 
                "getDeclAnnoVal = \"@Foo(value=1)\", " 
                + "getAnnosArgs = {\"@Foo(value=1)\"}, "
                + "getDeclAnnosArgs = { \"@Foo(value=1)\" })", 
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"NULL\", "
                + "getAnnotationsVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=1)\" }, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=1)\"}, "
                + 
                "getDeclAnnoVal = \"NULL\", " + 
                "getAnnosArgs = {}, " + "getDeclAnnosArgs = {})") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = getCommonStmts(true);

                
                
                

                if (srcType == SrcType.CLASS) {
                    
                    anno = Helper.ContentVars.BASEANNO.getVal();
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    
                    replaceVal = expectedVals + "\n" + "@Foo(1)";
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className)
                            .replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        
        
        RepeatableOnSuperSingleOnSub_Inherited(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=3)\", "
                + "getAnnotationsVals = {"
                + "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=3)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + 
                "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=3)\"}, "
                + 
                "getDeclAnnoVal = \"@Foo(value=3)\", " 
                + "getAnnosArgs = {\"@Foo(value=3)\"}, "
                + "getDeclAnnosArgs = { \"@Foo(value=3)\" })", 
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {"
                + "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=3)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=3)\"}, "
                + 
                "getDeclAnnoVal = \"NULL\", "
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosArgs = {}) // ignores inherited ") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = getCommonStmts(true);

                
                
                if (srcType == SrcType.CLASS) {
                    
                    anno = Helper.ContentVars.REPEATABLEANNO.getVal();
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    
                    anno = "@Foo(3)";
                    replaceVal = expectedVals + "\n" + anno;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className)
                            .replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);
                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        
        
        SingleOnSuperRepeatableOnSub_Inherited(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=0)\", "
                + "getAnnotationsVals = {"
                + "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + 
                "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + 
                "getDeclAnnoVal = \"NULL\","
                + "getAnnosArgs = {\"@Foo(value=1)\", \"@Foo(value=2)\"}, "
                + "getDeclAnnosArgs = { \"@Foo(value=1)\", \"@Foo(value=2)\"})",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {"
                + "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + 
                "getDeclAnnoVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"})") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = getCommonStmts(true);

                
                
                if (srcType == SrcType.CLASS) {
                    
                    anno = Helper.ContentVars.BASEANNO.getVal();
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    
                    anno = Helper.ContentVars.REPEATABLEANNO.getVal();
                    replaceVal = expectedVals + "\n" + anno;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className)
                            .replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        
        
        ContainerOnSuperSingleOnSub_Inherited(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=0)\", "
                + "getAnnotationsVals = {"
                + "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\"},"
                + "getDeclAnnoVal = \"@Foo(value=0)\","
                + "getAnnosArgs = {\"@Foo(value=0)\"},"
                + "getDeclAnnosArgs = {\"@Foo(value=0)\"})",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {"
                + "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\"},"
                + "getDeclAnnoVal = \"NULL\","
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnosArgs = {})") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = getCommonStmts(true);

                
                
                if (srcType == SrcType.CLASS) {
                    
                    anno = Helper.ContentVars.LEGACYCONTAINER.getVal();
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    
                    anno = Helper.ContentVars.BASEANNO.getVal();
                    replaceVal = expectedVals + "\n" + anno;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className)
                            .replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        
        
        SingleOnSuperContainerOnSub_Inherited(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=0)\", "
                + "getAnnotationsVals = {"
                + "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnoVal = \"NULL\","
                + "getAnnosArgs = {\"@Foo(value=1)\", \"@Foo(value=2)\"},"
                + "getDeclAnnosArgs = {\"@Foo(value=1)\", \"@Foo(value=2)\"})",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {"
                + "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnoVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\","
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"})") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                     String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = getCommonStmts(true);

                
                
                if (srcType == SrcType.CLASS) {
                    
                    anno = Helper.ContentVars.BASEANNO.getVal();
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    
                    anno = Helper.ContentVars.LEGACYCONTAINER.getVal();
                    replaceVal = expectedVals + "\n" + anno;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className)
                            .replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        
        
        SingleOnSuperContainerAndSingleOnSub_Inherited(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=3)\", "
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", \"@Foo(value=3)\"}, "
                + "getDeclAnnosVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", \"@Foo(value=3)\"},"
                + "getDeclAnnoVal = \"@Foo(value=3)\","
                + "getAnnosArgs = {\"@Foo(value=1)\", \"@Foo(value=2)\", \"@Foo(value=3)\"},"
                + "getDeclAnnosArgs = {\"@Foo(value=1)\", \"@Foo(value=2)\", \"@Foo(value=3)\"})",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", \"@Foo(value=3)\"}, "
                + "getDeclAnnosVals = {"
                +       "\"ExpectedBase\", \"ExpectedContainer\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", \"@Foo(value=3)\"},"
                + "getDeclAnnoVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\","
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"})") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;
                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = getCommonStmts(true);

                

                if (srcType == SrcType.CLASS) {
                    
                    anno = Helper.ContentVars.BASEANNO.getVal();
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    
                    anno = Helper.ContentVars.LEGACYCONTAINER.getVal()
                            + "@Foo(3)";
                    replaceVal = expectedVals + "\n" + anno;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className)
                            .replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        },
        
        
        ContainerAndSingleOnSuperSingleOnSub_Inherited(
        "@ExpectedBase(value=Foo.class, "
                + "getAnnotationVal = \"@Foo(value=0)\", "
                + "getAnnotationsVals = {"
                + "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\"},"
                + "getDeclAnnoVal = \"@Foo(value=0)\","
                + "getAnnosArgs = {\"@Foo(value=0)\"},"
                + "getDeclAnnosArgs = {\"@Foo(value=0)\"})",
        "@ExpectedContainer(value=FooContainer.class, "
                + "getAnnotationVal = \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\", "
                + "getAnnotationsVals = {"
                + "\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\", \"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"}, "
                + "getDeclAnnosVals = {\"ExpectedBase\", \"ExpectedContainer\", \"@Foo(value=0)\"},"
                + "getDeclAnnoVal = \"NULL\","
                + "getAnnosArgs = {\"@FooContainer(value=[@Foo(value=1), @Foo(value=2)])\"},"
                + "getDeclAnnosArgs = {})") {

            @Override
            public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                    String className) {
                String anno = "";
                String replaceVal = "";
                String contents = "";
                JavaFileObject srcFileObj = null;
                Iterable<? extends JavaFileObject> files = null;

                String expectedVals = "\n" + getExpectedBase() + "\n"
                        + getExpectedContainer() + "\n";
                StringBuilder commonStmts = getCommonStmts(true);

                

                
                if (srcType == SrcType.CLASS) {
                    
                    anno = Helper.ContentVars.LEGACYCONTAINER.getVal()
                            + "@Foo(3)" ;
                    replaceVal = commonStmts + "\n" + anno;
                    String superClassContents = srcType.getTemplate()
                            .replace("#CN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    
                    anno = Helper.ContentVars.BASEANNO.getVal();
                    replaceVal = expectedVals + "\n" + anno;
                    String subClassContents = SrcType.CLASSEXTENDS.getTemplate()
                            .replace("#CN", className)
                            .replace("#SN", SUPERCLASS)
                            .replace("#REPLACE", replaceVal);

                    contents = superClassContents + subClassContents;
                    srcFileObj = Helper.getFile(className, contents);
                    files = Arrays.asList(srcFileObj);
                }
                return files;
            }
        };

         private String expectedBase, expectedContainer;

         private TestCase(String expectedBase, String expectedContainer) {
             this.expectedBase = expectedBase;
             this.expectedContainer = expectedContainer;
         }

         public String getExpectedBase() {
             return expectedBase;
         }

         public String getExpectedContainer() {
             return expectedContainer;
         }

         
         public Iterable<? extends JavaFileObject> getTestFiles(SrcType srcType,
                 String className) {
             return null;
         }
    }

    
    enum SrcType {

        CLASS("\n#REPLACE\nclass #CN { } ") {

            @Override
            public ExpectedBase getExpectedBase(Class<?> c) {
                return c.getAnnotation(ExpectedBase.class);
            }

            @Override
            public ExpectedContainer getExpectedContainer(Class<?> c) {
                return c.getAnnotation(ExpectedContainer.class);
            }
        },
        METHOD("class #CN  {\n" + "   " + "#REPLACE\n" + "   void "
        + TESTMETHOD + "() {} \n" + "}\n") {

            @Override
            public ExpectedBase getExpectedBase(Class<?> c) {
                ExpectedBase ret = null;
                try {
                    ret = c.getDeclaredMethod(TESTMETHOD).getAnnotation(
                            ExpectedBase.class);
                } catch (NoSuchMethodException nme) {
                    error("Could not get " + TESTMETHOD + " for className "
                            + c.getName() + " Exception:\n" + nme);
                }
                return ret;
            }

            @Override
            public ExpectedContainer getExpectedContainer(Class<?> c) {
                ExpectedContainer ret = null;
                try {
                    ret = c.getDeclaredMethod(TESTMETHOD).getAnnotation(
                            ExpectedContainer.class);
                } catch (NoSuchMethodException nme) {
                    error("Could not get " + TESTMETHOD + " for className "
                            + c.getName() + " Exception:\n" + nme);
                }
                return ret;

            }
        },
        FIELD("class #CN  {\n" + "   " + "#REPLACE\n" + "   int " + TESTFIELD
        + " = 0; \n" + "}\n") {

            @Override
            public ExpectedBase getExpectedBase(Class<?> c) {
                ExpectedBase ret = null;
                try {
                    ret = c.getDeclaredField(TESTFIELD).getAnnotation(
                            ExpectedBase.class);
                } catch (NoSuchFieldException nme) {
                    error("Could not get " + TESTFIELD + " for className "
                            + c.getName() + " Exception:\n" + nme);
                }
                return ret;
            }

            @Override
            public ExpectedContainer getExpectedContainer(Class<?> c) {
                ExpectedContainer ret = null;
                try {
                    ret = c.getDeclaredField(TESTFIELD).getAnnotation(
                            ExpectedContainer.class);
                } catch (NoSuchFieldException nme) {
                    error("Could not get " + TESTFIELD + " for className "
                            + c.getName() + " Exception:\n" + nme);
                }
                return ret;

            }
        },
        PACKAGE("package " + TESTPKG + "; \n" + "class #CN {}") {

            @Override
            public ExpectedBase getExpectedBase(Class<?> c) {
                return c.getPackage().getAnnotation(ExpectedBase.class);
            }

            @Override
            public ExpectedContainer getExpectedContainer(Class<?> c) {
                return c.getPackage().getAnnotation(ExpectedContainer.class);
            }
        },
        PKGINFO("#REPLACE1\npackage " + TESTPKG + "; \n" + "#REPLACE2"),
        INTERFACE("#REPLACE\ninterface #IN { } "),
        INTERFACEIMPL("#REPLACE\nclass #CN implements #IN {}"),
        CLASSEXTENDS("#REPLACE\nclass #CN extends #SN {}");
        String template;

        private SrcType(String template) {
            this.template = template;
        }

        public String getTemplate() {
            return template;
        }

        
        public ExpectedBase getExpectedBase(Class<?> c) {
            return null;
        }

        public ExpectedContainer getExpectedContainer(Class<?> c) {
            return null;
        }

        
        public static SrcType[] getSrcTypes() {
            return new SrcType[]{CLASS, PACKAGE, METHOD, FIELD};
        }
    }

    
    enum TestMethod {

        GET_ANNO("getAnnotation") {

            @Override
            public Annotation[] getActualAnnoBase(SrcType srcType, Class<?> c) {
                Annotation[] actualAnno = new Annotation[1];
                switch (srcType) {
                    case CLASS:
                        actualAnno[0] = c.getAnnotation(srcType.getExpectedBase(c).value());
                        break;
                    case PACKAGE:
                        actualAnno[0] = c.getPackage().getAnnotation(
                                srcType.getExpectedBase(c).value());
                        break;
                    case METHOD:
                        try {
                            actualAnno[0] = c.getDeclaredMethod(TESTMETHOD).getAnnotation(
                                    srcType.getExpectedBase(c).value());
                        } catch (NoSuchMethodException nme) {
                            error("Could not get " + TESTMETHOD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nme);
                        }
                        break;
                    case FIELD:
                        try {
                            actualAnno[0] = c.getDeclaredField(TESTFIELD).getAnnotation(
                                    srcType.getExpectedBase(c).value());
                        } catch (NoSuchFieldException nfe) {
                            error("Could not get " + TESTFIELD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nfe);
                        }
                        break;
                }
                return actualAnno;
            }

            @Override
            public Annotation[] getActualAnnoContainer(SrcType srcType,
                    Class<?> c) {
                Annotation[] actualAnno = new Annotation[1];
                switch (srcType) {
                    case CLASS:
                        actualAnno[0] = c.getAnnotation(srcType.getExpectedContainer(c).value());
                        break;
                    case PACKAGE:
                        actualAnno[0] = c.getPackage().getAnnotation(
                                srcType.getExpectedContainer(c).value());
                        break;
                    case METHOD:
                        try {
                            actualAnno[0] = c.getDeclaredMethod(TESTMETHOD).getAnnotation(
                                    srcType.getExpectedContainer(c).value());
                        } catch (NoSuchMethodException nme) {
                            error("Could not get " + TESTMETHOD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nme);
                        }
                        break;
                    case FIELD:
                        try {
                            actualAnno[0] = c.getDeclaredField(TESTFIELD).getAnnotation(
                                    srcType.getExpectedContainer(c).value());
                        } catch (NoSuchFieldException nfe) {
                            error("Could not get " + TESTFIELD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nfe);
                        }
                        break;
                }
                return actualAnno;
            }

            @Override
            public String[] getExpectedAnnoBase(SrcType srcType, Class<?> c) {
                String[] expAnno = {srcType.getExpectedBase(c).getAnnotationVal()};
                return expAnno;
            }

            @Override
            public String[] getExpectedAnnoContainer(SrcType srcType, Class<?> c) {
                String[] expAnno = {srcType.getExpectedContainer(c).getAnnotationVal()};
                return expAnno;
            }
        },
        GET_ANNOS("getAnnotations") {

            @Override
            public Annotation[] getActualAnnoBase(SrcType srcType, Class<?> c) {
                Annotation[] actualAnnos = null;
                switch (srcType) {
                    case CLASS:
                        actualAnnos = c.getAnnotations();
                        break;
                    case PACKAGE:
                        actualAnnos = c.getPackage().getAnnotations();
                        break;
                    case METHOD:
                        try {
                            actualAnnos = c.getDeclaredMethod(TESTMETHOD).getAnnotations();
                        } catch (NoSuchMethodException nme) {
                            error("Could not get " + TESTMETHOD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nme);
                        }
                        break;
                    case FIELD:
                        try {
                            actualAnnos = c.getDeclaredField(TESTFIELD).getAnnotations();
                        } catch (NoSuchFieldException nfe) {
                            error("Could not get " + TESTFIELD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nfe);
                        }
                        break;
                }
                return actualAnnos;
            }

            @Override
            public Annotation[] getActualAnnoContainer(SrcType srcType,
                    Class<?> c) {
                Annotation[] actualAnnos = null;
                switch (srcType) {
                    case CLASS:
                        actualAnnos = c.getAnnotations();
                        break;
                    case PACKAGE:
                        actualAnnos = c.getPackage().getAnnotations();
                        break;
                    case METHOD:
                        try {
                            actualAnnos = c.getDeclaredMethod(TESTMETHOD).getAnnotations();
                        } catch (NoSuchMethodException nme) {
                            error("Could not get " + TESTMETHOD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nme);
                        }
                        break;
                    case FIELD:
                        try {
                            actualAnnos = c.getDeclaredField(TESTFIELD).getAnnotations();
                        } catch (NoSuchFieldException nfe) {
                            error("Could not get " + TESTFIELD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nfe);
                        }
                        break;
                }
                return actualAnnos;
            }

            @Override
            public String[] getExpectedAnnoBase(SrcType srcType, Class<?> c) {
                return srcType.getExpectedBase(c).getAnnotationsVals();
            }

            @Override
            public String[] getExpectedAnnoContainer(SrcType srcType, Class<?> c) {
                return srcType.getExpectedContainer(c).getAnnotationsVals();
            }
        },
        GET_DECL_ANNOS("getDeclaredAnnotations") {

            @Override
            public Annotation[] getActualAnnoBase(SrcType srcType, Class<?> c) {
                Annotation[] actualDeclAnnos = null;
                switch (srcType) {
                    case CLASS:
                        actualDeclAnnos = c.getDeclaredAnnotations();
                        break;
                    case PACKAGE:
                        actualDeclAnnos = c.getPackage().getDeclaredAnnotations();
                        break;
                    case METHOD:
                        try {
                            actualDeclAnnos = c.getDeclaredMethod(TESTMETHOD)
                                    .getDeclaredAnnotations();
                        } catch (NoSuchMethodException nme) {
                            error("Could not get " + TESTMETHOD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nme);
                        }
                        break;
                    case FIELD:
                        try {
                            actualDeclAnnos = c.getDeclaredField(TESTFIELD)
                                    .getDeclaredAnnotations();
                        } catch (NoSuchFieldException nfe) {
                            error("Could not get " + TESTFIELD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nfe);
                        }
                        break;
                }
                return actualDeclAnnos;
            }

            @Override
            public Annotation[] getActualAnnoContainer(SrcType srcType,
                    Class<?> c) {
                Annotation[] actualDeclAnnos = null;
                switch (srcType) {
                    case CLASS:
                        actualDeclAnnos = c.getDeclaredAnnotations();
                        break;
                    case PACKAGE:
                        actualDeclAnnos = c.getPackage().getDeclaredAnnotations();
                        break;
                    case METHOD:
                        try {
                            actualDeclAnnos = c.getDeclaredMethod(TESTMETHOD)
                                    .getDeclaredAnnotations();
                        } catch (NoSuchMethodException nme) {
                            error("Could not get " + TESTMETHOD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nme);
                        }
                        break;
                    case FIELD:
                        try {
                            actualDeclAnnos = c.getDeclaredField(TESTFIELD)
                                    .getDeclaredAnnotations();
                        } catch (NoSuchFieldException nfe) {
                            error("Could not get " + TESTFIELD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nfe);
                        }
                        break;
                }
                return actualDeclAnnos;
            }

            @Override
            public String[] getExpectedAnnoBase(SrcType srcType, Class<?> c) {
                return srcType.getExpectedBase(c).getDeclAnnosVals();
            }

            @Override
            public String[] getExpectedAnnoContainer(SrcType srcType, Class<?> c) {
                return srcType.getExpectedContainer(c).getDeclAnnosVals();
            }
        },
        GET_DECL_ANNO("getDeclaredAnnotation") {

            @Override
            public Annotation[] getActualAnnoBase(SrcType srcType, Class<?> c) {
                Annotation[] actualDeclAnno = new Annotation[1];
                switch (srcType) {
                    case CLASS:
                        actualDeclAnno[0] = c.getDeclaredAnnotation(
                                srcType.getExpectedBase(c).value());
                        break;
                    case PACKAGE:
                        actualDeclAnno[0] = c.getPackage().getDeclaredAnnotation(
                                srcType.getExpectedBase(c).value());
                        break;
                    case METHOD:
                        try {
                            actualDeclAnno[0] = c.getDeclaredMethod(TESTMETHOD)
                                    .getDeclaredAnnotation(
                                        srcType.getExpectedBase(c).value());
                        } catch (NoSuchMethodException nme) {
                            error("Could not get " + TESTMETHOD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nme);
                        }
                        break;
                    case FIELD:
                        try {
                            actualDeclAnno[0] = c.getDeclaredField(TESTFIELD)
                                    .getDeclaredAnnotation(
                                        srcType.getExpectedBase(c).value());
                        } catch (NoSuchFieldException nfe) {
                            error("Could not get " + TESTFIELD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nfe);
                        }
                        break;
                }
                return actualDeclAnno;
            }

            @Override
            public Annotation[] getActualAnnoContainer(SrcType srcType,
                    Class<?> c) {
                Annotation[] actualDeclAnno = new Annotation[1];
                switch (srcType) {
                    case CLASS:
                        actualDeclAnno[0] = c.getDeclaredAnnotation(
                                srcType.getExpectedContainer(c).value());
                        break;
                    case PACKAGE:
                        actualDeclAnno[0] = c.getPackage().getDeclaredAnnotation(
                                srcType.getExpectedContainer(c).value());
                        break;
                    case METHOD:
                        try {
                            actualDeclAnno[0] = c.getDeclaredMethod(TESTMETHOD)
                                    .getDeclaredAnnotation(
                                        srcType.getExpectedContainer(c).value());
                        } catch (NoSuchMethodException nme) {
                            error("Could not get " + TESTMETHOD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nme);
                        }
                        break;
                    case FIELD:
                        try {
                            actualDeclAnno[0] = c.getDeclaredField(TESTFIELD)
                                    .getDeclaredAnnotation(
                                        srcType.getExpectedContainer(c).value());
                        } catch (NoSuchFieldException nfe) {
                            error("Could not get " + TESTFIELD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nfe);
                        }
                        break;
                }
                return actualDeclAnno;
            }

            @Override
            public String[] getExpectedAnnoBase(SrcType srcType, Class<?> c) {
                String[] expAnno = {srcType.getExpectedBase(c).getDeclAnnoVal()};
                return expAnno;
            }

            @Override
            public String[] getExpectedAnnoContainer(SrcType srcType, Class<?> c) {
                String[] expAnno = {srcType.getExpectedContainer(c).getDeclAnnoVal()};
                return expAnno;
            }
        }, 
        GET_ANNOS_ARG("getAnnotationsArg") {

            @Override
            public Annotation[] getActualAnnoBase(SrcType srcType, Class<?> c) {
                Annotation[] actualAnnoArgs = null;
                switch (srcType) {
                    case CLASS:
                        actualAnnoArgs = c.getAnnotationsByType(srcType.getExpectedBase(c).value());
                        break;
                    case PACKAGE:
                        actualAnnoArgs = c.getPackage().getAnnotationsByType(
                                srcType.getExpectedBase(c).value());
                        break;
                    case METHOD:
                        try {
                            actualAnnoArgs = c.getDeclaredMethod(TESTMETHOD)
                                    .getAnnotationsByType(
                                        srcType.getExpectedBase(c).value());
                        } catch (NoSuchMethodException nme) {
                            error("Could not get " + TESTMETHOD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nme);
                        }
                        break;
                    case FIELD:
                        try {
                            actualAnnoArgs = c.getDeclaredField(TESTFIELD)
                                    .getAnnotationsByType(
                                        srcType.getExpectedBase(c).value());
                        } catch (NoSuchFieldException nfe) {
                            error("Could not get " + TESTFIELD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nfe);
                        }
                        break;
                }
                return actualAnnoArgs;
            }

            @Override
            public Annotation[] getActualAnnoContainer(SrcType srcType,
                    Class<?> c) {
                Annotation[] actualAnnoArgs = null;
                switch (srcType) {
                    case CLASS:
                        actualAnnoArgs = c.getAnnotationsByType(srcType.getExpectedContainer(c).value());
                        break;
                    case PACKAGE:
                        actualAnnoArgs = c.getPackage().getAnnotationsByType(
                                srcType.getExpectedContainer(c).value());
                        break;
                    case METHOD:
                        try {
                            actualAnnoArgs = c.getDeclaredMethod(TESTMETHOD)
                                    .getAnnotationsByType(
                                        srcType.getExpectedContainer(c).value());
                        } catch (NoSuchMethodException nme) {
                            error("Could not get " + TESTMETHOD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nme);
                        }
                        break;
                    case FIELD:
                        try {
                            actualAnnoArgs = c.getDeclaredField(TESTFIELD)
                                    .getAnnotationsByType(
                                        srcType.getExpectedContainer(c).value());
                        } catch (NoSuchFieldException nfe) {
                            error("Could not get " + TESTFIELD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nfe);
                        }
                        break;
                }
                return actualAnnoArgs;
            }

            @Override
            public String[] getExpectedAnnoBase(SrcType srcType, Class<?> c) {
                return srcType.getExpectedBase(c).getAnnosArgs();
            }

            @Override
            public String[] getExpectedAnnoContainer(SrcType srcType, Class<?> c) {
                return srcType.getExpectedContainer(c).getAnnosArgs();
            }
        }, 
        GET_DECL_ANNOS_ARG("getDeclAnnosArg") {

            @Override
            public Annotation[] getActualAnnoBase(SrcType srcType, Class<?> c) {
                Annotation[] actualDeclAnnosArgs = null;
                switch (srcType) {
                    case CLASS:
                        actualDeclAnnosArgs = c.getDeclaredAnnotationsByType(
                                srcType.getExpectedBase(c).value());
                        break;
                    case PACKAGE:
                        actualDeclAnnosArgs = c.getPackage().getDeclaredAnnotationsByType(
                                srcType.getExpectedBase(c).value());
                        break;
                    case METHOD:
                        try {
                            actualDeclAnnosArgs = c.getDeclaredMethod(TESTMETHOD)
                                    .getDeclaredAnnotationsByType(
                                        srcType.getExpectedBase(c).value());
                        } catch (NoSuchMethodException nme) {
                            error("Could not get " + TESTMETHOD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nme);
                        }
                        break;
                    case FIELD:
                        try {
                            actualDeclAnnosArgs = c.getDeclaredField(TESTFIELD)
                                    .getDeclaredAnnotationsByType(
                                        srcType.getExpectedBase(c).value());
                        } catch (NoSuchFieldException nfe) {
                            error("Could not get " + TESTFIELD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nfe);
                        }
                        break;
                }
                return actualDeclAnnosArgs;
            }

            @Override
            public Annotation[] getActualAnnoContainer(SrcType srcType,
                    Class<?> c) {
                Annotation[] actualDeclAnnosArgs = null;
                switch (srcType) {
                    case CLASS:
                        actualDeclAnnosArgs = c.getDeclaredAnnotationsByType(
                                srcType.getExpectedContainer(c).value());
                        break;
                    case PACKAGE:
                        actualDeclAnnosArgs = c.getPackage().getDeclaredAnnotationsByType(
                                srcType.getExpectedContainer(c).value());
                        break;
                    case METHOD:
                        try {
                            actualDeclAnnosArgs = c.getDeclaredMethod(TESTMETHOD)
                                    .getDeclaredAnnotationsByType(
                                        srcType.getExpectedContainer(c).value());
                        } catch (NoSuchMethodException nme) {
                            error("Could not get " + TESTMETHOD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nme);
                        }
                        break;
                    case FIELD:
                        try {
                            actualDeclAnnosArgs = c.getDeclaredField(TESTFIELD)
                                   .getDeclaredAnnotationsByType(
                                        srcType.getExpectedContainer(c).value());
                        } catch (NoSuchFieldException nfe) {
                            error("Could not get " + TESTFIELD
                                    + " for className = " + c.getName()
                                    + "Exception = " + nfe);
                        }
                        break;
                }
                return actualDeclAnnosArgs;
            }

            @Override
            public String[] getExpectedAnnoBase(SrcType srcType, Class<?> c) {
                return srcType.getExpectedBase(c).getDeclAnnosArgs();
            }

            @Override
            public String[] getExpectedAnnoContainer(SrcType srcType, Class<?> c) {
                return srcType.getExpectedContainer(c).getDeclAnnosArgs();
            }
        }; 
        String name;

        private TestMethod(String name) {
            this.name = name;
        }

        public Annotation[] getActualAnnoBase(SrcType srcType, Class<?> c) {
            return null;
        }

        public Annotation[] getActualAnnoContainer(SrcType srcType, Class<?> c) {
            return null;
        }

        public String[] getExpectedAnnoBase(SrcType srcType, Class<?> c) {
            return null;
        }

        public String[] getExpectedAnnoContainer(SrcType srcType, Class<?> c) {
            return null;
        }
    }

    
    protected static void checkAnnoValues(SrcType srcType, Class<?> c) {

        
        ExpectedBase eb = srcType.getExpectedBase(c);
        ExpectedContainer ec = srcType.getExpectedContainer(c);
        if (eb == null) {
            error("Did not find ExpectedBase Annotation, Test will exit");
            throw new RuntimeException();
        }
        if (ec == null) {
            error("Did not find ExpectedContainer Annotation, Test will exit");
            throw new RuntimeException();
        }

        for (TestMethod testMethod : TestMethod.values()) {
            debugPrint("---------------------------------------------");
            debugPrint("Test method = " + testMethod);
            boolean isBasePass = true;
            boolean isConPass = true;
            
            if (!eb.value().getSimpleName().equalsIgnoreCase("Annotation")) {
                isBasePass = compareAnnotations(
                        testMethod.getActualAnnoBase(srcType, c),
                        testMethod.getExpectedAnnoBase(srcType, c));
            }

            
            if (!ec.value().getSimpleName().equalsIgnoreCase("Annotation")) {
                isConPass = compareAnnotations(
                        testMethod.getActualAnnoContainer(srcType, c),
                        testMethod.getExpectedAnnoContainer(srcType, c));
            }
            if (isBasePass && isConPass) {
                debugPrint("Testcase passed for " + testMethod +
                        " for className = " + c.getName());
            } else {
                debugPrint("Testcase failed for " + testMethod +
                        " for className = " + c.getName());
            }
        }
    }

    
    
    private static boolean compareAnnotations(Annotation[] actualAnnos,
            String[] expectedAnnos) {
        boolean compOrder = false;

        
        if (actualAnnos.length != expectedAnnos.length) {
            error("Length not same, Actual length = " + actualAnnos.length
                    + " Expected length = " + expectedAnnos.length);
            printArrContents(actualAnnos);
            printArrContents(expectedAnnos);
            return false;
        } else {
            int i = 0;
            
            if (actualAnnos.length == 0) {
                
                
                return true;
            }
            
            if (actualAnnos[0] == null) {
                if (expectedAnnos[0].equals("NULL")) {
                    debugPrint("Arr values are NULL as expected");
                    return true;
                } else {
                    error("Array values are not NULL");
                    printArrContents(actualAnnos);
                    printArrContents(expectedAnnos);
                    return false;
                }
            }
            
            String[] actualArr = new String[actualAnnos.length];
            for (Annotation a : actualAnnos) {
                if (a.annotationType().getSimpleName().contains("Expected"))
                actualArr[i++] = a.annotationType().getSimpleName();
                 else if (a.annotationType().getName().contains(TESTPKG)) {
                    String replaced = a.toString().replaceAll(Pattern.quote("testpkg."),"");
                    actualArr[i++] = replaced;
                } else
                    actualArr[i++] = a.toString();
            }
            List<String> actualList = new ArrayList<String>(Arrays.asList(actualArr));
            List<String> expectedList = new ArrayList<String>(Arrays.asList(expectedAnnos));
            if (!actualList.containsAll(expectedList)) {
                error("Array values are not same");
                printArrContents(actualAnnos);
                printArrContents(expectedAnnos);
                return false;
            } else {
                debugPrint("Arr values are same as expected");
                if (CHECKORDERING) {
                    debugPrint("Checking if annotation ordering is as expected..");
                    compOrder = compareOrdering(actualList, expectedList);
                    if (compOrder)
                        debugPrint("Arr values ordering is as expected");
                    else
                        error("Arr values ordering is not as expected! actual values: "
                            + actualList + " expected values: " + expectedList);
                } else
                    compOrder = true;
            }
        }
        return compOrder;
    }

    
    private static boolean compareOrdering(List<String> actualList, List<String> expectedList) {
        boolean order = true;
        
        actualList = iterateList(actualList);
        expectedList = iterateList(expectedList);
        
        if (actualList.size() != expectedList.size()) {
            error("Length not same, Actual list length = " + actualList.size()
                    + " Expected list length = " + expectedList.size());
            return false;
        } else {
            if (actualList.isEmpty() && expectedList.isEmpty()) {
        return true;
    }
            boolean tmp = true;
            for (int i = 0; i < actualList.size(); i++) {
                
                if (order) {
                    if (!actualList.get(i).equals(expectedList.get(i))) {
                        tmp = false;
                        debugPrint("Odering is false");
                        debugPrint("actualList values: " + actualList
                                + " expectedList values: " + expectedList);
                    }
                }
            }
            order = tmp;
        }
        return order;
    }

    private static List<String> iterateList(List<String> list) {
        Iterator<String> iter = list.iterator();
        while (iter.hasNext()) {
            String anno = iter.next();
            if (anno.contains("Expected")) {
                iter.remove();
            }
        }
        return list;
    }

    private static void printArrContents(Annotation[] actualAnnos) {
        System.out.print("Actual Arr Values: ");
        for (Annotation a : actualAnnos) {
            if (a != null && a.annotationType() != null) {
                System.out.print("[" + a.toString() + "]");
            } else {
                System.out.println("[null]");
            }
        }
        System.out.println();
    }

    private static void printArrContents(String[] expectedAnnos) {
        System.out.print("Expected Arr Values: ");
        for (String s : expectedAnnos) {
            System.out.print("[" + s + "]");
        }
        System.out.println();
    }

    private ClassLoader getLoader() {
        return getClass().getClassLoader();
    }

    private static Class<?> loadClass(String className, ClassLoader parentClassLoader, File... destDirs) {
        try {
            List<URL> list = new ArrayList<>();
            for (File f : destDirs) {
                list.add(new URL("file:" + f.toString().replace("\\", "/") + "/"));
            }
            return Class.forName(className, true, new URLClassLoader(
                    list.toArray(new URL[list.size()]), parentClassLoader));
        } catch (ClassNotFoundException | MalformedURLException e) {
            throw new RuntimeException("Error loading class " + className, e);
        }
    }

    private static void printTestSrc(Iterable<? extends JavaFileObject> files) {
        for (JavaFileObject f : files) {
            System.out.println("Test file " + f.getName() + ":");
            try {
                System.out.println("" + f.getCharContent(true));
            } catch (IOException e) {
                throw new RuntimeException(
                        "Exception when printing test src contents for class " +
                                f.getName(), e);
            }
        }

    }

    public static StringBuilder getCommonStmts(boolean isRepeatable) {
        StringBuilder sb = new StringBuilder();

        sb.append(Helper.ContentVars.IMPORTEXPECTED.getVal())
          .append(Helper.ContentVars.IMPORTSTMTS.getVal())
          .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
          .append(Helper.ContentVars.INHERITED.getVal());
        if(isRepeatable) {
            sb.append(Helper.ContentVars.REPEATABLE.getVal());
        }
        sb.append(Helper.ContentVars.BASE.getVal())
          .append(Helper.ContentVars.RETENTIONRUNTIME.getVal())
          .append(Helper.ContentVars.INHERITED.getVal())
          .append(Helper.ContentVars.CONTAINER.getVal());
        return sb;
    }

    private static int getNumErrors() {
        return errors;
    }

    private static void error(String msg) {
        System.out.println("error: " + msg);
        errors++;
    }

    private static void debugPrint(String string) {
        if(DEBUG)
            System.out.println(string);
    }
}
