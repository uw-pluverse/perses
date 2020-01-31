

package org.openjdk.tests.vm;

import org.openjdk.tests.separate.Compiler;
import org.openjdk.tests.separate.TestHarness;
import org.testng.annotations.Test;

import static org.openjdk.tests.separate.SourceModel.AbstractMethod;
import static org.openjdk.tests.separate.SourceModel.AccessFlag;
import static org.openjdk.tests.separate.SourceModel.Class;
import static org.openjdk.tests.separate.SourceModel.ConcreteMethod;
import static org.openjdk.tests.separate.SourceModel.DefaultMethod;
import static org.openjdk.tests.separate.SourceModel.Extends;
import static org.openjdk.tests.separate.SourceModel.Interface;
import static org.openjdk.tests.separate.SourceModel.MethodParameter;
import static org.openjdk.tests.separate.SourceModel.TypeParameter;
import static org.testng.Assert.assertEquals;
import static org.testng.Assert.assertNotNull;
import static org.testng.Assert.fail;

@Test(groups = "vm")
public class DefaultMethodsTest extends TestHarness {
    public DefaultMethodsTest() {
        super(false, false);
    }

    
    public void testHarnessInvokeVirtual() {
        Class C = new Class("C", ConcreteMethod.std("22"));
        assertInvokeVirtualEquals(22, C);
    }

    
    public void testHarnessInvokeInterface() {
        Interface I = new Interface("I", AbstractMethod.std());
        Class C = new Class("C", I, ConcreteMethod.std("33"));
        assertInvokeInterfaceEquals(33, C, I);
    }

    
    public void testHarnessThrows() {
        Class C = new Class("C");
        assertThrows(NoSuchMethodError.class, C);
    }

    
    public void testBasicDefault() {
        Interface I = new Interface("I", DefaultMethod.std("44"));
        Class C = new Class("C", I);

        assertInvokeVirtualEquals(44, C);
        assertInvokeInterfaceEquals(44, C, I);
    }

    
    public void testFarDefault() {
        Interface I = new Interface("I", DefaultMethod.std("44"));
        Interface J = new Interface("J", I);
        Interface K = new Interface("K", J);
        Class C = new Class("C", K);

        assertInvokeVirtualEquals(44, C);
        assertInvokeInterfaceEquals(44, C, K);
    }

    
    public void testOverrideAbstract() {
        Interface I = new Interface("I", AbstractMethod.std());
        Interface J = new Interface("J", I, DefaultMethod.std("44"));
        Interface K = new Interface("K", J);
        Class C = new Class("C", K);

        assertInvokeVirtualEquals(44, C);
        assertInvokeInterfaceEquals(44, C, K);
    }

    
    public void testExisting() {
        Interface I = new Interface("I", DefaultMethod.std("44"));
        Class C = new Class("C", I, ConcreteMethod.std("55"));

        assertInvokeVirtualEquals(55, C);
        assertInvokeInterfaceEquals(55, C, I);
    }

    
    public void testInherited() {
        Interface I = new Interface("I", DefaultMethod.std("99"));
        Class B = new Class("B", I);
        Class C = new Class("C", B);

        assertInvokeVirtualEquals(99, C);
        assertInvokeInterfaceEquals(99, C, I);
    }

    
    public void testExistingInherited() {
        Interface I = new Interface("I", DefaultMethod.std("99"));
        Class C = new Class("C", ConcreteMethod.std("11"));
        Class D = new Class("D", C, I);

        assertInvokeVirtualEquals(11, D);
        assertInvokeInterfaceEquals(11, D, I);
    }

    
    public void testExistingInheritedOverride() {
        Interface I = new Interface("I", DefaultMethod.std("99"));
        Class C = new Class("C", I, ConcreteMethod.std("11"));
        Class D = new Class("D", C, ConcreteMethod.std("22"));

        assertInvokeVirtualEquals(22, D);
        assertInvokeInterfaceEquals(22, D, I);
    }

    
    public void testExistingInheritedPlusDefault() {
        Interface I = new Interface("I", DefaultMethod.std("99"));
        Interface J = new Interface("J", DefaultMethod.std("88"));
        Class C = new Class("C", I, ConcreteMethod.std("11"));
        Class D = new Class("D", C, ConcreteMethod.std("22"));
        Class E = new Class("E", D, J);

        assertInvokeVirtualEquals(22, E);
        assertInvokeInterfaceEquals(22, E, J);
    }

    
    public void testInheritedWithConcrete() {
        Interface I = new Interface("I", DefaultMethod.std("99"));
        Class B = new Class("B", I);
        Class C = new Class("C", B, ConcreteMethod.std("77"));

        assertInvokeVirtualEquals(77, C);
        assertInvokeInterfaceEquals(77, C, I);
    }

    
    public void testInheritedWithConcreteAndImpl() {
        Interface I = new Interface("I", DefaultMethod.std("99"));
        Class B = new Class("B", I);
        Class C = new Class("C", B, I, ConcreteMethod.std("66"));

        assertInvokeVirtualEquals(66, C);
        assertInvokeInterfaceEquals(66, C, I);
    }

    
    public void testConflict() {
        Interface I = new Interface("I", DefaultMethod.std("99"));
        Interface J = new Interface("J", DefaultMethod.std("88"));
        Class C = new Class("C", I, J);

        assertThrows(IncompatibleClassChangeError.class, C);
    }

    
    public void testAmbiguousReabstract() {
        Interface I = new Interface("I", AbstractMethod.std());
        Interface J = new Interface("J", DefaultMethod.std("88"));
        Class C = new Class("C", I, J);

        assertInvokeVirtualEquals(88, C);
    }

    
    public void testDiamond() {
        Interface I = new Interface("I", DefaultMethod.std("99"));
        Interface J = new Interface("J", I);
        Interface K = new Interface("K", I);
        Class C = new Class("C", J, K);

        assertInvokeVirtualEquals(99, C);
        assertInvokeInterfaceEquals(99, C, J);
        assertInvokeInterfaceEquals(99, C, K);
        assertInvokeInterfaceEquals(99, C, I);
    }

    
    public void testExpandedDiamond() {
        Interface I = new Interface("I", DefaultMethod.std("99"));
        Interface J = new Interface("J", I);
        Interface K = new Interface("K", I);
        Interface L = new Interface("L", I);
        Interface M = new Interface("M", L);
        Class C = new Class("C", I, J, K, L, M);

        assertInvokeVirtualEquals(99, C);
        assertInvokeInterfaceEquals(99, C, J);
        assertInvokeInterfaceEquals(99, C, K);
        assertInvokeInterfaceEquals(99, C, I);
        assertInvokeInterfaceEquals(99, C, L);
        assertInvokeInterfaceEquals(99, C, M);
    }

    
    public void testReabstract() {
        Interface I = new Interface("I", DefaultMethod.std("99"));
        Interface J = new Interface("J", I, AbstractMethod.std());
        Class C = new Class("C", J);

        assertThrows(AbstractMethodError.class, C);
    }

    
    public void testShadow() {
        Interface I = new Interface("I", DefaultMethod.std("88"));
        Interface J = new Interface("J", I, DefaultMethod.std("99"));
        Class C = new Class("C", J);

        assertInvokeVirtualEquals(99, C);
        assertInvokeInterfaceEquals(99, C, J);
        assertInvokeInterfaceEquals(99, C, I);
    }

    
    public void testDisqualified() {
        Interface I = new Interface("I", DefaultMethod.std("88"));
        Interface J = new Interface("J", I, DefaultMethod.std("99"));
        Class C = new Class("C", I, J);

        assertInvokeVirtualEquals(99, C);
        assertInvokeInterfaceEquals(99, C, J);
        assertInvokeInterfaceEquals(99, C, I);
    }

    
    public void testSelfFill() {
        
        
        

        DefaultMethod dm = new DefaultMethod(
            "int", "m", "return 99;", new MethodParameter("T", "t"));
        ConcreteMethod cm = new ConcreteMethod(
            "int", "m", "return 88;", AccessFlag.PUBLIC,
            new MethodParameter("String", "s"));

        Interface I = new Interface("I", new TypeParameter("T"), dm);
        Class C = new Class("C", I.with("String"), cm);

        AbstractMethod pm = new AbstractMethod(
            "int", "m", new MethodParameter("T", "t"));

        assertInvokeVirtualEquals(88, C, cm, "-1", "\"string\"");
        assertInvokeInterfaceEquals(99, C, I.with("String"), pm, "\"string\"");

        C.setFullCompilation(true); 
        assertInvokeInterfaceEquals(88, C, I.with("String"), pm, "\"string\"");
    }

    
    public void testReflectCall() {
        Interface I = new Interface("I", DefaultMethod.std("99"));
        
        I.addAccessFlag(AccessFlag.PUBLIC);
        Class C = new Class("C", I);

        Compiler.Flags[] flags = this.verbose ?
            new Compiler.Flags[] { Compiler.Flags.VERBOSE } :
            new Compiler.Flags[] {};
        Compiler compiler = new Compiler(flags);
        java.lang.Class<?> cls = null;
        try {
            cls = compiler.compileAndLoad(C);
        } catch (ClassNotFoundException e) {
            fail("Could not load class");
        }

        java.lang.reflect.Method method = null;
        try {
            method = cls.getMethod(stdMethodName);
        } catch (NoSuchMethodException e) {
            fail("Could not find method in class");
        }
        assertNotNull(method);

        Object c = null;
        try {
            c = cls.newInstance();
        } catch (InstantiationException | IllegalAccessException e) {
            fail("Could not create instance of class");
        }
        assertNotNull(c);

        Integer res = null;
        try {
            res = (Integer)method.invoke(c);
        } catch (IllegalAccessException |
                 java.lang.reflect.InvocationTargetException e) {
            fail("Could not invoke default instance method");
        }
        assertNotNull(res);

        assertEquals(res.intValue(), 99);

        compiler.cleanup();
    }

    
    public void testBridges() {
        DefaultMethod dm = new DefaultMethod("int", stdMethodName, "return 99;",
            new MethodParameter("T", "t"), new MethodParameter("V", "v"),
            new MethodParameter("W", "w"));

        AbstractMethod pm0 = new AbstractMethod("int", stdMethodName,
            new MethodParameter("T", "t"), new MethodParameter("V", "v"),
            new MethodParameter("W", "w"));

        AbstractMethod pm1 = new AbstractMethod("int", stdMethodName,
            new MethodParameter("T", "t"), new MethodParameter("V", "v"),
            new MethodParameter("String", "w"));

        AbstractMethod pm2 = new AbstractMethod("int", stdMethodName,
            new MethodParameter("T", "t"), new MethodParameter("String", "v"),
            new MethodParameter("String", "w"));

        ConcreteMethod cm = new ConcreteMethod("int",stdMethodName,"return 88;",
            AccessFlag.PUBLIC,
            new MethodParameter("String", "t"),
            new MethodParameter("String", "v"),
            new MethodParameter("String", "w"));

        Interface I = new Interface("I", new TypeParameter("T"),
            new TypeParameter("V"), new TypeParameter("W"), dm);
        Interface J = new Interface("J",
            new TypeParameter("T"), new TypeParameter("V"),
            I.with("String", "T", "V"), pm1);
        Interface K = new Interface("K", new TypeParameter("T"),
            J.with("String", "T"), pm2);
        Class C = new Class("C", K.with("String"), cm);

        
        String[] args = new String[] { "\"A\"", "\"B\"", "\"C\"" };
        assertInvokeInterfaceEquals(99, C, I.with("String", "String", "String"), pm0, args);
        assertInvokeInterfaceThrows(AbstractMethodError.class, C, J.with("String", "String"), pm1, args);
        assertInvokeInterfaceThrows(AbstractMethodError.class, C, K.with("String"), pm2, args);

        
        C.setFullCompilation(true);
        assertInvokeInterfaceEquals(88, C, I.with("String", "String", "String"), pm0, args);
        assertInvokeInterfaceEquals(88, C, J.with("String", "String"), pm1, args);
        assertInvokeInterfaceEquals(88, C, K.with("String"), pm2, args);
    }

    
    public void testSuperBasic() {
        Interface J = new Interface("J", DefaultMethod.std("88"));
        Interface I = new Interface("I", J, new DefaultMethod(
            "int", stdMethodName, "return J.super.m();"));
        I.addCompilationDependency(J.findMethod(stdMethodName));
        Class C = new Class("C", I);

        assertInvokeVirtualEquals(88, C);
        assertInvokeInterfaceEquals(88, C, I);
    }

    
    public void testSuperConflict() {
        Interface K = new Interface("K", DefaultMethod.std("99"));
        Interface L = new Interface("L", DefaultMethod.std("101"));
        Interface J = new Interface("J", K, L);
        Interface I = new Interface("I", J, K, new DefaultMethod(
            "int", stdMethodName, "return J.super.m();"));
        Interface Jstub = new Interface("J", DefaultMethod.std("-1"));
        I.addCompilationDependency(Jstub);
        I.addCompilationDependency(Jstub.findMethod(stdMethodName));
        Class C = new Class("C", I);

        assertThrows(IncompatibleClassChangeError.class, C);
    }

    
    public void testSuperDisqual() {
        Interface I = new Interface("I", DefaultMethod.std("99"));
        Interface J = new Interface("J", I, DefaultMethod.std("55"));
        Class C = new Class("C", I, J,
            new ConcreteMethod("int", stdMethodName, "return I.super.m();",
                AccessFlag.PUBLIC));
        C.addCompilationDependency(I.findMethod(stdMethodName));

        assertInvokeVirtualEquals(99, C);
    }

    
    public void testSuperNull() {
        Interface J = new Interface("J", AbstractMethod.std());
        Interface I = new Interface("I", J, new DefaultMethod(
            "int", stdMethodName, "return J.super.m();"));
        Interface Jstub = new Interface("J", DefaultMethod.std("99"));
        I.addCompilationDependency(Jstub);
        I.addCompilationDependency(Jstub.findMethod(stdMethodName));
        Class C = new Class("C", I);

        assertThrows(AbstractMethodError.class, C);
    }

    
    public void testSuperGeneric() {
        Interface J = new Interface("J", new TypeParameter("T"),
            new DefaultMethod("int", stdMethodName, "return 88;",
                new MethodParameter("T", "t")));
        Interface I = new Interface("I", J.with("String"),
            new DefaultMethod("int", stdMethodName, "return J.super.m(s);",
                new MethodParameter("String", "s")));
        I.addCompilationDependency(J.findMethod(stdMethodName));
        Class C = new Class("C", I);

        AbstractMethod pm = new AbstractMethod("int", stdMethodName,
            new MethodParameter("String", "s"));

        assertInvokeInterfaceEquals(88, C, new Extends(I), pm, "\"\"");
    }

    
    public void testSuperGenericDisqual() {
        MethodParameter t = new MethodParameter("T", "t");
        MethodParameter s = new MethodParameter("String", "s");

        Interface I = new Interface("I", new TypeParameter("T"),
            new DefaultMethod("int", stdMethodName, "return 44;", t));
        Interface J = new Interface("J", I.with("String"),
            new DefaultMethod("int", stdMethodName, "return 55;", s));
        Class C = new Class("C", I.with("String"), J,
            new ConcreteMethod("int", stdMethodName,
                "return I.super.m(s);", AccessFlag.PUBLIC, s));
        C.addCompilationDependency(I.findMethod(stdMethodName));

        assertInvokeVirtualEquals(44, C,
            new ConcreteMethod(
                "int", stdMethodName, "return -1;", AccessFlag.PUBLIC, s),
            "-1", "\"string\"");
    }

    
    public void testCovarBridge() {
        Interface I = new Interface("I", new DefaultMethod(
            "Integer", "m", "return new Integer(88);"));
        Class C = new Class("C", new ConcreteMethod(
            "Number", "m", "return new Integer(99);", AccessFlag.PUBLIC));
        Class D = new Class("D", I, C);

        ConcreteMethod DstubMethod = new ConcreteMethod(
            "Integer", "m", "return null;", AccessFlag.PUBLIC);
        Class Dstub = new Class("D", DstubMethod);

        ConcreteMethod toCall = new ConcreteMethod(
            "Object", "foo", "return (new D()).m();", AccessFlag.PUBLIC);
        Class S = new Class("S", D, toCall);
        S.addCompilationDependency(Dstub);
        S.addCompilationDependency(DstubMethod);

        
        assertInvokeVirtualEquals(88, S, toCall, "null");
    }

    
    public void testNoCovarNoBridge() {
        Interface I = new Interface("I", new DefaultMethod(
            "Integer", "m", "return new Integer(88);"));
        Class C = new Class("C", new ConcreteMethod(
            "int", "m", "return 99;", AccessFlag.PUBLIC));
        Class D = new Class("D", I, C);

        ConcreteMethod DstubMethod = new ConcreteMethod(
            "Integer", "m", "return null;", AccessFlag.PUBLIC);
        Class Dstub = new Class("D", DstubMethod);

        ConcreteMethod toCall = new ConcreteMethod(
            "Object", "foo", "return (new D()).m();", AccessFlag.PUBLIC);
        Class S = new Class("S", D, toCall);
        S.addCompilationDependency(Dstub);
        S.addCompilationDependency(DstubMethod);

        assertInvokeVirtualEquals(88, S, toCall, "null");
    }

    
    public void testNoNewMiranda() {
        Interface J = new Interface("J", AbstractMethod.std());
        Interface I = new Interface("I", J, DefaultMethod.std("99"));
        Class B = new Class("B", J);
        Class C = new Class("C", B, I);
        assertInvokeVirtualEquals(99, C);
    }

    
    public void testNonConcreteFill() {
        AbstractMethod ipm = new AbstractMethod("int", "m",
            new MethodParameter("T", "t"),
            new MethodParameter("V", "s"),
            new MethodParameter("W", "w"));
        Interface I = new Interface("I",
            new TypeParameter("T"),
            new TypeParameter("V"),
            new TypeParameter("W"), ipm);

        AbstractMethod jpm = new AbstractMethod("int", "m",
            new MethodParameter("T", "t"),
            new MethodParameter("V", "s"),
            new MethodParameter("String", "w"));
        Interface J = new Interface("J",
            new TypeParameter("T"),
            new TypeParameter("V"),
            I.with("T", "V", "String"), jpm);

        AbstractMethod kpm = new AbstractMethod("int", "m",
            new MethodParameter("T", "t"),
            new MethodParameter("String", "s"),
            new MethodParameter("String", "w"));
        DefaultMethod kdm = new DefaultMethod("int", "m", "return 99;",
                                              new MethodParameter("T", "t"),
                                              new MethodParameter("String", "v"),
                                              new MethodParameter("String", "w"));
        Interface K = new Interface("K",
            new TypeParameter("T"),
            J.with("T", "String"),
            kdm);

        Class C = new Class("C",
            K.with("String"),
            new ConcreteMethod("int", "m", "return 77;",
                AccessFlag.PUBLIC,
                new MethodParameter("Object", "t"),
                new MethodParameter("Object", "v"),
                new MethodParameter("String", "w")));

        
        String a = "\"\"";
        assertInvokeInterfaceEquals(99, C, K.with("String"), kpm, a, a, a);
        assertInvokeInterfaceEquals(77, C, J.with("String", "String"), jpm, a, a, a);
        assertInvokeInterfaceThrows(AbstractMethodError.class, C, I.with("String", "String", "String"), ipm, a, a, a);

        
        J.setFullCompilation(true);
        K.setFullCompilation(true);
        assertInvokeInterfaceEquals(99, C, K.with("String"), kpm, a, a, a);
        assertInvokeInterfaceEquals(77, C, J.with("String", "String"), jpm, a, a, a);
        assertInvokeInterfaceEquals(99, C, I.with("String", "String", "String"), ipm, a, a, a);
    }

    public void testStrictfpDefault() {
        try {
            java.lang.Class.forName("org.openjdk.tests.vm.StrictfpDefault");
        } catch (Exception e) {
            fail("Could not load class", e);
        }
    }
}

interface StrictfpDefault {
    default strictfp void m() {}
}
