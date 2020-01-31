



import com.sun.tools.javac.code.Type;
import com.sun.tools.javac.code.Type.*;
import com.sun.tools.javac.code.Symbol.*;
import java.lang.reflect.Array;
import java.util.EnumSet;


public class PrimitiveConversionTest extends TypeHarness {

    Type[] types1;
    Type[] types2;
    Type[] types3;

    enum Result {
        OK_BOTH(true),
        FAIL_BOTH(false),
        OK_ASSIGN_ONLY(true);

        boolean value;

        Result(boolean value) {
            this.value = value;
        }
    }

    enum ConversionKind {
        ASSIGNMENT_CONVERSION(EnumSet.of(Result.OK_BOTH, Result.OK_ASSIGN_ONLY)) {
            @Override
            void check(TypeHarness harness, Type from, Type to, Result expected) {
                harness.assertAssignable(from, to, resSet.contains(expected));
            }
        },
        METHOD_CONVERSION(EnumSet.of(Result.OK_BOTH)) {
            @Override
            void check(TypeHarness harness, Type from, Type to, Result expected) {
                harness.assertConvertible(from, to, resSet.contains(expected));
            }
        };

        EnumSet<Result> resSet;

        private ConversionKind(EnumSet<Result> resSet) {
            this.resSet = resSet;
        }

        abstract void check(TypeHarness harness, Type from, Type to, Result expected);
    }

    enum TestKind {
        SIMPLE {
            @Override
            Type[] getFromTypes(PrimitiveConversionTest harness) {
                return harness.types1;
            }
            @Override
            Type[] getToTypes(PrimitiveConversionTest harness) {
                return harness.types1;
            }
            @Override
            Result[][] getResults(PrimitiveConversionTest harness) {
                return harness.results1;
            }
        },
        CONSTANT_TYPES {
            @Override
            Type[] getFromTypes(PrimitiveConversionTest harness) {
                return harness.types2;
            }
            @Override
            Type[] getToTypes(PrimitiveConversionTest harness) {
                return harness.types3;
            }
            @Override
            Result[][] getResults(PrimitiveConversionTest harness) {
                return harness.results2;
            }
        };

        abstract Type[] getFromTypes(PrimitiveConversionTest harness);
        abstract Type[] getToTypes(PrimitiveConversionTest harness);
        abstract Result[][] getResults(PrimitiveConversionTest harness);
    }

    static final Result T = Result.OK_BOTH;
    static final Result F = Result.FAIL_BOTH;
    static final Result A = Result.OK_ASSIGN_ONLY;

    Result[][] results1 = {
                
        { T   , T    , T  , T   , T    , T     , F   , F   , F , F , F , F , F     , F      , F    , F     , F      , F       , F     , F     , F   , F   , F   , F },
       { F   , T    , T  , T   , T    , T     , F   , F   , F , F , F , F , F     , F      , F    , F     , F      , F       , F     , F     , F   , F   , F   , F },
         { F   , F    , T  , T   , T    , T     , F   , F   , F , F , F , F , F     , F      , F    , F     , F      , F       , F     , F     , F   , F   , F   , F },
        { F   , F    , F  , T   , T    , T     , F   , F   , F , F , F , F , F     , F      , F    , F     , F      , F       , F     , F     , F   , F   , F   , F },
       { F   , F    , F  , F   , T    , T     , F   , F   , F , F , F , F , F     , F      , F    , F     , F      , F       , F     , F     , F   , F   , F   , F },
      { F   , F    , F  , F   , F    , T     , F   , F   , F , F , F , F , F     , F      , F    , F     , F      , F       , F     , F     , F   , F   , F   , F },
        { F   , F    , T  , T   , T    , T     , T   , F   , F , F , F , F , F     , F      , F    , F     , F      , F       , F     , F     , F   , F   , F   , F },
        { F   , F    , F  , F   , F    , F     , F   , T   , F , F , F , F , F     , F      , F    , F     , F      , F       , F     , F     , F   , F   , F   , F },
          { F   , F    , F  , F   , F    , F     , F   , F   , T , F , T , F , F     , F      , F    , F     , F      , F       , F     , F     , F   , F   , F   , F },
          { F   , F    , F  , F   , F    , F     , F   , F   , T , T , T , F , F     , F      , F    , F     , F      , F       , F     , F     , F   , F   , F   , F },
          { F   , F    , F  , F   , F    , F     , F   , F   , T , F , T , F , F     , F      , F    , F     , F      , F       , F     , F     , F   , F   , F   , F },
           { F   , F    , F  , F   , F    , F     , F   , F   , F , F , F , T , F     , F      , F    , F     , F      , F       , F     , F     , F   , F   , F   , F },
      { F   , F    , F  , F   , F    , F     , F   , F   , F , F , F , F , T     , F      , F    , F     , F      , F       , F     , F     , F   , F   , F   , F },
     { F   , F    , F  , F   , F    , F     , F   , F   , F , F , F , F , F     , T      , F    , F     , F      , F       , F     , F     , F   , F   , F   , F },
       { F   , F    , F  , F   , F    , F     , F   , F   , F , F , F , F , F     , F      , T    , F     , F      , F       , F     , F     , F   , F   , F   , F },
      { F   , F    , F  , F   , F    , F     , F   , F   , F , F , F , F , F     , F      , F    , T     , F      , F       , F     , F     , F   , F   , F   , F },
     { F   , F    , F  , F   , F    , F     , F   , F   , F , F , F , F , F     , F      , F    , F     , T      , F       , F     , F     , F   , F   , F   , F },
    { F   , F    , F  , F   , F    , F     , F   , F   , F , F , F , F , F     , F      , F    , F     , F      , T       , F     , F     , F   , F   , F   , F },
      { F   , F    , F  , F   , F    , F     , F   , F   , F , F , F , F , F     , F      , F    , F     , F      , F       , T     , F     , F   , F   , F   , F },
      { F   , F    , F  , F   , F    , F     , F   , F   , F , F , F , F , F     , F      , F    , F     , F      , F       , F     , T     , F   , F   , F   , F },
        { F   , F    , F  , F   , F    , F     , F   , F   , F , F , F , F , F     , F      , F    , F     , F      , F       , F     , F     , T   , F   , T   , F },
        { F   , F    , F  , F   , F    , F     , F   , F   , F , F , F , F , F     , F      , F    , F     , F      , F       , F     , F     , T   , T   , T   , F },
        { F   , F    , F  , F   , F    , F     , F   , F   , F , F , F , F , F     , F      , F    , F     , F      , F       , F     , F     , T   , F   , T   , F },
         { F   , F    , F  , F   , F    , F     , F   , F   , F , F , F , F , F     , F      , F    , F     , F      , F       , F     , F     , F   , F   , F   , T }};

    Result[][] results2 = {
                
        { T   , T    , T  , T   , T    , T     , F   , F },
       { F   , T    , T  , T   , T    , T     , F   , F },
      { A   , T    , T  , T   , T    , T     , A   , F },
      { F   , T    , T  , T   , T    , T     , A   , F },
         { F   , F    , T  , T   , T    , T     , F   , F },
        { A   , A    , T  , T   , T    , T     , A   , F },
        { F   , A    , T  , T   , T    , T     , A   , F },
        { F   , F    , T  , T   , T    , T     , F   , F },
        { F   , F    , F  , T   , T    , T     , F   , F },
       { F   , F    , F  , T   , T    , T     , F   , F },
       { F   , F    , F  , T   , T    , T     , F   , F },
       { F   , F    , F  , T   , T    , T     , F   , F },
       { F   , F    , F  , T   , T    , T     , F   , F },
       { F   , F    , F  , F   , T    , T     , F   , F },
      { F   , F    , F  , F   , T    , T     , F   , F },
      { F   , F    , F  , F   , T    , T     , F   , F },
      { F   , F    , F  , F   , T    , T     , F   , F },
      { F   , F    , F  , F   , F    , T     , F   , F },
     { F   , F    , F  , F   , F    , T     , F   , F },
     { F   , F    , F  , F   , F    , T     , F   , F },
     { F   , F    , F  , F   , F    , T     , F   , F },
     { F   , F    , F  , F   , F    , T     , F   , F },
        { F   , F    , T  , T   , T    , T     , T   , F },
       { A   , A    , T  , T   , T    , T     , T   , F },
       { F   , A    , T  , T   , T    , T     , T   , F },
        { F   , F    , F  , F   , F    , F     , F   , T }};

    PrimitiveConversionTest() {
        Type[] primitiveTypes = new Type[] {
            predef.byteType,
            predef.shortType,
            predef.intType,
            predef.longType,
            predef.floatType,
            predef.doubleType,
            predef.charType,
            predef.booleanType };

        ClassType c1 = fac.Class(fac.TypeVariable());
        ClassType c2 = fac.Class();
        c2.supertype_field = subst(c1,
                Mapping(c1.getTypeArguments().head, predef.stringType));
        Type c3 = erasure(c1);

        Type[] referenceTypes = {
            subst(c1,
                    Mapping(c1.getTypeArguments().head, predef.stringType)),
            c2,
            c3,
            fac.TypeVariable() };

        Type[] arrayTypes = new Type[primitiveTypes.length + referenceTypes.length];
        int idx = 0;
        for (Type t : join(Type.class, primitiveTypes, referenceTypes)) {
            arrayTypes[idx++] = fac.Array(t);
        }

        types1 = join(Type.class, primitiveTypes, referenceTypes, arrayTypes);

        types2 = new Type[] {
            predef.byteType,
            predef.shortType,
            fac.Constant((short)0x0001),
            fac.Constant((short)0x0100),
            predef.intType,
            fac.Constant((int)0x0000_0001),
            fac.Constant((int)0x0000_0100),
            fac.Constant((int)0x0001_0000),
            predef.longType,
            fac.Constant((long)0x0000_0000_0000_0001L),
            fac.Constant((long)0x0000_0000_0000_0100L),
            fac.Constant((long)0x0000_0000_0001_0000L),
            fac.Constant((long)0x0001_0000_0000_0000L),
            predef.floatType,
            fac.Constant((float)0x0000_0001),
            fac.Constant((float)0x0000_0100),
            fac.Constant((float)0x0001_0000),
            predef.doubleType,
            fac.Constant((double)0x0000_0000_0000_0001L),
            fac.Constant((double)0x0000_0000_0000_0100L),
            fac.Constant((double)0x0000_0000_0001_0000L),
            fac.Constant((double)0x0001_0000_0000_0000L),
            predef.charType,
            fac.Constant((char)0x0001),
            fac.Constant((char)0x0100),
            predef.booleanType
        };

        types3 = primitiveTypes;
    }

    void testConversion(ConversionKind convKind, TestKind testKind) {
        Type[] rows = testKind.getFromTypes(this);
        Type[] cols = testKind.getToTypes(this);
        for (int i = 0; i < rows.length ; i++) {
            for (int j = 0; j < cols.length ; j++) {
                convKind.check(this, rows[i], cols[j], testKind.getResults(this)[i][j]);
            }
        }
    }

    @SuppressWarnings("unchecked")
    <T> T[] join(Class<T> type, T[]... args) {
        int totalLength = 0;
        for (T[] arr : args) {
            totalLength += arr.length;
        }
        T[] new_arr = (T[])Array.newInstance(type, totalLength);
        int idx = 0;
        for (T[] arr : args) {
            System.arraycopy(arr, 0, new_arr, idx, arr.length);
            idx += arr.length;
        }
        return new_arr;
    }

    public static void main(String[] args) {
        PrimitiveConversionTest harness = new PrimitiveConversionTest();
        for (ConversionKind convKind : ConversionKind.values()) {
            for (TestKind testKind : TestKind.values()) {
                harness.testConversion(convKind, testKind);
            }
        }
    }
}
