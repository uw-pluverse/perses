



import java.lang.reflect.*;
import java.io.*;
import com.sun.tools.javac.util.*;
import com.sun.tools.javac.code.*;
import com.sun.tools.javac.code.Scope.*;
import com.sun.tools.javac.code.Symbol.*;
import com.sun.tools.javac.file.JavacFileManager;
import static com.sun.tools.javac.code.Kinds.*;

public class HashCollisionTest {
    public static void main(String... args) throws Exception {
        new HashCollisionTest().run();
    }

    void run() throws Exception {
        
        Context context = new Context();
        JavacFileManager.preRegister(context); 
        names = Names.instance(context);       
        symtab = Symtab.instance(context);

        
        Scope emptyScope = new Scope(symtab.unnamedPackage); 
        Field sHashMask = Scope.class.getDeclaredField("hashMask");
        sHashMask.setAccessible(true);
        scopeHashMask = sHashMask.getInt(emptyScope);
        log("scopeHashMask: " + scopeHashMask);

        
        
        Name entry = names.fromString("Entry");

        
        
        
        
        
        Name outerName;
        Name innerName;
        StringBuilder sb = new StringBuilder("C");
        int i = 0;
        do {
            sb.append(Integer.toString(i % 10));
            innerName = names.fromString(sb + "$Entry");
        } while (!clash(entry, innerName) && (++i) < MAX_TRIES);

        if (clash(entry, innerName)) {
            log("Detected expected hash collision for " + entry + " and " + innerName
                    + " after " + i + " tries");
        } else {
            throw new Exception("No potential collision found after " + i + " tries");
        }

        outerName = names.fromString(sb.toString());

        

        
        ClassSymbol cc = createClass(names.fromString("C"), symtab.unnamedPackage);
        ClassSymbol ce = createClass(entry, cc);

        
        PackageSymbol p = new PackageSymbol(names.fromString("p"), symtab.rootPackage);
        p.members_field = new Scope(p);
        ClassSymbol inner = createClass(innerName, p);
        
        ClassSymbol outer = createClass(outerName, p);

        
        log ("createStarImportScope");

        
        
        Scope starImportScope;
        Method importAll;
        PackageSymbol pkg = new PackageSymbol(names.fromString("pkg"), symtab.rootPackage);
        try {
            Class<?> c = Class.forName("com.sun.tools.javac.code.Scope$StarImportScope");
            Constructor ctor = c.getDeclaredConstructor(new Class[] { Symbol.class });
            importAll = c.getDeclaredMethod("importAll", new Class[] { Scope.class });
            starImportScope = (Scope) ctor.newInstance(new Object[] { pkg });
        } catch (ClassNotFoundException e) {
            starImportScope = new ImportScope(pkg);
            importAll = null;
        }

        dump("initial", starImportScope);

        
        Scope p_members = p.members();
        if (importAll != null) {
            importAll.invoke(starImportScope, p_members);
        } else {
            Scope fromScope = p_members;
            Scope toScope = starImportScope;
            
            
            for (Scope.Entry e = fromScope.elems; e != null; e = e.sibling) {
                if (e.sym.kind == TYP && !toScope.includes(e.sym))
                    toScope.enter(e.sym, fromScope);
            }
        }

        dump("imported p", starImportScope);

        
        starImportScope.enter(ce, cc.members_field);
        dump("imported ce", starImportScope);

        

        
        p.members_field.remove(inner);
        inner.name = entry;
        inner.owner = outer;
        outer.members_field.enter(inner);

        
        Scope.Entry e = starImportScope.lookup(entry);
        dump("final", starImportScope);

        if (e.sym == null)
            throw new Exception("symbol not found: " + entry);
    }

    
    boolean clash(Name n1, Name n2) {
        log(n1 + " hc:" + n1.hashCode() + " v:" + (n1.hashCode() & scopeHashMask) + ", " +
                n2 + " hc:" + n2.hashCode() + " v:" + (n2.hashCode() & scopeHashMask));
        return (n1.hashCode() & scopeHashMask) == (n2.hashCode() & scopeHashMask);
    }

    
    ClassSymbol createClass(Name name, Symbol owner) {
        ClassSymbol sym = new ClassSymbol(0, name, owner);
        sym.members_field = new Scope(sym);
        if (owner != symtab.unnamedPackage)
            owner.members().enter(sym);
        return sym;
    }

    
    void dump(String label, Scope s) throws Exception {
        dump(label, s, System.err);
    }

    
    void dump(String label, Scope s, PrintStream out) throws Exception {
        out.println(label);
        Field sTable = Scope.class.getDeclaredField("table");
        sTable.setAccessible(true);

        out.println("owner:" + s.owner);
        Scope.Entry[] table = (Scope.Entry[]) sTable.get(s);
        for (int i = 0; i < table.length; i++) {
            if (i > 0)
                out.print(", ");
            out.print(i + ":" + toString(table[i], table, false));
        }
        out.println();
    }

    
    String toString(Scope.Entry e, Scope.Entry[] table, boolean ref) {
        if (e == null)
            return "null";
        if (e.sym == null)
            return "sent"; 
        if (ref) {
            int index = indexOf(table, e);
            if (index != -1)
                return String.valueOf(index);
        }
        return "(" + e.sym.name + ":" + e.sym
                + ",shdw:" + toString(e.next(), table, true)
                + ",sibl:" + toString(e.sibling, table, true)
                + ((e.sym.owner != e.scope.owner)
                    ? (",BOGUS[" + e.sym.owner + "," + e.scope.owner + "]")
                    : "")
                + ")";
    }

    <T> int indexOf(T[] array, T item) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == item)
                return i;
        }
        return -1;
    }

    
    void log(String msg) {
        System.err.println(msg);
    }

    int MAX_TRIES = 100; 
    int scopeHashMask;

    Names names;
    Symtab symtab;
}
