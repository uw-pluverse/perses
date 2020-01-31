

package evalexpr;

import java.io.ByteArrayOutputStream;
import java.io.FilterOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.Reader;
import java.io.StringReader;
import java.net.URI;
import java.net.URISyntaxException;
import java.nio.CharBuffer;
import java.util.HashMap;
import java.util.Map;
import javax.tools.*;
import javax.tools.JavaFileObject.Kind;


public final class MemoryFileManager extends ForwardingJavaFileManager {
    
    private Map<String, byte[]> classes;

    
    public static JavaFileObject makeSource(String name, String code) {
        return new JavaSourceFromString(name, code);
    }

    
    public MemoryFileManager(JavaFileManager fileManager) {
        super(fileManager);
        classes = new HashMap<String, byte[]>();
    }

    
    @Override
    public ClassLoader getClassLoader(Location location) {
        return new ByteArrayClassLoader(classes);
    }

    @Override
    public JavaFileObject getJavaFileForOutput(Location location,
                                               String name,
                                               Kind kind,
                                               FileObject originatingSource)
        throws UnsupportedOperationException
    {
        if (originatingSource instanceof JavaSourceFromString) {
            return new JavaClassInArray(name);
        } else {
            throw new UnsupportedOperationException();
        }
    }

    protected static URI uriFromString(String uri) {
        try {
            return new URI(uri);
        } catch (URISyntaxException e) {
            throw new IllegalArgumentException(e);
        }
    }

    
    private class JavaClassInArray extends SimpleJavaFileObject {

        private String name;

        
        JavaClassInArray(String name) {
            super(uriFromString("mfm:///" + name.replace('.','/') + Kind.CLASS.extension),
                  Kind.CLASS);
            this.name = name;
        }

        public OutputStream openOutputStream() {
            return new FilterOutputStream(new ByteArrayOutputStream()) {
                public void close() throws IOException {
                    out.close();
                    ByteArrayOutputStream bos = (ByteArrayOutputStream)out;
                    classes.put(name, bos.toByteArray());
                    System.out.println("compiled " + name);
                }
            };
        }
    }

    
    private static class JavaSourceFromString extends SimpleJavaFileObject {
        
        final String code;

        
        JavaSourceFromString(String name, String code) {
            super(uriFromString("mfm:///" + name.replace('.','/') + Kind.SOURCE.extension),
                  Kind.SOURCE);
            this.code = code;
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return code;
        }
    }

}
