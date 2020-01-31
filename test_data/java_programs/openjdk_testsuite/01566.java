

package org.openjdk.tests.separate;

import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.ConcurrentHashMap;
import java.io.*;
import java.net.URI;
import javax.tools.*;

import com.sun.source.util.JavacTask;

import static org.openjdk.tests.separate.SourceModel.Type;
import static org.openjdk.tests.separate.SourceModel.Class;
import static org.openjdk.tests.separate.SourceModel.Extends;
import static org.openjdk.tests.separate.SourceModel.SourceProcessor;

public class Compiler {

    public enum Flags {
        VERBOSE, 
        USECACHE 
                 
                 
    }

    private static final AtomicInteger counter = new AtomicInteger();
    private static final String targetDir = "gen-separate";
    private static final File root = new File(targetDir);
    private static ConcurrentHashMap<String,File> cache =
            new ConcurrentHashMap<>();

    Set<Flags> flags;

    private JavaCompiler systemJavaCompiler;
    private StandardJavaFileManager fm;
    private List<File> tempDirs;
    private List<ClassFilePreprocessor> postprocessors;

    private static class SourceFile extends SimpleJavaFileObject {
        private final String content;

        public SourceFile(String name, String content) {
            super(URI.create("myfo:/" + name + ".java"), Kind.SOURCE);
            this.content = content;
        }

        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return toString();
        }

        public String toString() { return this.content; }
    }

    public Compiler(Flags ... flags) {
        setFlags(flags);
        this.tempDirs = new ArrayList<>();
        this.postprocessors = new ArrayList<>();
        this.systemJavaCompiler = ToolProvider.getSystemJavaCompiler();
        this.fm = systemJavaCompiler.getStandardFileManager(null, null, null);
    }

    public void setFlags(Flags ... flags) {
        this.flags = new HashSet<>(Arrays.asList(flags));
    }

    public void addPostprocessor(ClassFilePreprocessor cfp) {
        this.postprocessors.add(cfp);
    }

    
    public ClassLoader compile(Type ... types) {
        ClassFilePreprocessor[] cfps = this.postprocessors.toArray(
            new ClassFilePreprocessor[0]);

        DirectedClassLoader dcl = new DirectedClassLoader(cfps);

        for (Type t : types) {
            for (Map.Entry<String,File> each : compileHierarchy(t).entrySet()) {
                dcl.setLocationFor(each.getKey(), each.getValue());
            }
        }
        return dcl;
    }

    
    public java.lang.Class<?> compileAndLoad(Type type)
            throws ClassNotFoundException {

        ClassLoader loader = compile(type);
        return java.lang.Class.forName(type.getName(), false, loader);
    }

    
    private Map<String,File> compileHierarchy(Type type) {
        HashMap<String,File> outputDirs = new HashMap<>();

        File outDir = compileOne(type);
        outputDirs.put(type.getName(), outDir);

        Class superClass = type.getSuperclass();
        if (superClass != null)
            outputDirs.putAll(compileHierarchy(superClass));
        for (Extends ext : type.getSupertypes())
            outputDirs.putAll(compileHierarchy(ext.getType()));

        return outputDirs;
    }

    private File compileOne(Type type) {
        if (this.flags.contains(Flags.USECACHE)) {
            File dir = cache.get(type.getName());
            if (dir != null) {
                return dir;
            }
        }
        List<JavaFileObject> files = new ArrayList<>();
        SourceProcessor accum =
            (name, src) -> { files.add(new SourceFile(name, src)); };

        Collection<Type> deps = type.typeDependencies(type.isFullCompilation());
        for (Type dep : deps) {
            if (type.isFullCompilation())
                dep.generate(accum);
            else
                dep.generateAsDependency(accum, type.methodDependencies());
        }

        type.generate(accum);

        JavacTask ct = (JavacTask)this.systemJavaCompiler.getTask(
            null, this.fm, null, null, null, files);
        File destDir = null;
        do {
            int value = counter.incrementAndGet();
            destDir = new File(root, Integer.toString(value));
        } while (destDir.exists());

        if (this.flags.contains(Flags.VERBOSE)) {
            System.out.println("Compilation unit for " + type.getName() +
                " : compiled into " + destDir);
            for (JavaFileObject jfo : files) {
                System.out.println(jfo.toString());
            }
        }

        try {
            destDir.mkdirs();
            this.fm.setLocation(
                StandardLocation.CLASS_OUTPUT, Arrays.asList(destDir));
        } catch (IOException e) {
            throw new RuntimeException(
                "IOException encountered during compilation", e);
        }
        Boolean result = ct.call();
        if (result == Boolean.FALSE) {
            throw new RuntimeException(
                "Compilation failure in " + type.getName() + " unit");
        }
        if (this.flags.contains(Flags.USECACHE)) {
            File existing = cache.putIfAbsent(type.getName(), destDir);
            if (existing != null) {
                deleteDir(destDir);
                return existing;
            }
        } else {
        this.tempDirs.add(destDir);
        }
        return destDir;
    }

    private static void deleteDir(File dir) {
        for (File f : dir.listFiles()) {
            f.delete();
        };
        dir.delete();
    }

    public void cleanup() {
        if (!this.flags.contains(Flags.USECACHE)) {
            for (File d : tempDirs) {
                deleteDir(d);
            };
            tempDirs = new ArrayList<>();
        }
    }

    
    
    
    public static void purgeCache() {
        for (Map.Entry<String,File> entry : cache.entrySet()) {
            cache.remove(entry.getKey());
            deleteDir(entry.getValue());
        }
    }
}
