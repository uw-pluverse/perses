



import com.sun.tools.javac.code.Type;
import com.sun.tools.javac.code.Type.*;
import com.sun.tools.javac.code.Symbol.*;
import java.lang.reflect.Array;

import static com.sun.tools.javac.code.Flags.*;


public class CastTest extends TypeHarness {

    Type[] types_no_boxing;
    Type[] types_boxing;

    static final boolean T = true;
    static final boolean F = false;

    boolean[][] cast_result_no_boxing = {
                
        { T   , T    , T  , T   , T    , T     , T   , F   , F, F , F, F, F     , F      , F    , F     , F      , F       , F     , F     , F  , F   , F  , F },
       { T   , T    , T  , T   , T    , T     , T   , F   , F, F , F, F, F     , F      , F    , F     , F      , F       , F     , F     , F  , F   , F  , F },
         { T   , T    , T  , T   , T    , T     , T   , F   , F, F , F, F, F     , F      , F    , F     , F      , F       , F     , F     , F  , F   , F  , F },
        { T   , T    , T  , T   , T    , T     , T   , F   , F, F , F, F, F     , F      , F    , F     , F      , F       , F     , F     , F  , F   , F  , F },
       { T   , T    , T  , T   , T    , T     , T   , F   , F, F , F, F, F     , F      , F    , F     , F      , F       , F     , F     , F  , F   , F  , F },
      { T   , T    , T  , T   , T    , T     , T   , F   , F, F , F, F, F     , F      , F    , F     , F      , F       , F     , F     , F  , F   , F  , F },
        { T   , T    , T  , T   , T    , T     , T   , F   , F, F , F, F, F     , F      , F    , F     , F      , F       , F     , F     , F  , F   , F  , F },
        { F   , F    , F  , F   , F    , F     , F   , T   , F, F , F, F, F     , F      , F    , F     , F      , F       , F     , F     , F  , F   , F  , F },
           { F   , F    , F  , F   , F    , F     , F   , F   , T, F , T, T, F     , F      , F    , F     , F      , F       , F     , F     , F  , F   , F  , F },
          { F   , F    , F  , F   , F    , F     , F   , F   , F, T , F, T, F     , F      , F    , F     , F      , F       , F     , F     , F  , F   , F  , F },
           { F   , F    , F  , F   , F    , F     , F   , F   , T, F , T, T, F     , F      , F    , F     , F      , F       , F     , F     , F  , F   , F  , F },
           { F   , F    , F  , F   , F    , F     , F   , F   , T, T , T, T, T     , T      , T    , T     , T      , T       , T     , T     , T  , T   , T  , T },
      { F   , F    , F  , F   , F    , F     , F   , F   , F, F , F, T, T     , F      , F    , F     , F      , F       , F     , F     , F  , F   , F  , F },
     { F   , F    , F  , F   , F    , F     , F   , F   , F, F , F, T, F     , T      , F    , F     , F      , F       , F     , F     , F  , F   , F  , F },
       { F   , F    , F  , F   , F    , F     , F   , F   , F, F , F, T, F     , F      , T    , F     , F      , F       , F     , F     , F  , F   , F  , F },
      { F   , F    , F  , F   , F    , F     , F   , F   , F, F , F, T, F     , F      , F    , T     , F      , F       , F     , F     , F  , F   , F  , F },
     { F   , F    , F  , F   , F    , F     , F   , F   , F, F , F, T, F     , F      , F    , F     , T      , F       , F     , F     , F  , F   , F  , F },
    { F   , F    , F  , F   , F    , F     , F   , F   , F, F , F, T, F     , F      , F    , F     , F      , T       , F     , F     , F  , F   , F  , F },
      { F   , F    , F  , F   , F    , F     , F   , F   , F, F , F, T, F     , F      , F    , F     , F      , F       , T     , F     , F  , F   , F  , F },
      { F   , F    , F  , F   , F    , F     , F   , F   , F, F , F, T, F     , F      , F    , F     , F      , F       , F     , T     , F  , F   , F  , F },
         { F   , F    , F  , F   , F    , F     , F   , F   , F, F , F, T, F     , F      , F    , F     , F      , F       , F     , F     , T  , F   , T  , T },
        { F   , F    , F  , F   , F    , F     , F   , F   , F, F , F, T, F     , F      , F    , F     , F      , F       , F     , F     , F  , T   , F  , T },
         { F   , F    , F  , F   , F    , F     , F   , F   , F, F , F, T, F     , F      , F    , F     , F      , F       , F     , F     , T  , F   , T  , T },
         { F   , F    , F  , F   , F    , F     , F   , F   , F, F , F, T, F     , F      , F    , F     , F      , F       , F     , F     , T  , T   , T  , T }};

    boolean[][] cast_result_boxing = {
                   
           { T   , T    , T  , T   , T    , T     , T   , F   , T   , F    , F      , F   , F    , F     , F        , F ,      T },
          { T   , T    , T  , T   , T    , T     , T   , F   , F   , T    , F      , F   , F    , F     , F        , F ,      T  },
            { T   , T    , T  , T   , T    , T     , T   , F   , F   , F    , T      , F   , F    , F     , F        , F ,      T  },
           { T   , T    , T  , T   , T    , T     , T   , F   , F   , F    , F      , T   , F    , F     , F        , F ,      T  },
          { T   , T    , T  , T   , T    , T     , T   , F   , F   , F    , F      , F   , T    , F     , F        , F ,      T  },
         { T   , T    , T  , T   , T    , T     , T   , F   , F   , F    , F      , F   , F    , T     , F        , F ,      T  },
           { T   , T    , T  , T   , T    , T     , T   , F   , F   , F    , F      , F   , F    , F     , T        , F ,      T  },
           { F   , F    , F  , F   , F    , F     , F   , T   , F   , F    , F      , F   , F    , F     , F        , T ,      T  },
           { T   , T    , T  , T   , T    , T     , F   , F   , T   , F    , F      , F   , F    , F     , F        , F ,      T  },
          { F   , T    , T  , T   , T    , T     , F   , F   , F   , T    , F      , F   , F    , F     , F        , F ,      T  },
        { F   , F    , T  , T   , T    , T     , F   , F   , F   , F    , T      , F   , F    , F     , F        , F ,      T  },
           { F   , F    , F  , T   , T    , T     , F   , F   , F   , F    , F      , T   , F    , F     , F        , F ,      T  },
          { F   , F    , F  , F   , T    , T     , F   , F   , F   , F    , F      , F   , T    , F     , F        , F ,      T  },
         { F   , F    , F  , F   , F    , T     , F   , F   , F   , F    , F      , F   , F    , T     , F        , F ,      T  },
      { F   , F    , T  , T   , T    , T     , T   , F   , F   , F    , F      , F   , F    , F     , T        , F ,      T  },
        { F   , F    , F  , F   , F    , F     , F   , T   , F   , F    , F      , F   , F    , F     , F        , T ,      T  },
         { T   , T    , T  , T   , T    , T     , T   , T   , T   , T    , T      , T   , T    , T     , T        , T ,      T  }};
    CastTest() {
        Type[] primitiveTypes = {
            predef.byteType,
            predef.shortType,
            predef.intType,
            predef.longType,
            predef.floatType,
            predef.doubleType,
            predef.charType,
            predef.booleanType };

        Type[] boxedTypes = new Type[primitiveTypes.length + 1];
        for (int i = 0 ; i < primitiveTypes.length ; i++) {
            boxedTypes[i] = box(primitiveTypes[i]);
        }

        boxedTypes[primitiveTypes.length] = predef.objectType;

        types_boxing = join(Type.class, primitiveTypes, boxedTypes);

        Type[] referenceTypes = {
            fac.Class(),
            fac.Class(FINAL),
            fac.Interface(),
            fac.TypeVariable() };

        Type[] arrayTypes = new Type[primitiveTypes.length + referenceTypes.length];
        int idx = 0;
        for (Type t : join(Type.class, primitiveTypes, referenceTypes)) {
            arrayTypes[idx++] = fac.Array(t);
        }

        types_no_boxing = join(Type.class, primitiveTypes, referenceTypes, arrayTypes);
    }

    void test(Type[] all_types, boolean[][] cast_result) {
        for (int i = 0; i < all_types.length ; i++) {
            for (int j = 0; j < all_types.length ; j++) {
                assertCastable(all_types[i], all_types[j], cast_result[i][j]);
            }
        }
    }

    void runTests() {
        test(types_no_boxing, cast_result_no_boxing);
        test(types_boxing, cast_result_boxing);
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
        new CastTest().runTests();
    }
}
