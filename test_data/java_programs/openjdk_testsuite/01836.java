

import javax.annotation.processing.*;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.*;
import javax.lang.model.util.*;
import static javax.lang.model.util.ElementFilter.*;
import static javax.tools.Diagnostic.Kind.*;
import java.util.*;
import java.util.Set;

public class b6341534 extends JavacTestingAbstractProcessor {
    static int r = 0;

    
    public boolean process(Set<? extends TypeElement> tes, RoundEnvironment renv)
    {
        if(!renv.errorRaised() &&  !renv.processingOver()){
            r++;
            for( TypeElement t : typesIn(renv.getRootElements()) )
                System.out.println("Round"+r+ ": " + t.toString());

            try {
                PackageElement PE = eltUtils.getPackageElement("dir1");
                List<? extends Element> LEE = PE.getEnclosedElements();    
                for(Element e : LEE)
                    System.out.println("found " + e.toString() + " in dir1.");
            }
            catch(NullPointerException npe) {
                messager.printMessage(ERROR,npe.toString());
                
                return false;
            }
        }
        
        
        if( renv.errorRaised() != renv.processingOver()) {
            messager.printMessage(ERROR, "FAILED: round:" + r
                + ", errorRaised:" + renv.errorRaised()
                + ", processingOver:" + renv.processingOver());
        }
        return true;
    }
}
