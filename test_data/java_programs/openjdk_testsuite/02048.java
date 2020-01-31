



import java.util.Random;
import java.util.Map;
import java.util.HashMap;
import com.sun.tools.javac.util.*;
import com.sun.tools.javac.code.*;
import com.sun.tools.javac.code.Scope.*;
import com.sun.tools.javac.code.Symbol.*;
import com.sun.tools.javac.file.JavacFileManager;

public class CompoundScopeTest {
    public static void main(String... args) throws Exception {
        new CompoundScopeTest().run(args);
    }

    static final int MAX_SYMBOLS_COUNT = 20;
    static final int PASSES = 10;

    void run(String... args) throws Exception {
        int count = PASSES;

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

    
    void log(String msg) {
        System.err.println(msg);
    }

    
    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    Random rgen;
    long seed = 0;

    int errors;

    
    class Test {

        List<Symbol> elems = List.nil();
        Map<Name, List<Symbol>> shadowedMap = new HashMap<Name, List<Symbol>>();

        
        void run() throws Exception {
            log ("starting test");
            setup();
            Scope[] scopes = { createScope(rgen.nextInt(MAX_SYMBOLS_COUNT)),
                               createScope(rgen.nextInt(MAX_SYMBOLS_COUNT)),
                               createScope(rgen.nextInt(MAX_SYMBOLS_COUNT)) };
            boolean[][] scopeNesting = { {false, true, false, true},
                                   {false, true, true, true},
                                   {false, false, true, true} };
            
            for (int i = 0 ; i < 4 ; i ++) {
                CompoundScope root = new CompoundScope(symtab.noSymbol);
                CompoundScope sub = new CompoundScope(symtab.noSymbol);
                boolean subAdded = false;
                for (int sc = 0 ; sc < 3 ; sc ++) {
                    if (scopeNesting[sc][i]) {
                        sub.addSubScope(scopes[sc]);
                        if (!subAdded) {
                            root.addSubScope(sub);
                            subAdded = true;
                        }
                    } else {
                        root.addSubScope(scopes[sc]);
                    }
                }
                log("testing scope: " + root);
                checkElems(root, null);
                checkElems(root, new OddFilter());
                checkShadowed(root, null);
                checkShadowed(root, new OddFilter());
            }
        }

        class OddFilter implements Filter<Symbol> {
            public boolean accepts(Symbol s) {
                Name numPart = s.name.subName(1, s.name.length());
                return Integer.parseInt(numPart.toString()) % 2 != 0;
            }
        }

        
        Scope createScope(int nelems) {
            Scope s = new Scope(symtab.noSymbol);
            for (int i = 0 ; i < nelems ; i++) {
                Symbol sym = new TypeVariableSymbol(0, names.fromString("s" + i), null, null);
                s.enter(sym);
                elems = elems.prepend(sym);
                List<Symbol> shadowed = shadowedMap.get(sym.name);
                if (shadowed == null) {
                    shadowed = List.nil();
                }
                shadowedMap.put(sym.name, shadowed.prepend(sym));
            }
            return s;
        }

        
        void setup() {
            log ("setup");
            context = new Context();
            JavacFileManager.preRegister(context); 
            names = Names.instance(context);       
            symtab = Symtab.instance(context);
        }

        
        void checkElems(CompoundScope cs, Filter<Symbol> sf) {
            int count = 0;
            ListBuffer<Symbol> found = new ListBuffer<>();
            List<Symbol> allSymbols = sf == null ?
                    elems :
                    filter(elems, sf);
            int expectedCount = allSymbols.length();
            for (Symbol s : sf == null ? cs.getElements() : cs.getElements(sf)) {
                checkSameSymbols(s, allSymbols.head);
                allSymbols = allSymbols.tail;
                found.append(s);
                count++;
            }
            if (count != expectedCount) {
                error("CompoundScope.getElements() did not returned enough symbols");
            }
        }

        
        void checkShadowed(CompoundScope cs, Filter<Symbol> sf) {
            for (Map.Entry<Name, List<Symbol>> shadowedEntry : shadowedMap.entrySet()) {
                int count = 0;
                List<Symbol> shadowed = sf == null ?
                    shadowedEntry.getValue() :
                    filter(shadowedEntry.getValue(), sf);
                int expectedCount = shadowed.length();
                Name name = shadowedEntry.getKey();
                for (Symbol s : sf == null ? cs.getElementsByName(name) : cs.getElementsByName(name, sf)) {
                    checkSameSymbols(s, shadowed.head);
                    shadowed = shadowed.tail;
                    count++;
                }
                if (count != expectedCount) {
                    error("CompoundScope.lookup() did not returned enough symbols for name " + name);
                }
            }
        }

        List<Symbol> filter(List<Symbol> elems, Filter<Symbol> sf) {
            ListBuffer<Symbol> res = new ListBuffer<>();
            for (Symbol s : elems) {
                if (sf.accepts(s)) {
                    res.append(s);
                }
            }
            return res.toList();
        }

        void checkSameSymbols(Symbol found, Symbol req) {
            if (found != req) {
                error("Symbol mismatch - found    : " + found + ":" + found.hashCode() + "\n" +
                      "                  required : " + req + ":" + req.hashCode());
            }
        }

        Context context;
        Symtab symtab;
        Names names;
    }
}
