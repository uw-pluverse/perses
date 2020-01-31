



import java.util.*;
import com.sun.source.tree.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;


public class CheckMethod extends Checker {
    public static void main(String... args) throws Exception {
        Checker chk = new CheckMethod();
        chk.check("TestMethod.java");
    }

    @Override
    protected boolean checkLocal(Scope s, String ref) {
        
        ExecutableElement ee = s.getEnclosingMethod();
        boolean ok;
        if (ee == null)
            ok = ref.equals("0");
        else {
            CharSequence name = ee.getSimpleName();
            ok = ref.equals(name == null || name.length() == 0 ? "-" : name.toString());
        }
        if (!ok)
            error(s, ref, "bad enclosing method found: " + ee);
        return ok;
    }
}
