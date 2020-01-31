



import com.sun.tools.javac.code.Scope;
import com.sun.tools.javac.code.Symbol;
import com.sun.tools.javac.code.Symtab;
import com.sun.tools.javac.code.Types;
import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.util.Context;
import com.sun.tools.javac.util.Names;
import java.lang.reflect.Field;
import java.util.Collection;

public class ScopeListenerTest {

    public static void main(String[] args) throws Exception {
        new ScopeListenerTest().run();
    }

    void run() throws Exception {
        Context context = new Context();
        JavacFileManager.preRegister(context);
        Types types = Types.instance(context);
        Symtab syms = Symtab.instance(context);
        Names names = Names.instance(context);
        types.membersClosure(syms.stringType, true);
        types.membersClosure(syms.stringType, false);

        Field listenersField = Scope.class.getDeclaredField("listeners");

        listenersField.setAccessible(true);

        int listenerCount =
                ((Collection) listenersField.get(syms.stringType.tsym.members())).size();

        for (int i = 0; i < 100; i++) {
            types.membersClosure(syms.stringType, true);
            types.membersClosure(syms.stringType, false);
        }

        int newListenerCount
                = ((Collection) listenersField.get(syms.stringType.tsym.members())).size();

        if (listenerCount != newListenerCount) {
            throw new AssertionError("Orig listener count: " + listenerCount +
                                     "; new listener count: " + newListenerCount);
        }

        for (Symbol s : types.membersClosure(syms.stringType, true).getElements())
            ;
        for (Symbol s : types.membersClosure(syms.stringType, false).getElementsByName(names.fromString("substring")))
            ;
    }

}
