

import com.sun.tools.javac.code.BoundKind;
import com.sun.tools.javac.code.Flags;
import com.sun.tools.javac.util.Context;
import com.sun.tools.javac.code.Types;
import com.sun.tools.javac.code.Symtab;
import com.sun.tools.javac.code.Type;
import com.sun.tools.javac.code.Type.*;
import com.sun.tools.javac.code.Symbol.*;
import com.sun.tools.javac.comp.Check;
import com.sun.tools.javac.util.List;
import com.sun.tools.javac.util.ListBuffer;
import com.sun.tools.javac.util.Name;
import com.sun.tools.javac.util.Names;
import com.sun.tools.javac.file.JavacFileManager;


public class TypeHarness {

    protected Types types;
    protected Check chk;
    protected Symtab predef;
    protected Names names;
    protected Factory fac;

    protected TypeHarness() {
        Context ctx = new Context();
        JavacFileManager.preRegister(ctx);
        types = Types.instance(ctx);
        chk = Check.instance(ctx);
        predef = Symtab.instance(ctx);
        names = Names.instance(ctx);
        fac = new Factory();
    }

    

    
    public void assertSubtype(Type s, Type t) {
        assertSubtype(s, t, true);
    }

    
    public void assertSubtype(Type s, Type t, boolean expected) {
        if (types.isSubtype(s, t) != expected) {
            String msg = expected ?
                " is not a subtype of " :
                " is a subtype of ";
            error(s + msg + t);
        }
    }

    
    public void assertSameType(Type s, Type t) {
        assertSameType(s, t, true);
    }

    
    public void assertSameType(Type s, Type t, boolean expected) {
        if (types.isSameType(s, t) != expected) {
            String msg = expected ?
                " is not the same type as " :
                " is the same type as ";
            error(s + msg + t);
        }
    }

    
    public void assertCastable(Type s, Type t) {
        assertCastable(s, t, true);
    }

    
    public void assertCastable(Type s, Type t, boolean expected) {
        if (types.isCastable(s, t) != expected) {
            String msg = expected ?
                " is not castable to " :
                " is castable to ";
            error(s + msg + t);
        }
    }

    
    public void assertConvertible(Type s, Type t) {
        assertCastable(s, t, true);
    }

    
    public void assertConvertible(Type s, Type t, boolean expected) {
        if (types.isConvertible(s, t) != expected) {
            String msg = expected ?
                " is not convertible to " :
                " is convertible to ";
            error(s + msg + t);
        }
    }

    
    public void assertAssignable(Type s, Type t) {
        assertCastable(s, t, true);
    }

    
    public void assertAssignable(Type s, Type t, boolean expected) {
        if (types.isAssignable(s, t) != expected) {
            String msg = expected ?
                " is not assignable to " :
                " is assignable to ";
            error(s + msg + t);
        }
    }

    
    public void assertValidGenericType(Type t) {
        assertValidGenericType(t, true);
    }

    
    public void assertValidGenericType(Type t, boolean expected) {
        if (chk.checkValidGenericType(t) != expected) {
            String msg = expected ?
                " is not a valid generic type" :
                " is a valid generic type";
            error(t + msg + "   " + t.tsym.type);
        }
    }
    

    private void error(String msg) {
        throw new AssertionError("Unexpected result: " + msg);
    }

    

    
    public Type erasure(Type t) {
        return types.erasure(t);
    }

    
    public Type capture(Type t) {
        return types.capture(t);
    }

    
    public Type box(Type t) {
        if (!t.isPrimitive()) {
            throw new AssertionError("Cannot box non-primitive type: " + t);
        }
        return types.boxedClass(t).type;
    }

    
    public Type unbox(Type t) {
        Type u = types.unboxedType(t);
        if (t == null) {
            throw new AssertionError("Cannot unbox reference type: " + t);
        } else {
            return u;
        }
    }

    
    public Type subst(Type t, Mapping... maps) {
        ListBuffer<Type> from = new ListBuffer<>();
        ListBuffer<Type> to = new ListBuffer<>();
        for (Mapping tm : maps) {
            from.append(tm.from);
            to.append(tm.to);
        }
        return types.subst(t, from.toList(), to.toList());
    }

    
    public Mapping Mapping(Type from, Type to) {
        return new Mapping(from, to);
    }

    public static class Mapping {
        Type from;
        Type to;
        private Mapping(Type from, Type to) {
            this.from = from;
            this.to = to;
        }
    }
    

    

    
    public class Factory {

        private int synthNameCount = 0;

        private Name syntheticName() {
            return names.fromString("A$" + synthNameCount++);
        }

        public ClassType Class(long flags, Type... typeArgs) {
            ClassSymbol csym = new ClassSymbol(flags, syntheticName(), predef.noSymbol);
            csym.type = new ClassType(Type.noType, List.from(typeArgs), csym);
            ((ClassType)csym.type).supertype_field = predef.objectType;
            return (ClassType)csym.type;
        }

        public ClassType Class(Type... typeArgs) {
            return Class(0, typeArgs);
        }

        public ClassType Interface(Type... typeArgs) {
            return Class(Flags.INTERFACE, typeArgs);
        }

        public ClassType Interface(long flags, Type... typeArgs) {
            return Class(Flags.INTERFACE | flags, typeArgs);
        }

        public Type Constant(byte b) {
            return predef.byteType.constType(b);
        }

        public Type Constant(short s) {
            return predef.shortType.constType(s);
        }

        public Type Constant(int i) {
            return predef.intType.constType(i);
        }

        public Type Constant(long l) {
            return predef.longType.constType(l);
        }

        public Type Constant(float f) {
            return predef.floatType.constType(f);
        }

        public Type Constant(double d) {
            return predef.doubleType.constType(d);
        }

        public Type Constant(char c) {
            return predef.charType.constType(c + 0);
        }

        public ArrayType Array(Type elemType) {
            return new ArrayType(elemType, predef.arrayClass);
        }

        public TypeVar TypeVariable() {
            return TypeVariable(predef.objectType);
        }

        public TypeVar TypeVariable(Type bound) {
            TypeSymbol tvsym = new TypeVariableSymbol(0, syntheticName(), null, predef.noSymbol);
            tvsym.type = new TypeVar(tvsym, bound, null);
            return (TypeVar)tvsym.type;
        }

        public WildcardType Wildcard(BoundKind bk, Type bound) {
            return new WildcardType(bound, bk, predef.boundClass);
        }

        public CapturedType CapturedVariable(Type upper, Type lower) {
            return new CapturedType(syntheticName(), predef.noSymbol, upper, lower, null);
        }

        public ClassType Intersection(Type classBound, Type... intfBounds) {
            ClassType ct = Class(Flags.COMPOUND);
            ct.supertype_field = classBound;
            ct.interfaces_field = List.from(intfBounds);
            return ct;
        }
    }
    
}
