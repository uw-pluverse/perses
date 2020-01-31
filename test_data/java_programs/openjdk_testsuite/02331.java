

import java.io.*;
import java.lang.reflect.*;


public class ReflectionVisitor extends Tester.Visitor {

    public ReflectionVisitor(Tester tester) {
        super(tester);
    }

    public void error(String msg) {
        super.error("reflection: " + msg);
    }

    public void warn(String msg) {
        super.warn("reflection: " + msg);
    }

    boolean isEnum;
    boolean isInterface;
    boolean isAnon;
    boolean isLocal;
    boolean isMember;
    boolean isStatic;
    boolean isPublic;
    boolean isFinal;
    Class clazz;
    StringBuilder sb;

    
    void visitClass(final String cl, final File cfile, final StringBuilder sb)
        throws Exception {

        this.sb = sb;
        clazz = Class.forName(cl);
        isEnum = clazz.isEnum();
        isInterface = clazz.isInterface();
        isAnon = clazz.isAnonymousClass();
        isLocal = clazz.isLocalClass();
        isMember = clazz.isMemberClass();
        isStatic = ((clazz.getModifiers() & Modifier.STATIC) != 0);
        isPublic = ((clazz.getModifiers() & Modifier.PUBLIC) != 0);

        sb.append(isStatic ? "static " : "")
            .append(isPublic ? "public " : "")
            .append(isEnum ? "enum " : isInterface ? "interface " : "class ")
            .append(cl).append(" -- ")
            .append(isMember? "inner" : "" )
            .append(isLocal? "inner" : "" )
            .append(isAnon ?  "anon" : "")
            .append("\n");

        for (Constructor c : clazz.getDeclaredConstructors()) {
            testConstructor(c);
        }

        for (Method m :clazz.getDeclaredMethods()) {
            testMethod(m);
        }
    }

    void testConstructor(Constructor c) {

        String prefix = clazz.getName() + "." + c.getName() + "() - ";

        
        Parameter params[] = c.getParameters();
        int paramTypes =  c.getParameterTypes().length;
        if (paramTypes != params.length) {
            error(prefix + "number of parameter types (" + paramTypes
                  + ") != number of parameters (" + params.length + ")");
            return;
        }

        sb.append(clazz.getName()).append(".").append("<init>").append("(");
        String sep = "";

        
        if (params.length < 2 && isEnum) {
            error(prefix + "enum constuctor, two arguments expected");
        } else if (params.length < 1 && (isAnon || isLocal ||
                                         (isMember && !isStatic ))) {
            error(prefix + "class constuctor,expected implicit argument");
        }

        int i = -1;
        String param = null;
        for (Parameter p : c.getParameters()) {
            i++;
            String pname = p.getName();
            int pmodifier = p.getModifiers();
            isFinal = false;
            if (Modifier.isFinal(pmodifier)) {
                isFinal = true;
                pname = "final " + pname;
            }
            sb.append(sep).append(pname);
            if (p.isImplicit()) sb.append("/*implicit*/");
            if (p.isSynthetic()) sb.append("/*synthetic*/");
            sep = ", ";

            
            String expect = null;
            boolean allowImplicit = false;
            boolean allowSynthetic = false;
            if (isEnum) {
                if (i == 0) {
                    expect = "\\$enum\\$name";
                    allowSynthetic = true;
                } else if(i == 1) {
                    expect = "\\$enum\\$ordinal";
                    allowSynthetic = true;
                }
            } else if (i == 0) {
                if (isAnon) {
                    expect = "this\\$[0-9]+";
                    allowImplicit = true;
                    if (isFinal)
                        expect = "final this\\$[0-9]+";
                } else if (isLocal) {
                    expect = "this\\$[0-9]+";
                    allowImplicit = true;
                    if (isFinal)
                        expect = "final this\\$[0-9]+";
                } else if ((isMember && !isStatic)) {
                    expect = "this\\$[0-9]+";
                    allowImplicit = true;
                    if (!isPublic) {
                        
                        
                        
                        allowSynthetic = true;
                    }
                    if (isFinal)
                        expect = "final this\\$[0-9]+";
                }
            }

            
            if (p.isSynthetic() && p.isImplicit()) {
                error(prefix + "param[" + i + "]='" + pname +
                      "' both isImplicit() and isSynthetic()");
                break;
            }
            if (allowImplicit && allowSynthetic &&
                !(p.isSynthetic() || p.isImplicit())) {
                error(prefix + "param[" + i + "]='" + pname +
                      "' isImplicit() or isSynthetic() expected");
                break;
            }

            if (allowImplicit && !allowSynthetic && !p.isImplicit()) {
                error(prefix + "param[" + i + "]='" + pname +
                      "' isImplicit() expected");
                break;
            }
            if (!allowImplicit && allowSynthetic && !p.isSynthetic()) {
                error(prefix + "param[" + i + "]='" + pname +
                      "' isSynthetic() expected");
                break;
            }

            if (!allowImplicit && p.isImplicit()) {
                error(prefix + "param[" + i + "]='" + pname +
                      "' isImplicit() unexpected");
                break;
            }

            if (!allowSynthetic && p.isSynthetic()) {
                error(prefix + "param[" + i + "]='" + pname +
                      "' isSynthetic() unexpected");
                break;
            }

            
            if (expect != null) {
                if (pname.matches(expect))  continue;
                error(prefix + "param[" + i + "]='" + pname +
                      "' expected '" + expect + "'");
                break;
            }

            
            boolean fidelity = !isAnon;
            if (param != null && fidelity) {
                char ch = param.charAt(0);
                expect =  (++ch) + param;
            }
            if (isFinal && expect != null) {
                expect = "final " + expect;
            }
            if (pname != null && fidelity) {
                if (isFinal) {
                    param = pname.substring(6);
                } else {
                param = pname;
            }
            }
            if (expect != null && !expect.equals(pname)) {
                error(prefix + "param[" + i + "]='" + pname +
                      "' expected '" + expect + "'");
                break;
            }
        }
        if  (c.isSynthetic()) {
            sb.append(")/*synthetic*/\n");
        } else {
            sb.append(")\n");
        }
    }

    void testMethod(Method m) {

        String prefix = clazz.getName() + "." + m.getName() + "() - ";

        
        int paramTypes =  m.getParameterTypes().length;
        int params = m.getParameters().length;
        if (paramTypes != params) {
            error(prefix + "number of parameter types (" + paramTypes
                  + ") != number of parameters (" + params + ")");
            return;
        }

        sb.append(clazz.getName()).append(".").append(m.getName()).append("(");
        String sep = "";
        String param = null;
        int i = -1;
        
        
        for (Parameter p : m.getParameters()) {
            i++;
            isFinal = false;
            int pmodifier = p.getModifiers();
            if (param == null) {
                param = p.getName();
                if (Modifier.isFinal(pmodifier)) {
                    isFinal = true;
                    param = "final " + param;
                }
                sb.append(sep).append(param);
            } else  {
                char c = param.charAt(0);
                String expect =  m.isSynthetic() ? ("arg" + i) : ((++c) + param);
                param = p.getName();
                if (Modifier.isFinal(pmodifier)) {
                    isFinal = true;
                    expect = "final " + expect;
                    param = "final " + param;
                }
                sb.append(sep).append(param);
                if (!m.isBridge() && !m.getName().startsWith("lambda$") && !expect.equals(param)) {
                    error(prefix + "param[" + i + "]='"
                          + param + "' expected '" + expect + "'");
                    break;
                }
            }
            if(isFinal)
                param = param.substring(6);
            if (p.isImplicit()) {
                sb.append("/*implicit*/");
            }
            if (p.isSynthetic()) {
                sb.append("/*synthetic*/");
            }
            sep = ", ";
        }
        if  (m.isSynthetic()) {
            sb.append(")/*synthetic*/\n");
        } else {
            sb.append(")\n");
        }
    }
}
