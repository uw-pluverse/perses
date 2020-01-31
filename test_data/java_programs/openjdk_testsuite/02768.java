

class T6558548 {

    void nothing() {}
    void checked() throws InterruptedException {}
    void runtime() throws IllegalArgumentException {}

    void m1a() {
        try {
            throw new java.io.FileNotFoundException();
        }
        catch(java.io.FileNotFoundException exc) { }
        catch(java.io.IOException exc) { } 
    }

    void m1b() {
        try {
            throw new java.io.IOException();
        }
        catch(java.io.FileNotFoundException exc) { }
        catch(java.io.IOException exc) { } 
    }

    void m1c() {
        try {
            throw new java.io.FileNotFoundException();
        }
        catch(java.io.FileNotFoundException exc) { }
        catch(Exception ex) { } 
    }

    void m1d() {
        try {
            throw new java.io.FileNotFoundException();
        }
        catch(java.io.FileNotFoundException exc) { }
        catch(Throwable ex) { } 
    }

    void m3() {
        try {
            checked();
        }
        catch(Exception exc) { } 
    }

    void m4() {
        try {
            runtime();
        }
        catch(Exception exc) { } 
    }

    void m5() {
        try {
            nothing();
        }
        catch(Throwable exc) { } 
    }

    void m6() {
        try {
            checked();
        }
        catch(Throwable exc) { } 
    }

    void m7() {
        try {
            runtime();
        }
        catch(Throwable exc) { } 
    }

    void m9() {
        try {
            checked();
        }
        catch(Error exc) { }
        catch(Throwable exc) { } 
    }

    void m10() {
        try {
            runtime();
        }
        catch(Error exc) { }
        catch(Throwable exc) { } 
    }

    void m11() {
        try {
            nothing();
        }
        catch(Error exc) { }
        catch(Throwable exc) { } 
    }

    void m12() {
        try {
            checked();
        }
        catch(RuntimeException exc) { }
        catch(Throwable exc) { } 
    }

    void m13() {
        try {
            runtime();
        }
        catch(RuntimeException exc) { }
        catch(Throwable exc) { } 
    }

    void m14() {
        try {
            nothing();
        }
        catch(RuntimeException exc) { }
        catch(Throwable exc) { } 
    }

    void m15() {
        try {
            checked();
        }
        catch(RuntimeException exc) { }
        catch(Exception exc) { } 
    }

    void m16() {
        try {
            runtime();
        }
        catch(RuntimeException exc) { }
        catch(Exception exc) { } 
    }

    void m17() {
        try {
            nothing();
        }
        catch(RuntimeException exc) { }
        catch(Exception exc) { } 
    }

    void m18() {
        try {
            checked();
        }
        catch(RuntimeException exc) { }
        catch(InterruptedException exc) { }
        catch(Exception exc) { } 
    }

    void m19() {
        try {
            runtime();
        }
        catch(RuntimeException exc) { }
        catch(InterruptedException exc) { } 
        catch(Exception exc) { } 
    }

    void m20() {
        try {
            nothing();
        }
        catch(RuntimeException exc) { }
        catch(InterruptedException exc) { } 
        catch(Exception exc) { } 
    }

    void m21() {
        try {
            checked();
        }
        catch(RuntimeException exc) { }
        catch(Exception exc) { } 
    }

    void m22() {
        try {
            runtime();
        }
        catch(RuntimeException exc) { }
        catch(Exception exc) { } 
    }

    void m23() {
        try {
            nothing();
        }
        catch(RuntimeException exc) { }
        catch(Exception exc) { } 
    }

    void m24() {
        try {
            checked();
        }
        catch(RuntimeException exc) { }
        catch(Error exc) { }
        catch(Throwable exc) { } 
    }

    void m25() {
        try {
            runtime();
        }
        catch(RuntimeException exc) { }
        catch(Error exc) { }
        catch(Throwable exc) { } 
    }

    void m26() {
        try {
            nothing();
        }
        catch(RuntimeException exc) { }
        catch(Error exc) { }
        catch(Throwable exc) { } 
    }

    void m27() {
        try {
            checked();
        }
        catch(RuntimeException exc) { }
        catch(Error exc) { }
        catch(InterruptedException exc) { }
        catch(Throwable exc) { } 
    }

    void m28() {
        try {
            runtime();
        }
        catch(RuntimeException exc) { }
        catch(Error exc) { }
        catch(InterruptedException exc) { } 
        catch(Throwable exc) { } 
    }

    void m29() {
        try {
            nothing();
        }
        catch(RuntimeException exc) { }
        catch(Error exc) { }
        catch(InterruptedException exc) { } 
        catch(Throwable exc) { } 
    }

    void m30() {
        try {
            checked();
        }
        catch(RuntimeException exc) { }
        catch(Error exc) { }
        catch(Throwable exc) { } 
    }

    void m31() {
        try {
            runtime();
        }
        catch(RuntimeException exc) { }
        catch(Error exc) { }
        catch(Throwable exc) { } 
    }

    void m32() {
        try {
            nothing();
        }
        catch(RuntimeException exc) { }
        catch(Error exc) { }
        catch(Throwable exc) { } 
    }

    void m33() {
        try {
            checked();
        }
        catch(InterruptedException exc) { } 
    }

    void m34() {
        try {
            runtime();
        }
        catch(InterruptedException exc) { } 
    }

    void m35() {
        try {
            nothing();
        }
        catch(InterruptedException exc) { } 
    }
}
