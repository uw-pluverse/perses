



import java.io.*;
import java.util.*;
import javax.tools.*;
import com.sun.tools.classfile.*;


public class CheckResourceKeys {
    
    public static void main(String... args) throws Exception {
        CheckResourceKeys c = new CheckResourceKeys();
        if (c.run(args))
            return;

        if (is_jtreg())
            throw new Exception(c.errors + " errors occurred");
        else
            System.exit(1);
    }

    static boolean is_jtreg() {
        return (System.getProperty("test.src") != null);
    }

    
    boolean run(String... args) throws Exception {
        boolean findDeadKeys = false;
        boolean findMissingKeys = false;

        if (args.length == 0) {
            if (is_jtreg()) {
                findDeadKeys = true;
                findMissingKeys = true;
            } else {
                System.err.println("Usage: java CheckResourceKeys <options>");
                System.err.println("where options include");
                System.err.println("  -finddeadkeys      find keys in resource bundles which are no longer required");
                System.err.println("  -findmissingkeys   find keys in resource bundles that are required but missing");
                return true;
            }
        } else {
            for (String arg: args) {
                if (arg.equalsIgnoreCase("-finddeadkeys"))
                    findDeadKeys = true;
                else if (arg.equalsIgnoreCase("-findmissingkeys"))
                    findMissingKeys = true;
                else
                    error("bad option: " + arg);
            }
        }

        if (errors > 0)
            return false;

        Set<String> codeStrings = getCodeStrings();
        Set<String> resourceKeys = getResourceKeys();

        if (findDeadKeys)
            findDeadKeys(codeStrings, resourceKeys);

        if (findMissingKeys)
            findMissingKeys(codeStrings, resourceKeys);

        return (errors == 0);
    }

    
    void findDeadKeys(Set<String> codeStrings, Set<String> resourceKeys) {
        String[] prefixes = {
            "compiler.err.", "compiler.warn.", "compiler.note.", "compiler.misc.",
            "javac."
        };
        for (String rk: resourceKeys) {
            
            if (codeStrings.contains(rk))
                continue;

            
            String s = null;
            for (int i = 0; i < prefixes.length && s == null; i++) {
                if (rk.startsWith(prefixes[i])) {
                    s = rk.substring(prefixes[i].length());
                }
            }
            if (s == null) {
                error("Resource key does not start with a standard prefix: " + rk);
                continue;
            }

            if (codeStrings.contains(s))
                continue;

            
            if (s.endsWith(".1") && codeStrings.contains(s.substring(0, s.length() - 2)))
                continue;

            
            if (s.startsWith("verbose.") && codeStrings.contains(s.substring(8)))
                continue;

            
            if (isMandatoryWarningString(s))
                continue;

            
            if (knownRequired.contains(rk))
                continue;

            
            if (needToInvestigate.contains(rk))
                continue;

            error("Resource key not found in code: " + rk);
        }
    }

    
    private boolean isMandatoryWarningString(String s) {
        String[] bases = { "deprecated", "unchecked", "varargs", "sunapi" };
        String[] tails = { ".filename", ".filename.additional", ".plural", ".plural.additional", ".recompile" };
        for (String b: bases) {
            if (s.startsWith(b)) {
                String tail = s.substring(b.length());
                for (String t: tails) {
                    if (tail.equals(t))
                        return true;
                }
            }
        }
        return false;
    }

    Set<String> knownRequired = new TreeSet<String>(Arrays.asList(
        
        "compiler.err.cant.resolve.args",
        "compiler.err.cant.resolve.args.params",
        "compiler.err.cant.resolve.location.args",
        "compiler.err.cant.resolve.location.args.params",
        "compiler.misc.cant.resolve.location.args",
        "compiler.misc.cant.resolve.location.args.params",
        
        "compiler.misc.count.error",
        "compiler.misc.count.error.plural",
        "compiler.misc.count.warn",
        "compiler.misc.count.warn.plural",
        
        "compiler.warn.lintOption",
        
        "compiler.misc.base.membership"                                 
        ));


    Set<String> needToInvestigate = new TreeSet<String>(Arrays.asList(
        "compiler.misc.fatal.err.cant.close.loader",        
        "compiler.err.cant.read.file",                      
        "compiler.err.illegal.self.ref",                    
        "compiler.err.io.exception",                        
        "compiler.err.limit.pool.in.class",                 
        "compiler.err.name.reserved.for.internal.use",      
        "compiler.err.no.match.entry",                      
        "compiler.err.not.within.bounds.explain",           
        "compiler.err.signature.doesnt.match.intf",         
        "compiler.err.signature.doesnt.match.supertype",    
        "compiler.err.type.var.more.than.once",             
        "compiler.err.type.var.more.than.once.in.result",   
        "compiler.misc.ccf.found.later.version",            
        "compiler.misc.non.denotable.type",                 
        "compiler.misc.unnamed.package",                    
        "compiler.misc.verbose.retro",                      
        "compiler.misc.verbose.retro.with",                 
        "compiler.misc.verbose.retro.with.list",            
        "compiler.warn.proc.type.already.exists",           
        "javac.err.invalid.arg",                            
        "javac.opt.arg.class",                              
        "javac.opt.arg.pathname",                           
        "javac.opt.moreinfo",                               
        "javac.opt.nogj",                                   
        "javac.opt.printflat",                              
        "javac.opt.printsearch",                            
        "javac.opt.prompt",                                 
        "javac.opt.retrofit",                               
        "javac.opt.s",                                      
        "javac.opt.scramble",                               
        "javac.opt.scrambleall"                             
        ));

    
    void findMissingKeys(Set<String> codeStrings, Set<String> resourceKeys) {
        for (String cs: codeStrings) {
            if (cs.matches("[A-Za-z][^.]*\\..*")) {
                
                if (cs.matches(".*\\.java"))
                    continue;
                
                if (cs.matches("(com|java|javax|sun)\\.[A-Za-z.]+"))
                    continue;
                
                if (noResourceRequired.contains(cs))
                    continue;
                
                if (hasMatch(resourceKeys, cs))
                    continue;
                error("no match for \"" + cs + "\"");
            }
        }
    }
    
    private Set<String> noResourceRequired = new HashSet<String>(Arrays.asList(
            
            "application.home", 
            "env.class.path",
            "line.separator",
            "os.name",
            "user.dir",
            
            "ct.sym",
            "rt.jar",
            "tools.jar",
            
            "process.packages",
            "ignore.symbol.file",
            
            "compiler.",
            "compiler.misc.",
            "count.",
            "illegal.",
            "javac.",
            "verbose."
    ));

    
    boolean hasMatch(Set<String> resourceKeys, String s) {
        for (String rk: resourceKeys) {
            if (rk.endsWith(s))
                return true;
        }
        return false;
    }

    
    Set<String> getCodeStrings() throws IOException {
        Set<String> results = new TreeSet<String>();
        JavaCompiler c = ToolProvider.getSystemJavaCompiler();
        JavaFileManager fm = c.getStandardFileManager(null, null, null);
        JavaFileManager.Location javacLoc = findJavacLocation(fm);
        String[] pkgs = {
            "javax.annotation.processing",
            "javax.lang.model",
            "javax.tools",
            "com.sun.source",
            "com.sun.tools.javac"
        };
        for (String pkg: pkgs) {
            for (JavaFileObject fo: fm.list(javacLoc,
                    pkg, EnumSet.of(JavaFileObject.Kind.CLASS), true)) {
                String name = fo.getName();
                
                if (name.matches(".*resources.[A-Za-z_0-9]+\\.class.*")
                        || name.matches(".*CreateSymbols\\.class.*"))
                    continue;
                scan(fo, results);
            }
        }
        return results;
    }

    
    JavaFileManager.Location findJavacLocation(JavaFileManager fm) {
        JavaFileManager.Location[] locns =
            { StandardLocation.PLATFORM_CLASS_PATH, StandardLocation.CLASS_PATH };
        try {
            for (JavaFileManager.Location l: locns) {
                JavaFileObject fo = fm.getJavaFileForInput(l,
                    "com.sun.tools.javac.Main", JavaFileObject.Kind.CLASS);
                if (fo != null)
                    return l;
            }
        } catch (IOException e) {
            throw new Error(e);
        }
        throw new IllegalStateException("Cannot find javac");
    }

    
    void scan(JavaFileObject fo, Set<String> results) throws IOException {
        InputStream in = fo.openInputStream();
        try {
            ClassFile cf = ClassFile.read(in);
            for (ConstantPool.CPInfo cpinfo: cf.constant_pool.entries()) {
                if (cpinfo.getTag() == ConstantPool.CONSTANT_Utf8) {
                    String v = ((ConstantPool.CONSTANT_Utf8_info) cpinfo).value;
                    if (v.matches("[A-Za-z0-9-_.]+"))
                        results.add(v);
                }
            }
        } catch (ConstantPoolException ignore) {
        } finally {
            in.close();
        }
    }

    
    Set<String> getResourceKeys() {
        Set<String> results = new TreeSet<String>();
        for (String name : new String[]{"javac", "compiler"}) {
            ResourceBundle b =
                    ResourceBundle.getBundle("com.sun.tools.javac.resources." + name);
            results.addAll(b.keySet());
        }
        return results;
    }

    
    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    int errors;
}
