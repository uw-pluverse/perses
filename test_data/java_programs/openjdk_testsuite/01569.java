

package org.openjdk.tests.shapegen;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;


public class ClassCase {

    public enum Kind {
        IVAC        (true,  "v"),
        IPRESENT    (true,  "p"),
        IDEFAULT    (true,  "d"),
        CNONE       (false, "n"),
        CABSTRACT   (false, "a"),
        CCONCRETE   (false, "c");

        private final String prefix;
        public final boolean isInterface;

        Kind(boolean isInterface, String prefix) {
            this.isInterface = isInterface;
            this.prefix = prefix;
        }

        public String getPrefix() { return prefix; }
    }

    public final Kind kind;
    private final ClassCase superclass;
    private final List<ClassCase> supertypes;

    private String name;
    private boolean _OK;
    private boolean _HasClassMethod;
    private Set<ClassCase> _mprov;
    private boolean _IsConcrete;
    private boolean _HasDefault;
    private ClassCase _mres;
    private ClassCase _mdefend;

    private Set<RuleGroup> executed = new HashSet<RuleGroup>();

    public ClassCase(Kind kind, ClassCase superclass, List<ClassCase> interfaces) {
        this.kind = kind;
        this.superclass = superclass;

        
        List<ClassCase> lc;
        if (superclass == null) {
            lc = interfaces;
        } else {
            lc = new ArrayList<>();
            lc.add(superclass);
            lc.addAll(interfaces);
        }
        this.supertypes = lc;
    }

    public final boolean isInterface() { return kind.isInterface; }
    public final boolean isClass() { return !kind.isInterface; }

    public Set<ClassCase> get_mprov() {
        exec(RuleGroup.PROVENENCE);
        return _mprov;
    }

    public void set_mprov(ClassCase cc) {
        Set<ClassCase> s = new HashSet<>();
        s.add(cc);
        _mprov = s;
    }

    public void set_mprov(Set<ClassCase> s) {
        _mprov = s;
    }

    public ClassCase get_mres() {
        exec(RuleGroup.RESOLUTION);
        return _mres;
    }

    public void set_mres(ClassCase cc) {
        _mres = cc;
    }

    public ClassCase get_mdefend() {
        exec(RuleGroup.DEFENDER);
        return _mdefend;
    }

    public void set_mdefend(ClassCase cc) {
        _mdefend = cc;
    }

    public boolean get_HasClassMethod() {
        exec(RuleGroup.PROVENENCE);
        return _HasClassMethod;
    }

    public void set_HasClassMethod(boolean bool) {
        _HasClassMethod = bool;
    }

    public boolean get_HasDefault() {
        exec(RuleGroup.MARKER);
        return _HasDefault;
    }

    public void set_HasDefault(boolean bool) {
        _HasDefault = bool;
    }

    public boolean get_IsConcrete() {
        exec(RuleGroup.MARKER);
        return _IsConcrete;
    }

    public void set_IsConcrete(boolean bool) {
        _IsConcrete = bool;
    }

    public boolean get_OK() {
        exec(RuleGroup.CHECKING);
        return _OK;
    }

    public void set_OK(boolean bool) {
        _OK = bool;
    }

    public boolean isMethodDefined() {
        for (ClassCase cc : supertypes) {
            if (cc.isMethodDefined()) {
                return true;
            }
        }
        switch (kind) {
            case CCONCRETE:
            case CABSTRACT:
            case IPRESENT:
            case IDEFAULT:
                return true;
            default:
                return false;
        }
    }

    public boolean isAbstract() {
        return isMethodDefined() && (get_mres()==null);
    }

    public boolean hasSuperclass() {
        return superclass != null;
    }

    public ClassCase getSuperclass() {
        return superclass;
    }

    public List<ClassCase> getSupertypes() {
        return supertypes;
    }

    public List<ClassCase> getInterfaces() {
        if (superclass != null) {
            if (supertypes.get(0) != superclass) {
                throw new AssertionError("superclass missing from supertypes");
            }
            return supertypes.subList(1, supertypes.size());
        } else {
            return supertypes;
        }
    }

    public boolean isSubtypeOf(ClassCase cc) {
        
        if (cc.equals(this)) {
            return true;
        }

        
        for (ClassCase sp : getSupertypes()) {
            if (cc.equals(sp)) {
                return true;
            }
        }

        
        for (ClassCase sp : getSupertypes()) {
            if (sp.isSubtypeOf(cc)) {
                return true;
            }
        }

        return false;
    }

    public void init(Map<String, Integer> namingContext) {
        if (name != null) {
            return; 
        }

        for (ClassCase sup : supertypes) {
            sup.init(namingContext);
        }

        
        StringBuilder sb = new StringBuilder();
        if (!supertypes.isEmpty()) {
            sb.append(isInterface() ? "I" : "C");
            for (ClassCase cc : supertypes) {
                sb.append(cc.getName());
            }
            sb.append(kind.isInterface ? "i" : "c");
        }
        sb.append(kind.prefix);
        String pname = sb.toString();
        Integer icnt = namingContext.get(pname);
        int cnt = icnt == null ? 0 : icnt;
        ++cnt;
        namingContext.put(pname, cnt);
        if (cnt > 1) {
            sb.append(cnt);
        }
        this.name = sb.toString();
    }

    public boolean isa(Kind... kinds) {
        for (Kind k : kinds) {
            if (kind == k) {
                return true;
            }
        }
        return false;
    }

    private void exec(RuleGroup rg ) {
        if (!executed.contains(rg)) {
            rg.exec(this);
            executed.add(rg);
        }
    }

    public void collectClasses(Set<ClassCase> seen) {
        seen.add(this);
        for (ClassCase cc : supertypes) {
            cc.collectClasses(seen);
        }
    }

    public String getID() {
        if (name == null) {
            throw new Error("Access to uninitialized ClassCase");
        } else {
            return name;
        }
    }

    public final String getName() {
        if (name == null) {
            return "ClassCase uninited@" + hashCode();
        } else {
            return name;
        }
    }

    @Override
    public boolean equals(Object obj) {
        return obj instanceof ClassCase && getID().equals(((ClassCase)obj).getID());
    }

    @Override
    public int hashCode() {
        return getID().hashCode();
    }

    @Override
    public String toString() {
        return getName();
    }
}
