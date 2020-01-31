



import java.lang.reflect.*;
import java.util.*;
import java.util.List;
import com.sun.tools.javac.util.*;
import com.sun.tools.javac.code.*;
import com.sun.tools.javac.code.Scope.*;
import com.sun.tools.javac.code.Symbol.*;
import com.sun.tools.javac.file.JavacFileManager;
import static com.sun.tools.javac.code.Kinds.*;

public class StarImportTest {
    public static void main(String... args) throws Exception {
        new StarImportTest().run(args);
    }

    void run(String... args) throws Exception {
        int count = 1;

        for (int i = 0; i < args.length; i++) {
            String arg = args[i];
            if (arg.equals("-seed") && (i + 1 < args.length))
                seed = Long.parseLong(args[++i]);
            else if(arg.equals("-tests") && (i + 1 < args.length))
                count = Integer.parseInt(args[++i]);
            else
                throw new Exception("unknown arg: " + arg);
        }

        rgen = new Random(seed);

        for (int i = 0; i < count; i++) {
            Test t = new Test();
            t.run();
        }

        if (errors > 0)
            throw new Exception(errors + " errors found");
    }

    
    <T> T random(T... choices) {
        return choices[rgen.nextInt(choices.length)];
    }

    
    void log(String msg) {
        System.err.println(msg);
    }

    
    void log(String msg, Scope s) {
        System.err.print(msg);
        System.err.print(": ");
        String sep = "(";
        for (Scope.Entry se = s.elems; se != null; se = se.sibling) {
            for (Scope.Entry e = se; e.sym != null; e = e.next()) {
                System.err.print(sep + e.sym.name + ":" + e.sym);
                sep = ",";
            }
            System.err.print(")");
            sep = ", (";
        }
        System.err.println();
    }

    
    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    Random rgen;
    long seed = 0;

    int errors;

    enum SetupKind { NAMES, PACKAGE, CLASS };
    static final int MAX_SETUP_COUNT = 50;
    static final int MAX_SETUP_NAME_COUNT = 20;
    static final int MAX_SETUP_PACKAGE_COUNT = 20;
    static final int MAX_SETUP_CLASS_COUNT = 20;

    
    class Test {
        
        void run() throws Exception {
            log ("starting test");
            setup();
            createStarImportScope();
            test();
        }

        
        void setup() {
            log ("setup");
            context = new Context();
            JavacFileManager.preRegister(context); 
            names = Names.instance(context);       
            symtab = Symtab.instance(context);
            int setupCount = rgen.nextInt(MAX_SETUP_COUNT);
            for (int i = 0; i < setupCount; i++) {
                switch (random(SetupKind.values())) {
                    case NAMES:
                        setupNames();
                        break;
                    case PACKAGE:
                        setupPackage();
                        break;
                    case CLASS:
                        setupClass();
                        break;
                }
            }
        }

        
        void setupNames() {
            int count = rgen.nextInt(MAX_SETUP_NAME_COUNT);
            log("setup: creating " + count + " new names");
            for (int i = 0; i < count; i++) {
                names.fromString("n" + (++nextNameSerial));
            }
        }

        
        void setupPackage() {
            Name name = names.fromString("p" + (++nextPackageSerial));
            int count = rgen.nextInt(MAX_SETUP_PACKAGE_COUNT);
            log("setup: creating package " + name + " with " + count + " entries");
            PackageSymbol p = new PackageSymbol(name, symtab.rootPackage);
            p.members_field = new Scope(p);
            for (int i = 0; i < count; i++) {
                String outer = name + "c" + i;
                String suffix = random(null, "$Entry", "$Entry2");
                ClassSymbol c1 = createClass(names.fromString(outer), p);

                if (suffix != null) {
                    ClassSymbol c2 = createClass(names.fromString(outer + suffix), p);

                }
            }

            packages.add(p);
            imports.add(p);
        }

        
        void setupClass() {
            Name name = names.fromString("c" + (++nextClassSerial));
            int count = rgen.nextInt(MAX_SETUP_CLASS_COUNT);
            log("setup: creating class " + name + " with " + count + " entries");
            ClassSymbol c = createClass(name, symtab.unnamedPackage);

            for (int i = 0; i < count; i++) {
                ClassSymbol ic = createClass(names.fromString("Entry" + i), c);

            }
            classes.add(c);
            imports.add(c);
        }

        
        void createStarImportScope() throws Exception {
            log ("createStarImportScope");
            PackageSymbol pkg = new PackageSymbol(names.fromString("pkg"), symtab.rootPackage);

            
            
            Method importAll;
            try {
                Class<?> c = Class.forName("com.sun.tools.javac.code.Scope$StarImportScope");
                Constructor ctor = c.getDeclaredConstructor(new Class[] { Symbol.class });
                importAll = c.getDeclaredMethod("importAll", new Class[] { Scope.class });
                starImportScope = (Scope) ctor.newInstance(new Object[] { pkg });
            } catch (ClassNotFoundException e) {
                starImportScope = new ImportScope(pkg);
                importAll = null;
            }
            starImportModel = new Model();

            for (Symbol imp: imports) {
                Scope members = imp.members();
                if (importAll != null) {

                    importAll.invoke(starImportScope, members);
                } else {
                    Scope fromScope = members;
                    Scope toScope = starImportScope;
                    
                    
                    for (Scope.Entry e = fromScope.elems; e != null; e = e.sibling) {
                        if (e.sym.kind == TYP && !toScope.includes(e.sym))
                            toScope.enter(e.sym, fromScope);
                    }
                }

                for (Scope.Entry e = members.elems; e != null; e = e.sibling) {
                    starImportModel.enter(e.sym);
                }
            }


            starImportModel.check(starImportScope);
        }

        
        void test() {
            log ("test");
            List<ClassSymbol> nestedClasses = new LinkedList<ClassSymbol>();
            for (PackageSymbol p: packages) {
                for (Scope.Entry se = p.members_field.elems; se != null; se = se.sibling) {
                    if (se.sym.name.toString().contains("$"))
                        nestedClasses.add((ClassSymbol) se.sym);
                }
            }

            for (int i = nestedClasses.size(); i > 0; i--) {
                
                ClassSymbol sym = nestedClasses.remove(rgen.nextInt(i));
                log("adjusting class " + sym);

                
                starImportModel.remove(sym);

                String s = sym.name.toString();
                int dollar = s.indexOf("$");

                
                assert (sym.owner.kind == PCK);

                
                Name outerName = names.fromString(s.substring(0, dollar));

                Scope.Entry outerEntry = sym.owner.members().lookup(outerName);
                ClassSymbol outer = (ClassSymbol) outerEntry.sym;


                
                sym.owner.members().remove(sym);

                
                sym.name = names.fromString(s.substring(dollar + 1));
                outer.members().enter(sym);
                sym.owner = outer;

                
                starImportModel.check(starImportScope);
            }
        }

        ClassSymbol createClass(Name name, Symbol owner) {
            ClassSymbol sym = new ClassSymbol(0, name, owner);
            sym.members_field = new Scope(sym);
            if (owner != symtab.unnamedPackage)
                owner.members().enter(sym);
            return sym;
        }

        Context context;
        Symtab symtab;
        Names names;
        int nextNameSerial;
        List<PackageSymbol> packages = new ArrayList<PackageSymbol>();
        int nextPackageSerial;
        List<ClassSymbol> classes = new ArrayList<ClassSymbol>();
        List<Symbol> imports = new ArrayList<Symbol>();
        int nextClassSerial;

        Scope starImportScope;
        Model starImportModel;
    }

    class Model {
        private Map<Name, Set<Symbol>> map = new HashMap<Name, Set<Symbol>>();
        private Set<Symbol> bogus = new HashSet<Symbol>();

        void enter(Symbol sym) {
            Set<Symbol> syms = map.get(sym.name);
            if (syms == null)
                map.put(sym.name, syms = new LinkedHashSet<Symbol>());
            syms.add(sym);
        }

        void remove(Symbol sym) {
            Set<Symbol> syms = map.get(sym.name);
            if (syms == null)
                error("no entries for " + sym.name + " found in reference model");
            else {
                boolean ok = syms.remove(sym);
                if (ok) {

                } else {
                    error(sym.name + " not found in reference model");
                }
                if (syms.isEmpty())
                    map.remove(sym.name);
            }
        }

        
        void check(Scope scope) {
            
            int bogusCount = 0;
            for (Scope.Entry se = scope.elems; se != null; se = se.sibling) {
                Symbol sym = se.sym;
                if (sym.owner != se.scope.owner) {
                    if (bogus.contains(sym)) {
                        bogusCount++;
                    } else {
                        log("Warning: " + sym.name + ":" + sym + " appears to be bogus");
                        bogus.add(sym);
                    }
                } else {
                    Set<Symbol> syms = map.get(sym.name);
                    if (syms == null) {
                        error("check: no entries found for " + sym.name + ":" + sym + " in reference map");
                    } else  if (!syms.contains(sym)) {
                        error("check: symbol " + sym.name + ":" + sym + " not found in reference map");
                    }
                }
            }
            if (bogusCount > 0) {
                log("Warning: " + bogusCount + " other bogus entries previously reported");
            }

            
            for (Map.Entry<Name,Set<Symbol>> me: map.entrySet()) {
                Name name = me.getKey();
                Scope.Entry se = scope.lookup(name);
                assert (se != null);
                if (se.sym == null) {
                    error("check: no entries found for " + name + " in scope");
                    continue;
                }
            nextSym:
                for (Symbol sym: me.getValue()) {
                    for (Scope.Entry e = se; e.sym != null; e = e.next()) {
                        if (sym == e.sym)
                            continue nextSym;
                    }
                    error("check: symbol " + sym + " not found in scope");
                }
            }
        }
    }
}
