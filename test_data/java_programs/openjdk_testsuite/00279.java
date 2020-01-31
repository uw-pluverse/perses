



import com.sun.source.util.JavacTask;
import com.sun.tools.classfile.AccessFlags;
import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.ConstantPool;
import com.sun.tools.classfile.ConstantPoolException;
import com.sun.tools.classfile.Method;
import com.sun.tools.javac.code.Symbol.ClassSymbol;
import com.sun.tools.javac.util.List;

import java.io.File;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

import javax.annotation.processing.RoundEnvironment;
import javax.annotation.processing.SupportedAnnotationTypes;
import javax.lang.model.element.Element;
import javax.lang.model.element.TypeElement;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.ToolProvider;

import static javax.tools.StandardLocation.*;

public class BridgeHarness {

    
    static int nerrors = 0;

    
    static final JavaCompiler comp = ToolProvider.getSystemJavaCompiler();

    
    static final StandardJavaFileManager fm = comp.getStandardFileManager(null, null, null);

    public static void main(String[] args) throws Exception {
        
        fm.setLocation(SOURCE_PATH,
                Arrays.asList(new File(System.getProperty("test.src"), "tests")));
        
        fm.setLocation(javax.tools.StandardLocation.CLASS_OUTPUT,
                Arrays.asList(new File(System.getProperty("user.dir"))));
        for (JavaFileObject jfo : fm.list(SOURCE_PATH, "", Collections.singleton(JavaFileObject.Kind.SOURCE), true)) {
            
            new BridgeHarness(jfo).compileAndCheck();
        }
        
        if (nerrors > 0) {
            throw new AssertionError("Errors were found");
        }
    }

    

    
    static <Z> List<Z> drop(List<Z> lz, Z z) {
        if (lz.head == z) {
            return drop(lz.tail, z);
        } else if (lz.isEmpty()) {
            return lz;
        } else {
            return drop(lz.tail, z).prepend(lz.head);
        }
    }

    
    static String descriptor(Method m, ConstantPool cp) throws ConstantPoolException {
        return m.getName(cp) + m.descriptor.getValue(cp);
    }

    

    
    JavaFileObject jfo;

    
    Map<String, List<Bridge>> bridgesMap = new HashMap<String, List<Bridge>>();

    protected BridgeHarness(JavaFileObject jfo) {
        this.jfo = jfo;
    }

    
    protected void compileAndCheck() throws Exception {
        JavacTask ct = (JavacTask)comp.getTask(null, fm, null, null, null, Arrays.asList(jfo));
        ct.setProcessors(Collections.singleton(new BridgeFinder()));

        for (JavaFileObject jfo : ct.generate()) {
            checkBridges(jfo);
        }
    }

    
    protected void checkBridges(JavaFileObject jfo) {
        try (InputStream is = jfo.openInputStream()) {
            ClassFile cf = ClassFile.read(is);
            System.err.println("checking: " + cf.getName());

            List<Bridge> bridgeList = bridgesMap.get(cf.getName());
            if (bridgeList == null) {
                
                bridgeList = List.nil();
            }

            for (Method m : cf.methods) {
                if (m.access_flags.is(AccessFlags.ACC_SYNTHETIC | AccessFlags.ACC_BRIDGE)) {
                    
                    Bridge match = null;
                    for (Bridge b : bridgeList) {
                        if (b.value().equals(descriptor(m, cf.constant_pool))) {
                            match = b;
                            break;
                        }
                    }
                    if (match == null) {
                        error("No annotation for bridge method: " + descriptor(m, cf.constant_pool));
                    } else {
                        bridgeList = drop(bridgeList, match);
                    }
                }
            }
            if (bridgeList.nonEmpty()) {
                error("Redundant bridge annotation found: " + bridgeList.head.value());
            }
        } catch (Exception e) {
            e.printStackTrace();
            throw new Error("error reading " + jfo.toUri() +": " + e);
        }
    }

    
    protected void error(String msg) {
        nerrors++;
        System.err.printf("Error occurred while checking file: %s\nreason: %s\n", jfo.getName(), msg);
    }

    
    @SupportedAnnotationTypes({"Bridges","Bridge"})
    class BridgeFinder extends JavacTestingAbstractProcessor {
        @Override
        public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
            if (roundEnv.processingOver())
                return true;

            TypeElement bridgeAnno = elements.getTypeElement("Bridge");
            TypeElement bridgesAnno = elements.getTypeElement("Bridges");

            
            for (Element elem: roundEnv.getElementsAnnotatedWith(bridgesAnno)) {
                List<Bridge> bridgeList = List.nil();
                Bridges bridges = elem.getAnnotation(Bridges.class);
                for (Bridge bridge : bridges.value()) {
                    bridgeList = bridgeList.prepend(bridge);
                }
                bridgesMap.put(((ClassSymbol)elem).flatname.toString(), bridgeList);
            }

            
            for (Element elem: roundEnv.getElementsAnnotatedWith(bridgeAnno)) {
                Bridge bridge = elem.getAnnotation(Bridge.class);
                bridgesMap.put(((ClassSymbol)elem).flatname.toString(),
                        List.of(bridge));
            }

            return true;
        }
    }
}
