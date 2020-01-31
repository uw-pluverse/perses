



import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.ConstantPoolException;
import com.sun.tools.classfile.Method;
import com.sun.tools.classfile.Attribute;
import com.sun.tools.classfile.Code_attribute;
import com.sun.tools.classfile.LineNumberTable_attribute;
import com.sun.tools.classfile.LineNumberTable_attribute.Entry;

import java.io.IOException;

public class FinallyLineNumberTest {
    public static void main(String[] args) throws Exception {
        
        Entry[] lines = findEntries();
        if (lines == null) {
            throw new Exception("finally line number table could not be loaded");
        }
        if (lines.length != 5) {
            
            System.err.println("LineTable error, got lines:");
            for (Entry e : lines) {
                System.err.println(e.line_number);
            }
            throw new Exception("finally line number table incorrect: length=" + lines.length + " expected length=5");
        }

        
        int current = lines[0].line_number;
        int first = current;

        
        current = lines[1].line_number;
        if (current != first + 2) {
            throw new Exception("finally line number table incorrect: got=" + current + " expected=" + (first + 2));
        }

        
        current = lines[2].line_number;
        if (current != first) {
            throw new Exception("finally line number table incorrect: got=" + current + " expected=" + first);
        }

        
        current = lines[3].line_number;
        if (current != first + 2) {
            throw new Exception("finally line number table incorrect: got=" + current + " expected=" + (first + 2));
        }

        
        current = lines[4].line_number;
        if (current != first + 3) {
            throw new Exception("finally line number table incorrect: got=" + current + " expected=" + (first + 3));
        }
    }

    static Entry[] findEntries() throws IOException, ConstantPoolException {
        ClassFile self = ClassFile.read(FinallyLineNumberTest.class.getResourceAsStream("FinallyLineNumberTest.class"));
        for (Method m : self.methods) {
            if ("method".equals(m.getName(self.constant_pool))) {
                Code_attribute code_attribute = (Code_attribute)m.attributes.get(Attribute.Code);
                for (Attribute at : code_attribute.attributes) {
                    if (Attribute.LineNumberTable.equals(at.getName(self.constant_pool))) {
                        return ((LineNumberTable_attribute)at).line_number_table;
                    }
                }
            }
        }
        return null;
    }

    
    
    
    
    
    public static String method(int field) {
        try {
            return null;
        } finally {
            field+=1; 
        }
    }
}
