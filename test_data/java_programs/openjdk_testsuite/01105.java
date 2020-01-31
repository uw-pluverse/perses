




import java.io.*;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class RunExamples {
    public static void main(String... args) throws Exception {
        jtreg = (System.getProperty("test.src") != null);
        Path tmpDir;
        boolean deleteOnExit;
        if (jtreg) {
            
            tmpDir = Paths.get(System.getProperty("user.dir"));
            deleteOnExit = false;
        } else {
            tmpDir = Files.createTempDirectory(Paths.get(System.getProperty("java.io.tmpdir")),
                    RunExamples.class.getName());
            deleteOnExit = true;
        }
        Example.setTempDir(tmpDir.toFile());

        RunExamples r = new RunExamples();

        try {
            if (r.run(args))
                return;
        } finally {
            if (deleteOnExit) {
                clean(tmpDir);
            }
        }

        if (jtreg)
            throw new Exception(r.errors + " errors occurred");
        else
            System.exit(1);
    }

    boolean run(String... args) {
        Set<String> selectedKeys = new TreeSet<String>();
        Set<Example> selectedExamples = new TreeSet<Example>();
        File testSrc = new File(System.getProperty("test.src", "."));
        File examplesDir = new File(testSrc, "examples");
        File outFile = null;
        boolean raw = false;
        boolean showFiles = false;
        boolean verbose = false;
        boolean argTypes = false;
        String title = null;

        for (int i = 0; i < args.length; i++) {
            String arg = args[i];
            if (arg.equals("-k") && (i + 1) < args.length)
                selectedKeys.add(args[++i]);
            else if (arg.equals("-examples") && (i + 1) < args.length)
                examplesDir = new File(args[++i]);
            else if (arg.equals("-raw"))
                raw = true;
            else if (arg.equals("-showFiles"))
                showFiles = true;
            else if (arg.equals("-verbose"))
                verbose = true;
            else if (arg.equals("-o") && (i + 1) < args.length)
                outFile = new File(args[++i]);
            else if (arg.equals("-title") && (i + 1) < args.length)
                title = args[++i];
            else if (arg.equals("-argtypes"))
                argTypes = true;
            else if (arg.startsWith("-")) {
                error("unknown option: " + arg);
                return false;
            } else {
                while (i < args.length) {
                    File f = new File(examplesDir, args[i]);
                    selectedExamples.add(new Example(f));
                    i++;
                }
            }
        }

        
        
        if (argTypes)
            Example.Compiler.factory = new ArgTypeCompilerFactory();

        if (selectedKeys.size() > 0) {
            Set<Example> examples = getExamples(examplesDir);
        nextKey:
            for (String k: selectedKeys) {
                for (Example e: examples) {
                    if (e.getDeclaredKeys().contains(k))
                        continue nextKey;
                }
                error("Key " + k + ": no examples found");
            }
        } else {
            if (selectedExamples.isEmpty())
                selectedExamples = getExamples(examplesDir);
        }

        try {
            Runner r;
            if (outFile == null) {
                PrintWriter out = new PrintWriter(System.out);
                r = new TextRunner(out, showFiles, raw, verbose);
            } else if (outFile.getName().endsWith(".html"))
                r = new HTMLRunner(outFile, showFiles, raw, verbose, title);
            else
                r = new TextRunner(outFile, showFiles, raw, verbose);
            r.run(selectedExamples);
            r.close();
        } catch (IOException e) {
            error("Error writing output: " + e);
        }

        return (errors == 0);
    }

    
    Set<Example> getExamples(File examplesDir) {
        Set<Example> results = new TreeSet<Example>();
        for (File f: examplesDir.listFiles()) {
            if (isValidExample(f))
                results.add(new Example(f));
        }
        return results;
    }

    boolean isValidExample(File f) {
        return (f.isDirectory() && (!jtreg || f.list().length > 0)) ||
                (f.isFile() && f.getName().endsWith(".java"));
    }

    
    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    static boolean jtreg;

    int errors;

    
    static void clean(Path dir) throws IOException {
        Files.walkFileTree(dir, new SimpleFileVisitor<Path>() {
            @Override
            public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
                Files.delete(file);
                return super.visitFile(file, attrs);
            }

            @Override
            public FileVisitResult postVisitDirectory(Path dir, IOException exc) throws IOException {
                if (exc == null) Files.delete(dir);
                return super.postVisitDirectory(dir, exc);
            }
        });
    }

    static abstract class Runner {
        Runner(boolean showFiles, boolean raw, boolean verbose) {
            this.showFiles = showFiles;
            this.raw = raw;
            this.verbose = verbose;
        }

        void close() throws IOException { }

        void run(Collection<Example> examples) throws IOException {
            for (Example e: examples) {
                startExample(e);
                if (showFiles) {
                    showFile(e, e.infoFile);
                    Set<File> srcFiles = new TreeSet<File>(e.srcFiles);
                    srcFiles.remove(e.infoFile);
                    showFiles(e, srcFiles);
                    showFiles(e, e.srcPathFiles);
                    showFiles(e, e.procFiles);
                    showFiles(e, e.supportFiles);
                }
                run(e);
            }
        }

        void showFiles(Example e, Collection<File> files) throws IOException {
            for (File f: files)
                showFile(e, f);
        }

        abstract void startExample(Example e) throws IOException;

        abstract void showFile(Example e, File f) throws IOException;

        abstract void run(Example e) throws IOException;

        protected String read(File f) throws IOException {
            byte[] bytes = new byte[(int) f.length()];
            DataInputStream in = new DataInputStream(new FileInputStream(f));
            try {
                in.readFully(bytes);
            } finally {
                in.close();
            }
            return new String(bytes);
        }

        protected Pattern copyrightHeaderPat =
                Pattern.compile("(?s)(/\\*.*?Copyright.*?\\*/\n)\\s*(.*)");
        protected Pattern infoHeaderPat =
                Pattern.compile("(?s)((?://\\s*[a-z]+:[^\n]*\n)+)\\s*(.*)");

        protected boolean showFiles;
        protected boolean raw;
        protected boolean verbose;
    }

    static class TextRunner extends Runner {
        TextRunner(File file, boolean showFiles, boolean raw, boolean verbose)
                throws IOException {
            super(showFiles, raw, verbose);
            this.file = file;
            out = new PrintWriter(new FileWriter(file));
        }

        TextRunner(PrintWriter out, boolean showFiles, boolean raw, boolean verbose)
                throws IOException {
            super(showFiles, raw, verbose);
            this.out = out;
        }

        @Override
        void close() {
            if (file != null)
                out.close();
        }

        @Override
        void startExample(Example e) {
            out.println("----- " + e.getName() + " --------------------");
            out.println();
        }

        @Override
        void showFile(Example e, File f) {
            out.println("--- " + f);
            String text;
            try {
                text = read(f);
            } catch (IOException ex) {
                text = "Error reading " + f + "; " + ex;
            }
            Matcher m = copyrightHeaderPat.matcher(text);
            if (m.matches()) {
                out.println("(Copyright)");
                writeLines(m.group(2));
            } else {
                writeLines(text);
            }
            out.println();
        }

        @Override
        void run(Example e) {
            
            if (showFiles)
                out.println("--- Output:");
            e.run(out, raw, verbose);
            out.println();
        }

        void writeLines(String text) {
            for (String line: text.split("\n"))
                out.println(line);
        }

        File file;
        PrintWriter out;
    }

    static class HTMLRunner extends Runner {
        HTMLRunner(File file, boolean showFiles, boolean raw, boolean verbose, String title)
                throws IOException {
            super(showFiles, raw, verbose);
            this.file = file;
            PrintWriter out = new PrintWriter(new FileWriter(file));
            html = new HTMLWriter(out);
            html.startTag(HTMLWriter.HEAD);
            if (title != null) {
                html.startTag(HTMLWriter.TITLE);
                html.write(title);
                html.endTag(HTMLWriter.TITLE);
            }
            html.startTag(HTMLWriter.STYLE);
            html.newLine();
            html.writeLine("div.file { background-color:#e0ffe0; margin-left:30px; margin-right:30px;\n"
                    + "  padding: 3px; border: thin solid silver; }");
            html.writeLine("p.file { white-space: pre-wrap; font-family:monospace; margin: 0; }");
            html.writeLine("div.output { background-color:#e0e0ff; margin-left:30px; margin-right:30px;\n"
                    + "  padding: 3px; border: thin solid silver; }");
            html.writeLine("p.output { white-space: pre-wrap; font-family:monospace; margin: 0; }");
            html.writeLine("table.index { border: thin solid silver; }");
            html.writeLine(".copyright { font-size: x-small }");
            html.writeLine(".hidden { display:none }");
            html.writeLine(".unhidden { display:block }");
            html.writeLine(".odd { background-color: #e0e0e0 }");
            html.writeLine(".even { background-color: white }");
            html.endTag(HTMLWriter.STYLE);
            html.startTag(HTMLWriter.SCRIPT);
            html.writeAttr(HTMLWriter.TYPE, HTMLWriter.TEXT_JAVASCRIPT);
            html.writeLine("\nfunction unhide(id) {\n"
                        + "  var item = document.getElementById(id);\n"
                        + "  if (item) {\n"
                        + "    item.className=(item.className=='hidden')?'unhidden':'hidden';\n"
                        + "  }\n"
                        + "}");
            html.endTag(HTMLWriter.SCRIPT);
            html.endTag(HTMLWriter.HEAD);
            html.startTag(HTMLWriter.BODY);
            if (title != null) {
                html.startTag(TITLE_HEADER);
                html.write(title);
                html.endTag(TITLE_HEADER);
            }
        }

        @Override
        void close() throws IOException {
            html.endTag(HTMLWriter.BODY);
            html.newLine();
            html.flush();
        }

        @Override
        void run(Collection<Example> examples) throws IOException {
            if (examples.size() > 1)
                writeIndex(examples);
            super.run(examples);
        }

        void writeIndex(Collection<Example> examples) throws IOException {
            Map<String, Set<Example>> index = new TreeMap<String, Set<Example>>();
            Set<String> initials = new HashSet<String>();
            for (Example e: examples) {
                for (String k: e.getDeclaredKeys()) {
                    Set<Example> s = index.get(k);
                    if (s == null)
                        index.put(k, s = new TreeSet<Example>());
                    s.add(e);
                }
                initials.add(e.getName().substring(0, 1).toUpperCase());
            }


            if (INDEX_HEADER != null) {
                html.startTag(INDEX_HEADER);
                html.write("Index");
                html.endTag(INDEX_HEADER);
            }

            html.startTag(HTMLWriter.P);
            html.writeLine("Examples: ");
            for (char initial = 'A'; initial <= 'Z'; initial++) {
                String s = String.valueOf(initial);
                if (initials.contains(s)) {
                    html.writeLink("#" + s, s);
                } else {
                    html.write(s);
                }
                html.newLine();
            }
            html.endTag(HTMLWriter.P);

            html.startTag(HTMLWriter.TABLE);
            html.writeAttr(HTMLWriter.CLASS, "index");
            html.newLine();
            int row = 0;
            for (Map.Entry<String, Set<Example>> entry: index.entrySet()) {
                html.startTag(HTMLWriter.TR);
                html.writeAttr(HTMLWriter.CLASS,
                        (row++ % 2 == 0 ? "even" : "odd"));
                html.startTag(HTMLWriter.TD);
                html.writeAttr("valign", "top");
                html.write(entry.getKey());
                html.endTag(HTMLWriter.TD);
                html.newLine();
                html.startTag(HTMLWriter.TD);
                html.writeAttr(HTMLWriter.ALIGN, "top");
                String sep = "";
                for (Example e: entry.getValue()) {
                    html.write(sep);
                    html.writeLink('#' + e.getName(), e.getName());
                    sep = ", ";
                }
                html.endTag(HTMLWriter.TD);
                html.endTag(HTMLWriter.TR);
                html.newLine();
            }
            html.endTag(HTMLWriter.TABLE);
        }

        @Override
        void startExample(Example e) throws IOException {
            String name = e.getName();
            String initial = name.substring(0, 1).toUpperCase();
            if (!initial.equals(currInitial)) {
                html.writeLinkDestination(initial, "");
                currInitial = initial;
            }
            html.writeLinkDestination(name, "");
            html.startTag(EXAMPLE_HEADER);
            html.write(e.getName());
            html.endTag(EXAMPLE_HEADER);
        }

        @Override
        void showFile(Example e, File f) throws IOException {
            String text;
            try {
                text = read(f);
            } catch (IOException ex) {
                text = "Error reading " + f + ": " + ex;
            }
            if (!f.equals(e.file)) {
                html.startTag(FILE_HEADER);
                html.write(e.file.toURI().relativize(f.toURI()).toString());
                html.endTag(FILE_HEADER);
            }
            html.startTag(HTMLWriter.DIV);
            html.writeAttr(CLASS, FILE);

            String legalHeader;
            Matcher m1 = copyrightHeaderPat.matcher(text);
            if (m1.matches()) {
                legalHeader = m1.group(1);
                text = m1.group(2);
            } else
                legalHeader = null;

            String infoHeader;
            Matcher m2 = infoHeaderPat.matcher(text);
            if (m2.matches()) {
                infoHeader = m2.group(1);
                text = m2.group(2);
            } else
                infoHeader = null;

            String legalId = null, infoId = null;
            if (legalHeader != null || infoHeader != null) {
                String sep = "";
                html.startTag(HTMLWriter.SPAN);
                html.writeStyleAttr("float: right");
                if (legalHeader != null) {
                    legalId = nextId();
                    html.startTag(HTMLWriter.A);
                    html.writeAttr(HTMLWriter.HREF, "javascript:unhide('" + legalId + "');");
                    
                    html.write("Copyright");
                    html.endTag(HTMLWriter.A);
                    sep = ", ";
                }
                if (infoHeader != null) {
                    html.write(sep);
                    infoId = nextId();
                    html.startTag(HTMLWriter.A);
                    html.writeAttr(HTMLWriter.HREF, "javascript:unhide('" + infoId + "');");
                    html.write("Info");
                    html.endTag(HTMLWriter.A);
                    sep = ", ";
                }
                html.endTag(HTMLWriter.SPAN);
            }

            html.startTag(HTMLWriter.P);
            html.writeAttr(CLASS, FILE);
            if (legalHeader != null) {
                html.startTag(HTMLWriter.SPAN);
                html.writeAttr(HTMLWriter.CLASS, "hidden");
                html.writeAttr(HTMLWriter.ID, legalId);
                html.write(legalHeader);
                html.newLine();
                html.endTag(HTMLWriter.SPAN);
            }
            if (infoHeader != null) {
                html.startTag(HTMLWriter.SPAN);
                html.writeAttr(HTMLWriter.CLASS, "hidden");
                html.writeAttr(HTMLWriter.ID, infoId);
                html.write(infoHeader);
                html.newLine();
                html.endTag(HTMLWriter.SPAN);
            }
            html.write(text);
            html.endTag(HTMLWriter.P);

            html.endTag(HTMLWriter.DIV);
        }

        @Override
        void run(Example e) throws IOException {
            StringWriter sw = new StringWriter();
            PrintWriter pw = new PrintWriter(sw);
            e.run(pw, raw, verbose);
            pw.flush();

            
            if (showFiles) {
                html.startTag(OUTPUT_HEADER);
                html.write("Output:");
                html.endTag(OUTPUT_HEADER);
            }

            html.startTag(HTMLWriter.DIV);
            html.writeAttr(CLASS, OUTPUT);
            html.startTag(HTMLWriter.P);
            html.writeAttr(CLASS, OUTPUT);
            String[] lines = sw.toString().split("\n");
            for (String line: lines) {
                html.write(line);
                html.newLine();
            }
            html.endTag(HTMLWriter.P);
            html.endTag(HTMLWriter.DIV);
        }

        String nextId() {
            return "id" + (nextId++);
        }

        File file;
        HTMLWriter html;
        int nextId;
        String currInitial = "";

        static final String TITLE_HEADER = HTMLWriter.H3;
        static final String INDEX_HEADER = HTMLWriter.H4;
        static final String EXAMPLE_HEADER = HTMLWriter.H4;
        static final String FILE_HEADER = HTMLWriter.H5;
        static final String OUTPUT_HEADER = HTMLWriter.H5;
        static final String CLASS = "class";
        static final String FILE = "file";
        static final String OUTPUT = "output";
    }
}


