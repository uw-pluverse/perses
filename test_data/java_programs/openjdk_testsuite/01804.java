



import java.lang.annotation.*;
import java.util.Set;
import javax.annotation.processing.*;
import javax.lang.model.element.*;

import com.sun.tools.javac.util.*;

@ProcessingEnvAnnoDiscovery.Anno1
public class ProcessingEnvAnnoDiscovery<@ProcessingEnvAnnoDiscovery.Anno4 T>
        extends JavacTestingAbstractProcessor {
    private int round = 0;

    public boolean process(Set<? extends TypeElement> annos, RoundEnvironment rEnv) {
        if (round++ == 0) {
            System.out.println(annos);
            Assert.check(annos.contains(eltUtils.getTypeElement("java.lang.annotation.Target")));
            Assert.check(annos.contains(eltUtils.getTypeElement("ProcessingEnvAnnoDiscovery.Anno1")));
            Assert.check(annos.contains(eltUtils.getTypeElement("ProcessingEnvAnnoDiscovery.Anno2")));
            Assert.check(annos.contains(eltUtils.getTypeElement("ProcessingEnvAnnoDiscovery.Anno3")));
            Assert.check(annos.contains(eltUtils.getTypeElement("ProcessingEnvAnnoDiscovery.Anno4")));
            Assert.check(annos.contains(eltUtils.getTypeElement("ProcessingEnvAnnoDiscovery.Anno5")));
            Assert.check(annos.size() == 6, "Found extra annotations"); 
        }

        return true;
    }

    @Anno2
    public <@Anno5 K> K m(@Anno3 long foo) {
        return null;
    }

    @interface Anno1 {}

    @interface Anno2 {}

    @interface Anno3 {}

    @Target(ElementType.TYPE_PARAMETER)
    @interface Anno4 {}

    @Target(ElementType.TYPE_PARAMETER)
    @interface Anno5 {}

}
