




package org.openjdk.tests.vm;

import java.util.*;

import org.testng.ITestResult;
import org.testng.annotations.Test;
import org.testng.annotations.DataProvider;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.AfterSuite;

import org.openjdk.tests.separate.*;
import org.openjdk.tests.separate.Compiler;

import org.openjdk.tests.shapegen.Hierarchy;
import org.openjdk.tests.shapegen.HierarchyGenerator;
import org.openjdk.tests.shapegen.ClassCase;

import static org.testng.Assert.*;
import static org.openjdk.tests.separate.SourceModel.*;
import static org.openjdk.tests.separate.SourceModel.Class;
import static org.openjdk.tests.separate.SourceModel.Method;
import static org.openjdk.tests.separate.SourceModel.Type;

public class FDSeparateCompilationTest extends TestHarness {

    private static String EMPTY = "\"\"";

    public FDSeparateCompilationTest() {
        super(false, true);
    }

    @DataProvider(name = "allShapes", parallel = true)
    public Object[][] hierarchyGenerator() {
        ArrayList<Object[]> allCases = new ArrayList<>();

        HierarchyGenerator hg = new HierarchyGenerator();
        for (Object x : hg.getOK()) {
            allCases.add(new Object[]{x});
        }
        for (Object x : hg.getErr()) {
            allCases.add(new Object[]{x});
        }
        return allCases.toArray(new Object[0][]);
    }

    
    
    private static String getExpectedResult(ClassCase cc) {
        Set<ClassCase> provs = cc.get_mprov();
        if (cc.get_mres() != null) {
            return cc.get_mres().getName();
        } else if (provs != null && provs.size() == 1) {
            ClassCase cand = provs.iterator().next();
            switch (cand.kind) {
                case CCONCRETE:
                case IDEFAULT:
                    return cand.getName();
                case CNONE:
                case IVAC:
                    return getExpectedResult(cand);
            }
        }
        return null;
    }

    private static final ConcreteMethod canonicalMethod = new ConcreteMethod(
            "String", "m", "returns " + EMPTY + ";", AccessFlag.PUBLIC);

    @Test(enabled = false, groups = "vm", dataProvider = "allShapes")
    public void separateCompilationTest(Hierarchy hs) {
        ClassCase cc = hs.root;
        Type type = sourceTypeFrom(hs.root);

        Class specimen = null;
        if (type instanceof Class) {
            Class ctype = (Class)type;
            if (ctype.isAbstract()) {
                specimen = new Class("Test" + ctype.getName(), ctype);
            } else {
                specimen = ctype;
            }
        } else {
            specimen = new Class("Test" + type.getName(), (Interface)type);
        }

        String value = getExpectedResult(cc);
        if (value != null) {
            assertInvokeVirtualEquals(value, specimen, canonicalMethod, EMPTY);
        } else {
            assertThrows(AbstractMethodError.class, specimen,
                canonicalMethod, EMPTY);
        }
    }

    @AfterMethod
    public void printCaseError(ITestResult result) {
        if (result.getStatus() == ITestResult.FAILURE) {
            Hierarchy hs = (Hierarchy)result.getParameters()[0];
            System.out.println("Separate compilation case " + hs);
            printCaseDetails(hs);
        }
    }

    @AfterSuite
    public void cleanupCompilerCache() {
        Compiler.purgeCache();
    }

    private void printCaseDetails(Hierarchy hs) {
        String exp = getExpectedResult(hs.root);
        for (String s : hs.getDescription()) {
             System.out.println("    " + s);
        }
        if (exp != null) {
            System.out.println("    Expected \"" + exp + "\"");
        } else {
            System.out.println("    Expected AbstractMethodError");
        }
    }

    private Type sourceTypeFrom(ClassCase cc) {
        Type type = null;

        if (cc.isInterface()) {
            Interface iface = new Interface(cc.getName());
            for (ClassCase scc : cc.getInterfaces()) {
                Interface supertype = (Interface)sourceTypeFrom(scc);
                iface.addSuperType(supertype);
            }
            type = iface;
        } else {
            Class cls = new Class(cc.getName());
            if (cc.hasSuperclass()) {
                Class superc = (Class)sourceTypeFrom(cc.getSuperclass());
                cls.setSuperClass(superc);
            }
            for (ClassCase scc : cc.getInterfaces()) {
                Interface supertype = (Interface)sourceTypeFrom(scc);
                cls.addSuperType(supertype);
            }
            if (cc.isAbstract()) {
                cls.getAccessFlags().add(AccessFlag.ABSTRACT);
            }
            type = cls;
        }
        Method method = methodFrom(cc);
        if (method != null) {
            type.addMethod(method);
        }
        return type;
    }

    private Method methodFrom(ClassCase cc) {
        switch (cc.kind) {
            case IVAC:
            case CNONE: return null;
            case IPRESENT:
            case CABSTRACT:
                return new AbstractMethod("String", "m", AccessFlag.PUBLIC);
            case IDEFAULT:
                return new DefaultMethod(
                    "String", "m", "return \"" + cc.getName() + "\";");
            case CCONCRETE:
                return new ConcreteMethod(
                    "String", "m", "return \"" + cc.getName() + "\";",
                    AccessFlag.PUBLIC);
            default:
                fail("Unknown method type in class");
                return null;
        }
    }
}
