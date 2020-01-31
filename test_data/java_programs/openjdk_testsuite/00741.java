

package evalexpr;

import java.util.Map;


public class ByteArrayClassLoader extends ClassLoader {
    
    private Map<String, byte[]> classes;

    
    public ByteArrayClassLoader(Map<String, byte[]> classes) {
        this.classes = classes;
    }

    @Override
    public Class<?> loadClass(String name) throws ClassNotFoundException {
        try {
            return super.loadClass(name);
        } catch (ClassNotFoundException e) {
            byte[] classData = classes.get(name);
            return defineClass(name, classData, 0, classData.length);
        }
    }
}
