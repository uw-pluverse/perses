

package org.openjdk.tests.separate;

import java.util.HashMap;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

class DirectedClassLoader extends ClassLoader {

    private HashMap<String,File> loadLocations;
    private File defaultLocation;
    private ClassFilePreprocessor[] preprocessors;

    public DirectedClassLoader(
            HashMap<String,File> locations, File fallback,
            ClassFilePreprocessor ... preprocessors) {
        loadLocations = new HashMap<>(locations);
        defaultLocation = fallback;
        this.preprocessors = preprocessors;
    }

    public DirectedClassLoader(
            File fallback, ClassFilePreprocessor ... preprocessors) {
        loadLocations = new HashMap<>();
        defaultLocation = fallback;
        this.preprocessors = preprocessors;
    }

    public DirectedClassLoader(ClassFilePreprocessor ... preprocessors) {
        this((File)null, preprocessors);
    }

    public void setDefaultLocation(File dir) { this.defaultLocation = dir; }
    public void setLocationFor(String name, File dir) {
        loadLocations.put(name, dir);
    }

    @Override
    protected Class<?> findClass(String name) {
        String path = name.replace(".", File.separator) + ".class";

        File location = loadLocations.get(name);
        if (location == null || !(new File(location, path)).exists()) {
            File def = new File(defaultLocation, path);
            if (def.exists()) {
                return defineFrom(name, new File(location, path));
            }
        } else {
            return defineFrom(name, new File(location, path));
        }
        return null;
    }

    private Class<?> defineFrom(String name, File file) {
        FileInputStream fis = null;
        try {
            try {
                fis = new FileInputStream(file);
                byte[] bytes = new byte[fis.available()];
                int read = fis.read(bytes);
                if (read != bytes.length) {
                    return null;
                }
                if (preprocessors != null) {
                    for (ClassFilePreprocessor cfp : preprocessors) {
                        bytes = cfp.preprocess(name, bytes);
                    }
                 }
                return defineClass(name, bytes, 0, bytes.length);
            } finally {
                fis.close();
            }
        } catch (IOException e) {}
        return null;
    }
}
