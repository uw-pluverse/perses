



import java.util.*;
import com.sun.source.tree.*;
import com.sun.source.util.*;
import javax.lang.model.element.*;
import javax.lang.model.type.*;
import javax.lang.model.util.*;


public class CheckIsAccessible extends Checker {
    public static void main(String... args) throws Exception {
        Checker chk = new CheckIsAccessible();
        chk.check("TestIsAccessible.java", "A.java");
    }

    @Override
    protected boolean check(Scope s, String ref) {
        System.err.println("checkIsAccessible: " + s + " " + s.getEnclosingClass() + " " + ref);
        if (ref.length() == 0)
            return true;

        Trees trees = getTrees();
        String[] args = ref.split(" +", 3);
        boolean expect = args[args.length - 1].equals("yes");
        boolean actual;
        switch (args.length) {
        case 2:
            TypeElement te = getTypeElement(args[0]);
            actual = trees.isAccessible(s, te);
            if (actual != expect)
                error(s, ref, "accessible issue found: " + te + " " + actual);
            break;

        case 3:
            DeclaredType site = getType(args[0]);
            Element member = getMember(args[1]);
            actual = trees.isAccessible(s, member, site);
            if (actual != expect)
                error(s, ref, "accessible issue found: " + member + "@" + site + " " + actual);
            break;

        default:
            throw new IllegalArgumentException(ref);
        }

        return (actual == expect);
    }

    private TypeElement getTypeElement(String name) {
        TypeElement te = getElements().getTypeElement(name);
        if (te == null)
            throw new IllegalArgumentException("can't find element " + name);
        return te;
    }

    private DeclaredType getType(String name) {
        return (DeclaredType)(getTypeElement(name).asType());
    }

    private Element getMember(String name) {
        int sep = name.indexOf("#");
        String tname = name.substring(0, sep);
        String mname = name.substring(sep+1);
        TypeElement te = getTypeElement(tname);
        for (Element e: te.getEnclosedElements()) {
            if (mname.contentEquals(e.getSimpleName()))
                return e;
        }
        throw new IllegalArgumentException("can't find member " + mname + " in " + tname);
    }

}
