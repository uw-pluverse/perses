

import java.lang.annotation.*;

import java.io.*;



class ResourceVariables {
    void m() throws Exception {
        try (@A InputStream is = new @B FileInputStream("xxx")) {
        }
    }
}

@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface A { }
@Target({ElementType.TYPE_USE, ElementType.TYPE_PARAMETER})
@interface B { }
