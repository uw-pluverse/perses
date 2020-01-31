



class T {
    
    int var;

    
    void f() {
    }

    
    void g() {
        f();
    }

    void h() {
        f();
    }

    
    T() {
    }

    
    T(int i) {
        this();
    }

    T(float f) {
        this();
    }

    void xyzzy() {
        new T();
        new T(1.4f);
    }
    
    void plugh() {
        new T();
        new T(1.45f);
    }

    
    int calcx() { return 0; }
}

class U extends T {
    
    void f() {
    }

    void g() { 
        super.g(); 
        var = 12; 
    }

    U() {} 

    U(int i) {
        super(i); 
    }

    U(float f) {
        super(1.3f);
    }
}

class V extends T {} 


class W extends T { 
    
    static {
        new T(1.3f).g(); 
    }

    
    {
        new T(1.3f).g(); 
    }

    {
        new T(1.3f).g(); 
    }

    int x = calcx(); 

    
    int y = calcx();
}


class X {}

class Y extends X {} 


class Z extends X {}
