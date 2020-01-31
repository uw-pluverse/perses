



import java.io.*;
import java.net.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.tools.*;

import com.sun.tools.javac.comp.Attr;
import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.main.Main;
import com.sun.tools.javac.processing.JavacProcessingEnvironment;
import com.sun.tools.javac.util.Context;

public class T7021650 extends JavacTestingAbstractProcessor {
    public static void main(String... args) throws Exception {
        new T7021650().run();
    }

    static File testSrc = new File(System.getProperty("test.src"));
    static final int MAX_ROUNDS = 3;

    
    void run() throws Exception {
        Counter demoCounter = new Counter();
        Counter myAttrCounter = new Counter();

        Context context = new Context();
        
        
        
        
        
        context.put(JavaFileManager.class, new Context.Factory<JavaFileManager>() {
            public JavaFileManager make(Context c) {
                return new JavacFileManager(c, true, null) {
                    @Override
                    protected ClassLoader getClassLoader(URL[] urls) {
                        return new URLClassLoader(urls, T7021650.class.getClassLoader());
                    }
                };
            }
        });

        Demo.preRegister(context, demoCounter);
        MyAttr.preRegister(context, myAttrCounter);

        String[] args = {
            "-d", ".",
            "-processor", T7021650.class.getName(),
            "-XprintRounds",
            new File(testSrc, T7021650.class.getName() + ".java").getPath()
        };

        compile(context, args);

        
        
        checkEqual("demoCounter", demoCounter.count, MAX_ROUNDS + 2);

        
        
        checkEqual("myAttrCounter", myAttrCounter.count, MAX_ROUNDS + 3);
    }

    void compile(Context context, String... args) throws Exception {
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        Main m = new Main("javac", pw);
        Main.Result res = m.compile(args, context);
        pw.close();
        String out = sw.toString();
        if (!out.isEmpty())
            System.err.println(out);
        if (!res.isOK())
            throw new Exception("compilation failed unexpectedly: result=" + res);
    }

    void checkEqual(String label, int found, int expect) throws Exception {
        if (found != expect)
            throw new Exception("unexpected value for " + label
                    + ": expected " + expect
                    + ": found " + found);
    }

    

    
    static class Demo {
        static void preRegister(Context context, final Counter counter) {
            context.put(Demo.class, new Context.Factory<Demo>() {
                public Demo make(Context c) {
                    counter.count++;
                    return new Demo(c);
                }
            });
        }

        Demo(Context c) {
            c.put(Demo.class, this);
        }

        static Demo instance(Context context) {
            return context.get(Demo.class);
        }
    }

    
    static class MyAttr extends Attr {
        static void preRegister(Context context, final Counter counter) {
            context.put(attrKey, new Context.Factory<Attr>() {
                public Attr make(Context c) {
                    counter.count++;
                    return new MyAttr(c);
                }
            });
        }

        MyAttr(Context c) {
            super(c);
        }
    }

    static class Counter {
        int count;
    }

    

    int round = 0;

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        round++;

        Context context = ((JavacProcessingEnvironment) processingEnv).getContext();

        
        check("Demo", Demo.instance(context), Demo.class);
        check("Attr", Attr.instance(context), MyAttr.class);

        
        
        if (round <= MAX_ROUNDS) {
            String pkg = "p";
            String currClass = "Gen" + round;
            String curr = pkg + "." + currClass;
            String next = (pkg + ".Gen" + (round + 1));
            StringBuilder text = new StringBuilder();
            text.append("package ").append(pkg).append(";\n");
            text.append("public class ").append(currClass).append(" {\n");
            if (round < MAX_ROUNDS)
                text.append("    ").append(next).append(" x;\n");
            text.append("}\n");

            try {
                JavaFileObject fo = filer.createSourceFile(curr);
                Writer out = fo.openWriter();
                try {
                    out.write(text.toString());
                } finally {
                    out.close();
                }
            } catch (IOException e) {
                throw new Error(e);
            }
        }

        return true;
    }

    void check(String label, Object o, Class<?> clazz) {
        if (o == null)
            throw new IllegalStateException(label + ": no item found");
        if (!clazz.isAssignableFrom(o.getClass()))
            throw new IllegalStateException(label + ": unexpected class: " + o.getClass());
    }
}
