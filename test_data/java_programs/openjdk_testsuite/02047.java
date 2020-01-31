



import com.sun.tools.javac.util.*;
import com.sun.tools.javac.code.*;
import com.sun.tools.javac.code.Scope.*;
import com.sun.tools.javac.code.Symbol.*;
import com.sun.tools.javac.file.JavacFileManager;

public class RemoveSymbolUnitTest {

    Context context;
    Names names;
    Symtab symtab;

    public static void main(String... args) throws Exception {
        new RemoveSymbolUnitTest().run();
    }

    public void run() {
        context = new Context();
        JavacFileManager.preRegister(context); 
        names = Names.instance(context);
        symtab = Symtab.instance(context);

        Name hasNext =  names.fromString("hasNext");
        ClassSymbol clazz = new ClassSymbol(0,
                                            names.fromString("X"),
                                            Type.noType,
                                            symtab.unnamedPackage);

        VarSymbol v = new VarSymbol(0, hasNext, Type.noType, clazz);
        MethodSymbol m = new MethodSymbol(0, hasNext, Type.noType, clazz);

        
        
        Scope cs = new Scope(clazz);
        cs.enter(v);
        cs.enter(m);
        cs.remove(v);
        Symbol s = cs.lookup(hasNext).sym;
        if (s != m)
            throw new AssertionError("Wrong symbol");

        cs = new Scope(clazz);
        cs.enter(m);
        cs.enter(v);
        cs.remove(v);
        s = cs.lookup(hasNext).sym;
        if (s != m)
            throw new AssertionError("Wrong symbol");

        cs = new Scope(clazz);
        cs.enter(v);
        cs.enter(m);
        cs.remove(m);
        s = cs.lookup(hasNext).sym;
        if (s != v)
            throw new AssertionError("Wrong symbol");

        cs = new Scope(clazz);
        cs.enter(m);
        cs.enter(v);
        cs.remove(m);
        s = cs.lookup(hasNext).sym;
        if (s != v)
            throw new AssertionError("Wrong symbol");
    }
}
