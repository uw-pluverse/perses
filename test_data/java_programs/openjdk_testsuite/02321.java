

import java.io.*;
import com.sun.tools.classfile.*;


class ClassFileVisitor extends Tester.Visitor {

    Tester tester;

    public String cname;
    public boolean isEnum;
    public boolean isInterface;
    public boolean isInner;
    public boolean isPublic;
    public boolean isStatic;
    public boolean isAnon;
    public ClassFile classFile;


    public ClassFileVisitor(Tester tester) {
        super(tester);
    }

    public void error(String msg) {
        super.error("classfile: " + msg);
    }

    public void warn(String msg) {
        super.warn("classfile: " + msg);
    }

    
    void visitClass(final String cname, final File cfile, final StringBuilder sb) throws Exception {
        this.cname = cname;
        classFile = ClassFile.read(cfile);
        isEnum = classFile.access_flags.is(AccessFlags.ACC_ENUM);
        isInterface = classFile.access_flags.is(AccessFlags.ACC_INTERFACE);
        isPublic = classFile.access_flags.is(AccessFlags.ACC_PUBLIC);
        isInner = false;
        isStatic = false;
        isAnon = false;

        Attribute attr = classFile.getAttribute("InnerClasses");
        if (attr != null) attr.accept(new InnerClassVisitor(), null);
        isAnon = isInner & isAnon;

        sb.append(isStatic ? "static " : "")
            .append(isPublic ? "public " : "")
            .append(isEnum ? "enum " : isInterface ? "interface " : "class ")
            .append(cname).append(" -- ");
        if (isInner) {
            sb.append(isAnon ? "anon" : "inner");
        }
        sb.append("\n");

        for (Method method : classFile.methods) {
            new MethodVisitor().visitMethod(method, sb);
        }
    }

    
    class InnerClassVisitor extends AttributeVisitor<Void, Void> {
        public Void visitInnerClasses(InnerClasses_attribute iattr, Void v) {
            try{
                for (InnerClasses_attribute.Info info : iattr.classes) {
                    if (info.getInnerClassInfo(classFile.constant_pool) == null) continue;
                    String in = info.getInnerClassInfo(classFile.constant_pool).getName();
                    if (in == null || !cname.equals(in)) continue;
                    isInner = true;
                    isAnon = null == info.getInnerName(classFile.constant_pool);
                    isStatic = info.inner_class_access_flags.is(AccessFlags.ACC_STATIC);
                    break;
                }
            } catch(Exception e) {
                throw new IllegalStateException(e);
            }
            return null;
        }
    }

    
    class MethodVisitor extends AttributeVisitor<Void, StringBuilder> {

        public String mName;
        public Descriptor mDesc;
        public int mParams;
        public int mAttrs;
        public int mNumParams;
        public boolean mSynthetic;
        public boolean mIsLambda;
        public boolean mIsConstructor;
        public boolean mIsClinit;
        public boolean mIsBridge;
        public boolean isFinal;
        public String prefix;

        void visitMethod(Method method, StringBuilder sb) throws Exception {

            mName = method.getName(classFile.constant_pool);
            mDesc = method.descriptor;
            mParams =  mDesc.getParameterCount(classFile.constant_pool);
            mAttrs = method.attributes.attrs.length;
            mNumParams = -1; 
            mSynthetic = method.access_flags.is(AccessFlags.ACC_SYNTHETIC);
            mIsConstructor = mName.equals("<init>");
            mIsClinit = mName.equals("<clinit>");
            prefix = cname + "." + mName + "() - ";
            mIsBridge = method.access_flags.is(AccessFlags.ACC_BRIDGE);
            mIsLambda = mSynthetic && mName.startsWith("lambda$");

            if (mIsClinit) {
                sb = new StringBuilder(); 
            }
            sb.append(cname).append(".").append(mName).append("(");

            for (Attribute a : method.attributes) {
                a.accept(this, sb);
            }
            if (mNumParams == -1) {
                if (mSynthetic) {
                    
                    
                    
                    for (int i = 0; i < mParams; i++) {
                        if (i == 0)
                            sb.append("arg").append(i);
                        else
                            sb.append(", arg").append(i);
                    }
                    sb.append(")/*synthetic*/");
                } else {
                    sb.append(")");
                }
            }
            sb.append("\n");

            
            
            if (mNumParams == -1 && mParams > 0 && ! mSynthetic) {
                error(prefix + "missing MethodParameters attribute");
            }
        }

        public Void visitMethodParameters(MethodParameters_attribute mp,
                                          StringBuilder sb) {

            
            if (mNumParams != -1) {
                error(prefix + "Multiple MethodParameters attributes");
                return null;
            }

            mNumParams = mp.method_parameter_table_length;

            
            if (mNumParams == 0) {
                error(prefix + "0 length MethodParameters attribute");
                return null;
            }

            
            if (mNumParams != mParams) {
                error(prefix + "found " + mNumParams +
                      " parameters, expected " + mParams);
                return null;
            }

            
            
            if (mSynthetic && !mIsLambda) {
                warn(prefix + "synthetic has MethodParameter attribute");
            }

            String sep = "";
            String userParam = null;
            for (int x = 0; x <  mNumParams; x++) {
                isFinal = (mp.method_parameter_table[x].flags & AccessFlags.ACC_FINAL) != 0;
                
                int cpi = mp.method_parameter_table[x].name_index;
                if (cpi == 0) {
                    error(prefix + "name expected, param[" + x + "]");
                    return null;
                }

                
                String param = null;
                try {
                    param = classFile.constant_pool.getUTF8Value(cpi);
                    if (isFinal)
                        param = "final " + param;
                    sb.append(sep).append(param);
                    sep = ", ";
                } catch(ConstantPoolException e) {
                    error(prefix + "invalid index " + cpi + " for param["
                          + x + "]");
                    return null;
                }


                
                int check = checkParam(mp, param, x, sb, isFinal);
                if (check < 0) {
                    return null;
                }

                
                
                
                
                String expect = null;
                if (userParam != null) {
                    char c = userParam.charAt(0);
                    expect =  (++c) + userParam;
                }
                if(isFinal && expect != null)
                    expect = "final " + expect;
                if (check > 0) {
                    if(isFinal) {
                        userParam = param.substring(6);
                    } else {
                    userParam = param;
                }
                }
                if (expect != null && !param.equals(expect)) {
                    error(prefix + "param[" + x + "]='"
                          + param + "' expected '" + expect + "'");
                    return null;
                }
            }
            if (mSynthetic) {
                sb.append(")/*synthetic*/");
            } else {
                sb.append(")");
            }
            return null;
        }

        
        int checkParam(MethodParameters_attribute mp, String param, int index,
                       StringBuilder sb, boolean isFinal) {

            boolean synthetic = (mp.method_parameter_table[index].flags
                                 & AccessFlags.ACC_SYNTHETIC) != 0;
            boolean mandated = (mp.method_parameter_table[index].flags
                                & AccessFlags.ACC_MANDATED) != 0;

            
            String expect = null;
            boolean allowMandated = false;
            boolean allowSynthetic = false;
            if (mSynthetic || synthetic) {
                
                expect = "arg" + index; 
            }
            if (mIsConstructor) {
                if (isEnum) {
                    if (index == 0) {
                        expect = "\\$enum\\$name";
                        allowSynthetic = true;
                    } else if(index == 1) {
                        expect = "\\$enum\\$ordinal";
                        allowSynthetic = true;
                    }
                } else if (index == 0) {
                    if (isAnon) {
                        expect = "this\\$[0-9]+";
                        allowMandated = true;
                        if (isFinal) {
                            expect = "final this\\$[0-9]+";
                        }
                    } else if (isInner && !isStatic) {
                        expect = "this\\$[0-9]+";
                        allowMandated = true;
                        if (!isPublic) {
                            
                            
                            
                            allowSynthetic = true;
                        }
                        if (isFinal) {
                            expect = "final this\\$[0-9]+";
                        }
                    }
                }
            } else if (isEnum && mNumParams == 1 && index == 0 && mName.equals("valueOf")) {
                expect = "name";
                allowMandated = true;
            } else if (mIsBridge || mIsLambda) {
                allowSynthetic = true;
                
                expect = null;
            }
            if (mandated) sb.append("/*implicit*/");
            if (synthetic) sb.append("/*synthetic*/");

            
            
            if (mandated && synthetic) {
                error(prefix + "param[" + index + "] == \"" + param
                      + "\" ACC_SYNTHETIC and ACC_MANDATED");
                return -1;
            }
            
            if (!(mandated || synthetic) && allowMandated && allowSynthetic) {
                error(prefix + "param[" + index + "] == \"" + param
                      + "\" expected ACC_MANDATED or ACC_SYNTHETIC");
                return -1;
            }

            
            if (!mandated && allowMandated && !allowSynthetic) {
                error(prefix + "param[" + index + "] == \"" + param
                      + "\" expected ACC_MANDATED");
                return -1;
            }
            if (!synthetic && !allowMandated && allowSynthetic) {
                error(prefix + "param[" + index + "] == \"" + param
                      + "\" expected ACC_SYNTHETIC");
                return -1;
            }

            
            if (mandated && !allowMandated) {
                error(prefix + "param[" + index + "] == \"" + param
                      + "\" unexpected, is ACC_MANDATED");
                return -1;
            }
            if (synthetic && !allowSynthetic) {
                error(prefix + "param[" + index + "] == \"" + param
                      + "\" unexpected, is ACC_SYNTHETIC");
                return -1;
            }

            
            if (expect != null) {
                if (param.matches(expect)) {
                    return 0;
                }
                error(prefix + "param[" + index + "]='" + param +
                      "' expected '" + expect + "'");
                return -1;
            }

            
            if (mSynthetic) {
                return 0;
            }

            
            return 1;
        }
    }
}
