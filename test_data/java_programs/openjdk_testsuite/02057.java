




import static org.testng.Assert.assertEquals;

import java.io.IOException;
import java.io.StringWriter;

import org.testng.annotations.Test;

import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.tree.JCTree;
import com.sun.tools.javac.tree.JCTree.JCExpression;
import com.sun.tools.javac.tree.Pretty;
import com.sun.tools.javac.tree.TreeMaker;
import com.sun.tools.javac.util.Context;
import com.sun.tools.javac.util.Names;



@Test
public class T8024415 {

    TreeMaker maker;
    JCExpression x;


    public T8024415() {
        Context ctx = new Context();
        JavacFileManager.preRegister(ctx);
        maker = TreeMaker.instance(ctx);
        Names names = Names.instance(ctx);
        x = maker.Ident(names.fromString("x"));
    }


    
    
    
    public void testAssociativity() throws IOException {

        JCTree left   = maker.Conditional(maker.Conditional(x, x, x), x, x);
        JCTree right  = maker.Conditional(x, x, maker.Conditional(x, x, x));

        String prettyLeft   = prettyPrint(left);
        String prettyRight  = prettyPrint(right);

        assertEquals(prettyLeft.replaceAll("\\s", ""),  "(x?x:x)?x:x");
        assertEquals(prettyRight.replaceAll("\\s", ""), "x?x:x?x:x");

    }


    
    
    
    public void testPrecedence() throws IOException {

        JCTree left   = maker.Conditional(maker.Assign(x, x), x, x);
        JCTree middle = maker.Conditional(x, maker.Assign(x, x), x);
        JCTree right  = maker.Conditional(x, x, maker.Assign(x, x));

        String prettyLeft   = prettyPrint(left);
        String prettyMiddle = prettyPrint(middle);
        String prettyRight  = prettyPrint(right);

        assertEquals(prettyLeft.replaceAll("\\s", ""),   "(x=x)?x:x");
        assertEquals(prettyMiddle.replaceAll("\\s", ""), "x?x=x:x");
        assertEquals(prettyRight.replaceAll("\\s", ""),  "x?x:(x=x)");

    }


    
    private static String prettyPrint(JCTree tree) throws IOException {
        StringWriter sw = new StringWriter();
        new Pretty(sw, true).printExpr(tree);
        return sw.toString();
    }

}
