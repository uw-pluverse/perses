


import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;

public class ShadowingTest {

    
    
    
    private enum MethodContext {
        STATIC("static "),
        INSTANCE("");

        public final String methodcontext;

        MethodContext(final String methodcontext) {
            this.methodcontext = methodcontext;
        }
    }

    
    
    

    private enum MethodTypeParameterDecl {
        NO(""),
        YES("<T extends Number> ");

        public final String tyvar;

        MethodTypeParameterDecl(final String tyvar) {
            this.tyvar = tyvar;
        }
    }

    private enum InsideDef {
        NONE(""),
        STATIC("static class T { public void inner() {} }\n"),
        INSTANCE("class T { public void inner() {} }\n");

        public final String instancedef;

        InsideDef(final String instancedef) {
            this.instancedef = instancedef;
        }
    }

    private enum TypeParameterDecl {
        NO(""),
        YES("<T extends Collection>");

        public final String tyvar;

        TypeParameterDecl(final String tyvar) {
            this.tyvar = tyvar;
        }
    }

    
    
    private enum MethodCall {
        
        METHOD_TYPEVAR("intValue"),
        
        INNER_CLASS("inner"),
        
        TYPEVAR("iterator"),
        
        OUTER_CLASS("outer");

        public final String methodcall;

        MethodCall(final String methodcall) {
            this.methodcall = methodcall;
        }

    }

    public boolean succeeds(final MethodCall call,
                            final MethodTypeParameterDecl mtyvar,
                            final MethodContext ctx,
                            final InsideDef inside,
                            final TypeParameterDecl tyvar) {
        switch(call) {
            
        case METHOD_TYPEVAR: switch(mtyvar) {
                
                
            case YES: return true;
                
            default: return false;
            }
            
        case INNER_CLASS: switch(mtyvar) {
                
                
            case NO: switch(ctx) {
                    
                case INSTANCE: switch(inside) {
                    case INSTANCE:
                    case STATIC:
                        return true;
                    default: return false;
                    }
                case STATIC: switch(inside) {
                        
                        
                        
                    case STATIC: return true;
                    case INSTANCE: switch(tyvar) {
                            
                            
                            
                            
                        case NO: return true;
                        default: return false;
                        }
                        
                        
                    default: return false;
                    }
                    
                default: return false;
                }
            default: return false;
            }
            
        case TYPEVAR: switch(mtyvar) {
                
                
            case NO: switch(ctx) {
                case INSTANCE: switch(inside) {
                        
                        
                        
                    case NONE: switch(tyvar) {
                            
                        case YES: return true;
                        default: return false;
                        }
                    default: return false;
                    }
                default: return false;
                }
            default: return false;
            }
            
        case OUTER_CLASS: switch(mtyvar) {
            case NO: switch(inside) {
                case NONE: switch(tyvar) {
                        
                        
                        
                        
                        
                    case NO: return true;
                    default: return false;
                    }
                default: return false;
                }
            default: return false;
            }
        }
        return false;
    }

    private static final File classesdir = new File("7118412");

    private int errors = 0;

    private int dirnum = 0;

    private void doTest(final MethodTypeParameterDecl mtyvar,
                        final TypeParameterDecl tyvar,
                        final InsideDef insidedef, final MethodContext ctx,
                        final MethodCall call)
        throws IOException {
        final String content = "import java.util.Collection;\n" +
            "class Test" + tyvar.tyvar + " {\n" +
            "  " + insidedef.instancedef +
            "  " + ctx.methodcontext + mtyvar.tyvar + "void test(T t) { t." +
            call.methodcall + "(); }\n" +
            "}\n" +
            "class T { void outer() {} }\n";
        final File dir = new File(classesdir, "" + dirnum);
        final File Test_java = writeFile(dir, "Test.java", content);
        dirnum++;
        if(succeeds(call, mtyvar, ctx, insidedef, tyvar)) {
            if(!assert_compile_succeed(Test_java))
                System.err.println("Failed file:\n" + content);
        }
        else {
            if(!assert_compile_fail(Test_java))
                System.err.println("Failed file:\n" + content);
        }
    }

    private void run() throws Exception {
        classesdir.mkdir();
        for(MethodTypeParameterDecl mtyvar : MethodTypeParameterDecl.values())
            for(TypeParameterDecl tyvar : TypeParameterDecl.values())
                for(InsideDef insidedef : InsideDef.values())
                    for(MethodContext ctx : MethodContext.values())
                        for(MethodCall methodcall : MethodCall.values())
                            doTest(mtyvar, tyvar, insidedef, ctx, methodcall);
        if (errors != 0)
            throw new Exception("ShadowingTest test failed with " +
                                errors + " errors.");
    }

    private boolean assert_compile_fail(final File file) {
        final String filename = file.getPath();
        final String[] args = { filename };
        final StringWriter sw = new StringWriter();
        final PrintWriter pw = new PrintWriter(sw);
        final int rc = com.sun.tools.javac.Main.compile(args, pw);
        pw.close();
        if (rc == 0) {
            System.err.println("Compilation of " + file.getName() +
                               " didn't fail as expected.");
            errors++;
            return false;
        } else return true;
    }

    private boolean assert_compile_succeed(final File file) {
        final String filename = file.getPath();
        final String[] args = { filename };
        final StringWriter sw = new StringWriter();
        final PrintWriter pw = new PrintWriter(sw);
        final int rc = com.sun.tools.javac.Main.compile(args, pw);
        pw.close();
        if (rc != 0) {
            System.err.println("Compilation of " + file.getName() +
                               " didn't succeed as expected.  Output:");
            System.err.println(sw.toString());
            errors++;
            return false;
        } else return true;
    }

    private File writeFile(final File dir,
                           final String path,
                           final String body) throws IOException {
        final File f = new File(dir, path);
        f.getParentFile().mkdirs();
        final FileWriter out = new FileWriter(f);
        out.write(body);
        out.close();
        return f;
    }

    public static void main(String... args) throws Exception {
        new ShadowingTest().run();
    }

}
