



import java.util.*;
import com.sun.source.tree.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;


public class CheckClass extends Checker {
    public static void main(String... args) throws Exception {
        Checker chk = new CheckClass();
        chk.check("TestClass.java");
    }

    @Override
    protected boolean checkLocal(Scope s, String ref) {
        
        TypeElement te = s.getEnclosingClass();
        boolean ok;
        if (te == null)
            ok = ref.equals("0");
        else {
            CharSequence name = te.getQualifiedName();
            ok = ref.equals(name == null || name.length() == 0 ? "-" : name.toString());
        }
        if (!ok)
            error(s, ref, "bad enclosing class found: " + te);
        return ok;
    }
}
