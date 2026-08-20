package org.hibernate;

public class Session implements java.lang.AutoCloseable {

    public void close() throws java.lang.Exception {
        throw new java.lang.Error();
    }

    public org.hibernate.Transaction beginTransaction() {
        throw new java.lang.Error();
    }

    public CreateNativeQueryReturnType createNativeQuery(java.lang.String parameter0) {
        throw new java.lang.Error();
    }
}
