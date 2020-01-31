

package org.openjdk.tests.shapegen;


public abstract class Rule {

    public final String name;

    public Rule(String name) {
        this.name = name;
    }

    abstract boolean guard(ClassCase cc);

    abstract void eval(ClassCase cc);

    @Override
    public String toString() {
        return name;
    }
}
