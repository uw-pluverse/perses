package daikon.chicory;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import org.checkerframework.checker.nullness.qual.Nullable;

public class PureMethodInfo extends DaikonVariableInfo {

    @Nullable
    private static Object executePureMethod(Method meth, Object receiverVal, @Nullable Object[] argVals) {
        synchronized (Runtime.class) {
            Object retVal;
            try {
                Runtime.startPure();
                @SuppressWarnings("nullness")
                Object tmp_retVal = meth.invoke(receiverVal, argVals);
                retVal = tmp_retVal;
                if (meth.getReturnType().isPrimitive()) {
                    retVal = convertWrapper(retVal);
                }
            } catch (IllegalArgumentException e) {
                throw new Error(e);
            } catch (IllegalAccessException e) {
                throw new Error(e);
            } catch (InvocationTargetException e) {
                retVal = NonsensicalObject.getInstance();
            } catch (Throwable e) {
                throw new Error(e);
            } finally {
                Runtime.endPure();
            }
            return retVal;
        }
    }

    public static Object convertWrapper(Object obj) {
        throw new java.lang.Error();
    }
}
