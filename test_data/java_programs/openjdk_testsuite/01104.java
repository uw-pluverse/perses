



import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.io.Writer;
import java.net.URL;
import java.text.MessageFormat;
import java.util.ResourceBundle;


public class HTMLWriter
{
    
    public HTMLWriter(Writer out) throws IOException {
        this(out, "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 3.2//EN\">");
    }

    
    public HTMLWriter(Writer out, String docType) throws IOException {
        if (out instanceof BufferedWriter)
            this.out = (BufferedWriter) out;
        else
            this.out = new BufferedWriter(out);
        this.out.write(docType);
        this.out.newLine();
    }

    
    public HTMLWriter(Writer out, ResourceBundle i18n) throws IOException {
        this(out);
        this.i18n = i18n;
    }


    
    public HTMLWriter(Writer out, String docType, ResourceBundle i18n) throws IOException {
        this(out, docType);
        this.i18n = i18n;
    }

    
    public void setResourceBundle(ResourceBundle i18n) {
        this.i18n = i18n;
    }

    
    public void flush() throws IOException {
        out.flush();
    }

    
    public void close() throws IOException {
        out.close();
    }

    
    public void newLine() throws IOException {
        out.newLine();
    }

    
    public void startTag(String tag) throws IOException {
        if (state == IN_TAG) {
            out.write(">");
            state = IN_BODY;
        }
        
        out.write("<");
        out.write(tag);
        state = IN_TAG;
    }

    
    public void endTag(String tag) throws IOException {
        if (state == IN_TAG) {
            out.write(">");
            state = IN_BODY;
            out.newLine();
        }
        out.write("</");
        out.write(tag);
        out.write(">");
        
        state = IN_BODY;
    }

    
    public void endEmptyTag(String tag) throws IOException {
        if (state != IN_TAG)
            throw new IllegalStateException();

        out.write(">");
        state = IN_BODY;
        out.newLine();
    }

    
    public void writeAttr(String name, String value) throws IOException {
        if (state != IN_TAG)
            throw new IllegalStateException();

        out.write(" ");
        out.write(name);
        out.write("=");
        boolean alpha = true;
        for (int i = 0; i < value.length() && alpha; i++)
            alpha = Character.isLetter(value.charAt(i));
        if (!alpha)
            out.write("\"");
        out.write(value);
        if (!alpha)
            out.write("\"");
    }

    
    public void writeAttr(String name, int value) throws IOException {
        writeAttr(name, Integer.toString(value));
    }

    
    public void writeLine(String text) throws IOException {
        write(text);
        out.newLine();
    }

    
    public void write(String text) throws IOException {
        if (state == IN_TAG) {
            out.write(">");
            state = IN_BODY;
        }

        if (text == null)
            return;

        
        boolean specialChars = false;
        for (int i = 0; i < text.length() && !specialChars; i++) {
            switch (text.charAt(i)) {
            case '<': case '>': case '&':
                specialChars = true;
            }
        }

        
        
        if (specialChars) {
            for (int i = 0; i < text.length(); i++) {
                char c = text.charAt(i);
                switch (c) {
                case '<': out.write("&lt;"); break;
                case '>': out.write("&gt;"); break;
                case '&': out.write("&amp;"); break;
                default: out.write(c);
                }
            }
        }
        else
            out.write(text);
    }

    
    public void writeEntity(String entity) throws IOException {
        if (state == IN_TAG) {
            out.write(">");
            state = IN_BODY;
        }
        out.write(entity);
    }

    
    public void writeImage(String imagePath) throws IOException {
        startTag(IMAGE);
        writeAttr(SRC, imagePath);
    }

    
    public void writeImage(URL imageURL) throws IOException {
        writeImage(imageURL.toString());
    }

    
    public void writeLink(String anchor, String body) throws IOException {
        startTag(A);
        writeAttr(HREF, anchor);
        write(body);
        endTag(A);
    }

    
    public void writeLink(File file, String body) throws IOException {
        startTag(A);
        StringBuffer sb = new StringBuffer();
        String path = file.getPath().replace(File.separatorChar, '/');
        if (file.isAbsolute() && !path.startsWith("/"))
            sb.append('/');
        sb.append(path);
        writeAttr(HREF, sb.toString());
        write(body);
        endTag(A);
    }

    
    public void writeLink(File file) throws IOException {
        writeLink(file, file.getPath());
    }

    
    public void writeLink(URL url, String body) throws IOException {
        startTag(A);
        writeAttr(HREF, url.toString());
        write(body);
        endTag(A);
    }

    
    public void writeLinkDestination(String anchor, String body) throws IOException {
        startTag(A);
        writeAttr(NAME, anchor);
        write(body);
        endTag(A);
    }

    
    public void writeParam(String name, String value) throws IOException {
        startTag(PARAM);
        writeAttr(NAME, name);
        writeAttr(VALUE, value);
    }

    
    public void writeStyleAttr(String value) throws IOException {
        writeAttr(STYLE, value);
    }

    
    public void write(ResourceBundle i18n, String key) throws IOException {
        write(getString(i18n, key));
    }

    
    public void write(ResourceBundle i18n, String key, Object arg) throws IOException {
        write(getString(i18n, key, arg));
    }

    
    public void write(ResourceBundle i18n, String key, Object[] args) throws IOException {
        write(getString(i18n, key, args));
    }

    
    public void writeI18N(String key) throws IOException {
        write(getString(i18n, key));
    }

    
    public void writeI18N(String key, Object arg) throws IOException {
        write(getString(i18n, key, arg));
    }

    
    public void writeI18N(String key, Object[] args) throws IOException {
        write(getString(i18n, key, args));
    }

    private String getString(ResourceBundle rb, String key, Object... args) {
        String s = rb.getString(key);
        return MessageFormat.format(s, args);
    }

    
    public static final String A = "a";
    
    public static final String ALIGN = "align";
    
    public static final String B = "b";
    
    public static final String BODY = "body";
    
    public static final String BORDER = "border";
    
    public static final String BR = "br";
    
    public static final String CLASS  = "class";
    
    public static final String CLASSID  = "classid";
    
    public static final String CODE  = "code";
    
    public static final String COLOR  = "color";
    
    public static final String COL = "col";
    
    public static final String DD = "dd";
    
    public static final String DIV = "div";
    
    public static final String DL = "dl";
    
    public static final String DT = "dt";
    
    public static final String FONT = "font";
    
    public static final String H1 = "h1";
    
    public static final String H2 = "h2";
    
    public static final String H3 = "h3";
    
    public static final String H4 = "h4";
    
    public static final String H5 = "h5";
    
    public static final String HEAD = "head";
    
    public static final String HREF = "href";
    
    public static final String HTML = "html";
    
    public static final String HR = "hr";
    
    public static final String I = "i";
    
    public static final String ID = "id";
    
    public static final String IMAGE = "image";
    
    public static final String LEFT = "left";
    
    public static final String LI = "li";
    
    public static final String LINK = "link";
    
    public static final String NAME = "name";
    
    public static final String OBJECT = "object";
    
    public static final String PARAM = "param";
    
    public static final String P = "p";
    
    public static final String REL = "rel";
    
    public static final String RIGHT = "right";
    
    public static final String ROW = "row";
    
    public static final String SCRIPT = "script";
    
    public static final String SMALL = "small";
    
    public static final String SPAN = "span";
    
    public static final String SRC = "src";
    
    public static final String SCOPE = "scope";
    
    public static final String STYLE = "style";
    
    public static final String TABLE = "table";
    
    public static final String TD = "td";
    
    public static final String TEXT_JAVASCRIPT = "text/javascript";
    
    public static final String TITLE = "title";
    
    public static final String TH = "th";
    
    public static final String TOP = "top";
    
    public static final String TR = "tr";
    
    public static final String TYPE = "type";
    
    public static final String UL = "ul";
    
    public static final String VALIGN = "valign";
    
    public static final String VALUE = "value";


    private BufferedWriter out;
    private int state;
    private ResourceBundle i18n;
    private static final int IN_TAG = 1;
    private static final int IN_BODY = 2;
}
