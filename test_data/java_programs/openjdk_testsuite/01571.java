

package org.openjdk.tests.shapegen;

import org.openjdk.tests.shapegen.ClassCase.Kind;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

import static org.openjdk.tests.shapegen.ClassCase.Kind.*;


public class TTNode {

    final List<TTNode> supertypes;
    final boolean canBeClass;

    private int currentKindIndex;
    private Kind[] kinds;

    public TTNode(List<TTNode> subtypes, boolean canBeClass) {
        this.supertypes = subtypes;
        this.canBeClass = canBeClass;
    }

    public void start(boolean includeClasses) {
        kinds =
             supertypes.isEmpty()?
                (new Kind[]{IDEFAULT, IPRESENT})
             :  ((includeClasses && canBeClass)?
                  new Kind[]{CNONE, IVAC, IDEFAULT, IPRESENT}
                : new Kind[]{IVAC, IDEFAULT, IPRESENT});
        currentKindIndex = 0;

        for (TTNode sub : supertypes) {
            sub.start(includeClasses);
        }
    }

    public boolean next() {
        ++currentKindIndex;
        if (currentKindIndex >= kinds.length) {
            currentKindIndex = 0;
            return false;
        } else {
            return true;
        }
    }

    public void collectAllSubtypes(Set<TTNode> subs) {
        subs.add(this);
        for (TTNode n : supertypes) {
            n.collectAllSubtypes(subs);
        }
    }

    private Kind getKind() {
        return kinds[currentKindIndex];
    }

    boolean isInterface() {
        return getKind().isInterface;
    }

    boolean isClass() {
        return !isInterface();
    }

    boolean hasDefault() {
        return getKind() == IDEFAULT;
    }

    public boolean isValid() {
        for (TTNode n : supertypes) {
            if (!n.isValid() || (isInterface() && n.isClass())) {
                return false;
            }
        }
        return true;
    }

    public ClassCase genCase() {
        ClassCase subclass;
        List<TTNode> ttintfs;
        if (isClass() && !supertypes.isEmpty() && supertypes.get(0).isClass()) {
            subclass = supertypes.get(0).genCase();
            ttintfs = supertypes.subList(1, supertypes.size());
        } else {
            subclass = null;
            ttintfs = supertypes;
        }
        List<ClassCase> intfs = new ArrayList<>();
        for (TTNode node : ttintfs) {
            intfs.add(node.genCase());
        }
        return new ClassCase(getKind(), subclass, intfs);
    }
}
