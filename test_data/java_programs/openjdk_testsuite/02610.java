



import java.util.*;
import com.sun.source.tree.*;
import javax.lang.model.element.*;
import javax.lang.model.util.*;


public class CheckLocalElements extends Checker {
    public static void main(String... args) throws Exception {
        Checker chk = new CheckLocalElements();
        chk.check("TestLocalElements.java");
    }

    @Override
    protected boolean checkLocal(Scope s, String ref) {
        Iterator<? extends Element> elemIter = s.getLocalElements().iterator();
        ref = ref.trim();
        String[] refs = ref.length() == 0 ? new String[0] : ref.split("[ ]*,[ ]*", -1);
        Iterator<String> refIter = Arrays.asList(refs).iterator();
        String r = null;

        nextElem:
        while (elemIter.hasNext()) {
            Element e = elemIter.next();
            try {
                if (r == null)
                    r = refIter.next();

                while (r.endsWith(".*")) {
                    String encl = getEnclosingName(e);
                    String rBase = r.substring(0, r.length() - 2);
                    if (encl.equals(rBase) || encl.startsWith(rBase + "."))
                        continue nextElem;
                    r = refIter.next();
                }

                if (r.equals("-") && (e.getSimpleName().length() == 0)
                    || e.getSimpleName().toString().equals(r)) {
                    r = null;
                    continue nextElem;
                }

                error(s, ref, "mismatch: " + e.getSimpleName() + " " + r);
                return false;

            } catch (NoSuchElementException ex) { 
                error(s, null, "scope has unexpected entry: " + e.getSimpleName());
                return false;
            }

        }

        if (refIter.hasNext()) {
            error(s, ref, "scope is missing entry: " + refIter.next());
            return false;
        }

        return true;
    }

    private String getEnclosingName(Element e) {
        Element encl = e.getEnclosingElement();
        return encl == null ? "" : encl.accept(qualNameVisitor, null);
    }

    private ElementVisitor<String,Void> qualNameVisitor = new SimpleElementVisitor8<String,Void>() {
        protected String defaultAction(Element e, Void ignore) {
            return "";
        }

        public String visitPackage(PackageElement e, Void ignore) {
            return e.getQualifiedName().toString();
        }

        public String visitType(TypeElement e, Void ignore) {
            return e.getQualifiedName().toString();
        }
    };
}
