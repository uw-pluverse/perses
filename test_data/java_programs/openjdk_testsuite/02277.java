

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.net.URI;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.EnumSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;

import com.sun.source.util.JavacTask;
import com.sun.tools.javac.api.JavacTaskImpl;

import sun.tools.jar.Main;

import static java.nio.file.StandardCopyOption.*;



public class ToolBox {

    public static final String lineSeparator = System.getProperty("line.separator");
    public static final String jdkUnderTest = System.getProperty("test.jdk");
    public static final Path javaBinary = Paths.get(jdkUnderTest, "bin", "java");
    public static final Path javacBinary = Paths.get(jdkUnderTest, "bin", "javac");

    public static final List<String> testToolVMOpts;
    public static final List<String> testVMOpts;

    private static final Charset defaultCharset = Charset.defaultCharset();

    static final JavaCompiler comp = ToolProvider.getSystemJavaCompiler();

    static {
        String sysProp = System.getProperty("test.tool.vm.opts");
        if (sysProp != null && sysProp.length() > 0) {
            testToolVMOpts = Arrays.asList(sysProp.split("\\s+"));
        } else {
            testToolVMOpts = Collections.<String>emptyList();
        }

        sysProp = System.getProperty("test.vm.opts");
        if (sysProp != null && sysProp.length() > 0) {
            testVMOpts = Arrays.asList(sysProp.split("\\s+"));
        } else {
            testVMOpts = Collections.<String>emptyList();
        }
    }

    
    public enum Expect {SUCCESS, FAIL}

    enum AcceptedParams {
        EXPECT,
        SOURCES,
        OPTIONS,
        STD_OUTPUT,
        ERR_OUTPUT,
        EXTRA_ENV,
    }

    enum OutputKind {STD, ERR}

    
    static abstract class WriterHelper {
        OutputKind kind;
        public abstract void pipeOutput(ProcessBuilder pb);
        public abstract void readFromStream(Process p) throws IOException;
        public abstract void addAll(Collection<? extends String> c) throws IOException;
    }

    
    static class FileWriterHelper extends WriterHelper {
        File file;

        FileWriterHelper(File file, OutputKind kind) {
            this.file = file;
            this.kind = kind;
        }

        @Override
        public void pipeOutput(ProcessBuilder pb) {
            if (file != null) {
                switch (kind) {
                    case STD:
                        pb.redirectInput(file);
                        break;
                    case ERR:
                        pb.redirectError(file);
                        break;
                }
            }
        }

        @Override
        public void readFromStream(Process p) throws IOException {}

        @Override
        public void addAll(Collection<? extends String> c) throws IOException {
            if (file.exists())
                Files.write(file.toPath(), c, defaultCharset,
                        StandardOpenOption.WRITE, StandardOpenOption.APPEND);
            else
                Files.write(file.toPath(), c, defaultCharset);
        }
    }

    
    static class ListWriterHelper extends WriterHelper {
        List<String> list;

        public ListWriterHelper(List<String> list, OutputKind kind) {
            this.kind = kind;
            this.list = list;
        }

        @Override
        public void pipeOutput(ProcessBuilder pb) {}

        @Override
        public void readFromStream(Process p) throws IOException {
            BufferedReader br = null;
            switch (kind) {
                case STD:
                    br = new BufferedReader(new InputStreamReader(p.getInputStream()));
                    break;
                case ERR:
                    br = new BufferedReader(new InputStreamReader(p.getErrorStream()));
                    break;
            }
            String line;
            while ((line = br.readLine()) != null) {
                list.add(line);
            }
        }

        public void addAll(Collection<? extends String> c) {
            list.addAll(c);
        }
    }

    
    static class WriterHelperFactory {
        static WriterHelper make(File file, OutputKind kind) {
            return new FileWriterHelper(file, kind);
        }

        static WriterHelper make(List<String> list, OutputKind kind) {
            return new ListWriterHelper(list, kind);
        }
    }

    
    public static abstract class GenericArgs <T extends GenericArgs> {
        protected static List<Set<AcceptedParams>> minAcceptedParams;

        protected Set<AcceptedParams> currentParams =
                EnumSet.<AcceptedParams>noneOf(AcceptedParams.class);

        protected Expect whatToExpect;
        protected WriterHelper stdOutput;
        protected WriterHelper errOutput;
        protected List<String> args = new ArrayList<>();
        protected String[] argsArr;

        protected GenericArgs() {
            set(Expect.SUCCESS);
        }

        public T set(Expect whatToExpt) {
            currentParams.add(AcceptedParams.EXPECT);
            this.whatToExpect = whatToExpt;
            return (T)this;
        }

        public T setStdOutput(List<String> stdOutput) {
            currentParams.add(AcceptedParams.STD_OUTPUT);
            this.stdOutput = WriterHelperFactory.make(stdOutput, OutputKind.STD);
            return (T)this;
        }

        public T setStdOutput(File output) {
            currentParams.add(AcceptedParams.STD_OUTPUT);
            this.stdOutput = WriterHelperFactory.make(output, OutputKind.STD);
            return (T)this;
        }

        public T setErrOutput(List<String> errOutput) {
            currentParams.add(AcceptedParams.ERR_OUTPUT);
            this.errOutput = WriterHelperFactory.make(errOutput, OutputKind.ERR);
            return (T)this;
        }

        public T setErrOutput(File errOutput) {
            currentParams.add(AcceptedParams.ERR_OUTPUT);
            this.errOutput = WriterHelperFactory.make(errOutput, OutputKind.ERR);
            return (T)this;
        }

        public T setAllArgs(String... args) {
            currentParams.add(AcceptedParams.OPTIONS);
            this.argsArr = args;
            return (T) this;
        }


        public T appendArgs(String... args) {
            appendArgs(Arrays.asList(args));
            return (T)this;
        }

        public T appendArgs(Path... args) {
            if (args != null) {
                List<String> list = new ArrayList<>();
                for (int i = 0; i < args.length; i++) {
                    if (args[i] != null) {
                        list.add(args[i].toString());
                    }
                }
                appendArgs(list);
            }
            return (T)this;
        }

        public T appendArgs(List<String> args) {
            if (args != null && args.size() > 0) {
                currentParams.add(AcceptedParams.OPTIONS);
                for (int i = 0; i < args.size(); i++) {
                    if (args.get(i) != null) {
                        this.args.add(args.get(i));
                    }
                }
            }
            return (T)this;
        }

        public T setOptions(List<String> options) {
            currentParams.add(AcceptedParams.OPTIONS);
            this.args = options;
            return (T)this;
        }

        public T setOptions(String... options) {
            currentParams.add(AcceptedParams.OPTIONS);
            this.args = Arrays.asList(options);
            return (T)this;
        }

        public boolean hasMinParams() {
            for (Set<AcceptedParams> minSet : minAcceptedParams) {
                if (currentParams.containsAll(minSet)) {
                    return true;
                }
            }
            return false;
        }
    }

    
    public static class JavaToolArgs extends GenericArgs<JavaToolArgs> {

        static {
            minAcceptedParams = new ArrayList<>();
            minAcceptedParams.add(EnumSet.<AcceptedParams>of(
                    AcceptedParams.EXPECT, AcceptedParams.OPTIONS));
            minAcceptedParams.add(EnumSet.<AcceptedParams>of(
                    AcceptedParams.EXPECT, AcceptedParams.SOURCES));
        }

        protected List<? extends JavaFileObject> sources;

        public JavaToolArgs() {
            super();
        }

        public JavaToolArgs(Expect whatToExpt) {
            super.set(whatToExpt);
        }

        public JavaToolArgs setSources(List<? extends JavaFileObject> sources) {
            currentParams.add(AcceptedParams.SOURCES);
            this.sources = sources;
            return this;
        }

        public JavaToolArgs setSources(JavaSource... sources) {
            return setSources(Arrays.asList(sources));
        }

        public JavaToolArgs setSources(String... sources) {
            List<JavaSource> javaSrcs = new ArrayList<>();
            for (String source : sources) {
                javaSrcs.add(new JavaSource(source));
            }
            return setSources(javaSrcs);
        }
    }

    
    public static class AnyToolArgs extends GenericArgs<AnyToolArgs> {

        static {
            minAcceptedParams = new ArrayList<>();
            minAcceptedParams.add(EnumSet.<AcceptedParams>of(
                    AcceptedParams.EXPECT, AcceptedParams.OPTIONS));
        }

        Map<String, String> extraEnv;

        public AnyToolArgs() {
            super();
        }

        public AnyToolArgs(Expect whatToExpt) {
            set(whatToExpt);
        }

        public AnyToolArgs set(Map<String, String> extraEnv) {
            currentParams.add(AcceptedParams.EXTRA_ENV);
            this.extraEnv = extraEnv;
            return this;
        }
    }

    
    public static class CommandExecutionException extends Exception {
        CommandExecutionException(List<String> command, Expect whatToExpt) {
            super(createMessage(command, whatToExpt));
        }

        CommandExecutionException(Expect whatToExpt, String... command) {
            this(Arrays.asList(command), whatToExpt);
        }

        private static String createMessage(List<String> command, Expect whatToExpt) {
            StringBuilder sb = new StringBuilder().append("Command : ");
            sb.append(command.toString()).append(lineSeparator);
            switch (whatToExpt) {
                case SUCCESS:
                    sb.append("    has unexpectedly failed");
                    break;
                case FAIL:
                    sb.append("    has been unexpectedly successful");
                    break;
            }
            return sb.toString();
        }
    }

    
    public static class ResourcesNotEqualException extends Exception {
        public ResourcesNotEqualException(List<String> res1, List<String> res2) {
            super(createMessage(res1, res2));
        }

        public ResourcesNotEqualException(String line1, String line2) {
            super(createMessage(line1, line2));
        }

        public ResourcesNotEqualException(Path path1, Path path2) {
            super(createMessage(path1, path2));
        }

        private static String createMessage(Path path1, Path path2) {
            return new StringBuilder()
                    .append("The resources provided for comparison in paths \n")
                    .append(path1.toString()).append(" and \n")
                    .append(path2.toString()).append("are different").toString();
        }

        private static String createMessage(String line1, String line2) {
            return new StringBuilder()
                    .append("The resources provided for comparison are different at lines: \n")
                    .append(line1).append(" and \n")
                    .append(line2).toString();
        }

        private static String createMessage(List<String> res1, List<String> res2) {
            return new StringBuilder()
                    .append("The resources provided for comparison are different: \n")
                    .append("Resource 1 is: ").append(res1).append("\n and \n")
                    .append("Resource 2 is: ").append(res2).append("\n").toString();
        }
    }

    
    public static int javac(JavaToolArgs params)
            throws CommandExecutionException, IOException {
        if (params.hasMinParams()) {
            if (params.argsArr != null) {
                return genericJavaCMD(JavaCMD.JAVAC, params);
            } else {
                return genericJavaCMD(JavaCMD.JAVAC_API, params);
            }
        }
        throw new AssertionError("javac command has been invoked with less parameters than needed");
    }

    
    public static String javap(JavaToolArgs params)
            throws CommandExecutionException, IOException {
        if (params.hasMinParams()) {
            List<String> list = new ArrayList<>();
            params.setErrOutput(list);
            genericJavaCMD(JavaCMD.JAVAP, params);
            return listToString(list);
        }
        throw new AssertionError("javap command has been invoked with less parameters than needed");
    }

    
    public static int javah(JavaToolArgs params)
            throws CommandExecutionException, IOException {
        if (params.hasMinParams()) {
            return genericJavaCMD(JavaCMD.JAVAH, params);
        }
        throw new AssertionError("javah command has been invoked with less parameters than needed");
    }

    
    enum JavaCMD {
        JAVAC {
            @Override
            int run(JavaToolArgs params, PrintWriter pw) {
                return com.sun.tools.javac.Main.compile(params.argsArr, pw);
            }
        },
        JAVAC_API {
            @Override
            int run(JavaToolArgs params, PrintWriter pw) {
                JavacTask ct = (JavacTask)comp.getTask(pw, null, null,
                        params.args, null, params.sources);
                return ((JavacTaskImpl)ct).doCall().exitCode;
            }

            @Override
            String getName() {
                return "javac";
            }

            @Override
            List<String> getExceptionMsgContent(JavaToolArgs params) {
                List<String> result = super.getExceptionMsgContent(params);
                for (JavaFileObject source : params.sources) {
                    if (source instanceof JavaSource) {
                        result.add(((JavaSource)source).name);
                    }
                }
                return result;
            }
        },
        JAVAH {
            @Override
            int run(JavaToolArgs params, PrintWriter pw) {
                return com.sun.tools.javah.Main.run(params.argsArr, pw);
            }
        },
        JAVAP {
            @Override
            int run(JavaToolArgs params, PrintWriter pw) {
                return com.sun.tools.javap.Main.run(params.argsArr, pw);
            }
        };

        abstract int run(JavaToolArgs params, PrintWriter pw);

        String getName() {
            return this.name().toLowerCase();
        }

        List<String> getExceptionMsgContent(JavaToolArgs params) {
            List<String> result = new ArrayList<>();
            result.add(getName());
            result.addAll(params.argsArr != null ?
                    Arrays.asList(params.argsArr) :
                    params.args);
            return result;
        }
    }

    
    private static int genericJavaCMD(
            JavaCMD cmd,
            JavaToolArgs params)
            throws CommandExecutionException, IOException {
        int rc = 0;
        StringWriter sw = null;
        try (PrintWriter pw = (params.errOutput == null) ?
                null : new PrintWriter(sw = new StringWriter())) {
            rc = cmd.run(params, pw);
        }
        String out = (sw == null) ? null : sw.toString();

        if (params.errOutput != null && (out != null) && !out.isEmpty()) {
            params.errOutput.addAll(splitLines(out, lineSeparator));
        }

        if ( (rc == 0 && params.whatToExpect == Expect.SUCCESS) ||
             (rc != 0 && params.whatToExpect == Expect.FAIL) ) {
            return rc;
        }

        throw new CommandExecutionException(cmd.getExceptionMsgContent(params),
                params.whatToExpect);
    }

    
    public static boolean jar(String... params) throws CommandExecutionException {
        Main jarGenerator = new Main(System.out, System.err, "jar");
        boolean result = jarGenerator.run(params);
        if (!result) {
            List<String> command = new ArrayList<>();
            command.add("jar");
            command.addAll(Arrays.asList(params));
            throw new CommandExecutionException(command, Expect.SUCCESS);
        }
        return result;
    }

    
    public static int executeCommand(AnyToolArgs params)
            throws CommandExecutionException, IOException, InterruptedException {
        if (params.hasMinParams()) {
            List<String> cmd = (params.args != null) ?
                    params.args :
                    Arrays.asList(params.argsArr);
            return executeCommand(cmd, params.extraEnv, params.stdOutput,
                    params.errOutput, params.whatToExpect);
        }
        throw new AssertionError("command has been invoked with less parameters than needed");
    }

    
    private static int executeCommand(
            List<String> command,
            Map<String, String> extraEnv,
            WriterHelper stdOutput,
            WriterHelper errOutput,
            Expect whatToExpt)
            throws IOException, InterruptedException, CommandExecutionException {
        ProcessBuilder pb = new ProcessBuilder(command);

        if (stdOutput != null) stdOutput.pipeOutput(pb);
        if (errOutput != null) errOutput.pipeOutput(pb);

        if (extraEnv != null) {
            pb.environment().putAll(extraEnv);
        }

        Process p = pb.start();

        if (stdOutput != null) stdOutput.readFromStream(p);
        if (errOutput != null) errOutput.readFromStream(p);

        int result = p.waitFor();
        if ( (result == 0 && whatToExpt == Expect.SUCCESS) ||
             (result != 0 && whatToExpt == Expect.FAIL) ) {
            return result;
        }

        throw new CommandExecutionException(command, whatToExpt);
    }

    
    public static void compareLines(Path aPath, Path otherPath, String encoding)
            throws FileNotFoundException, IOException, ResourcesNotEqualException {
        compareLines(aPath, otherPath, encoding, false);
    }

    public static void compareLines(
            Path aPath, Path otherPath, String encoding, boolean trim)
            throws FileNotFoundException, IOException, ResourcesNotEqualException {
        Charset charset = encoding != null ?
                Charset.forName(encoding) :
                defaultCharset;
        List<String> list1 = Files.readAllLines(aPath, charset);
        List<String> list2 = Files.readAllLines(otherPath, charset);
        compareLines(list1, list2, trim);
    }

    public static void compareLines(Path path, List<String> strings, String encoding)
            throws FileNotFoundException, IOException, ResourcesNotEqualException {
        compareLines(path, strings, encoding, false);
    }

    public static void compareLines(Path path, List<String> strings,
            String encoding, boolean trim)
            throws FileNotFoundException, IOException, ResourcesNotEqualException {
        Charset charset = encoding != null ?
                Charset.forName(encoding) :
                defaultCharset;
        List<String> list = Files.readAllLines(path, charset);
        compareLines(list, strings, trim);
    }

    public static void compareLines(List<String> list1, List<String> list2)
            throws ResourcesNotEqualException {
        compareLines(list1, list2, false);
    }

    public static void compareLines(List<String> list1,
            List<String> list2, boolean trim) throws ResourcesNotEqualException {
        if ((list1 == list2) || (list1 == null && list2 == null)) return;
        if (list1.size() != list2.size())
            throw new ResourcesNotEqualException(list1, list2);
        int i = 0;
        int j = 0;
        while (i < list1.size() &&
               j < list2.size() &&
               equals(list1.get(i), list2.get(j), trim)) {
            i++; j++;
        }
        if (!(i == list1.size() && j == list2.size()))
            throw new ResourcesNotEqualException(list1, list2);
    }

    private static boolean equals(String s1, String s2, boolean trim) {
        return (trim ? s1.trim().equals(s2.trim()) : s1.equals(s2));
    }

    
    public static List<String> grep(String regExpr, String text, String sep) {
        return grep(regExpr, splitLines(text, sep));
    }

    public static List<String> grep(String regExpr, List<String> text) {
        List<String> result = new ArrayList<>();
        Pattern pattern = Pattern.compile(regExpr);
        for (String s : text) {
            if (pattern.matcher(s).find()) {
                result.add(s);
            }
        }
        return result;
    }

    public static List<String> grep(String regExpr, File f)
            throws IOException {
        List<String> lines = Files.readAllLines(f.toPath(), defaultCharset);
        return grep(regExpr, lines);
    }

    
    public static boolean touch(String fileName) {
        File file = new File(fileName);
        return touch(file);
    }

    public static boolean touch(File file) {
        if (file.exists()) {
            file.setLastModified(System.currentTimeMillis());
            return true;
        }
        return false;
    }

    public static void createJavaFile(File outFile) throws IOException {
        createJavaFile(outFile, null);
    }

    
    public static void createJavaFile(File outFile, File superClass)
            throws IOException {
        String srcStr = "public class " + getSimpleName(outFile) + " ";
        if (superClass != null) {
            srcStr = srcStr.concat("extends " + getSimpleName(superClass) + " ");
        }
        srcStr = srcStr.concat("{}");
        try (PrintWriter ps = new PrintWriter(new FileWriter(outFile))) {
            ps.println(srcStr);
        }
    }

    
    public static void createJavaFileFromSource(String source) throws IOException {
        createJavaFileFromSource(null, source);
    }

    
    public static void createJavaFileFromSource(Path initialPath,
            String source) throws IOException {
        String fileName = getJavaFileNameFromSource(source);
        String dirTree = getDirTreeFromSource(source);
        Path path = (dirTree != null) ?
                Paths.get(dirTree, fileName) :
                Paths.get(fileName);
        path = (initialPath != null) ?
                initialPath.resolve(path):
                path;
        writeFile(path, source);
    }

    static Pattern publicClassPattern =
            Pattern.compile("public\\s+(?:class|enum|interface){1}\\s+(\\w+)");
    static Pattern packageClassPattern =
            Pattern.compile("(?:class|enum|interface){1}\\s+(\\w+)");

    
    private static String getJavaFileNameFromSource(String source) {
        String className = null;
        Matcher matcher = publicClassPattern.matcher(source);
        if (matcher.find()) {
            className = matcher.group(1) + ".java";
        } else {
            matcher = packageClassPattern.matcher(source);
            if (matcher.find()) {
                className = matcher.group(1) + ".java";
            } else {
                throw new AssertionError("Could not extract the java class " +
                        "name from the provided source");
            }
        }
        return className;
    }

    static Pattern packagePattern =
            Pattern.compile("package\\s+(((?:\\w+\\.)*)(?:\\w+))");

    
    private static String getDirTreeFromSource(String source) {
        Matcher matcher = packagePattern.matcher(source);
        return matcher.find() ?
            matcher.group(1).replace(".", File.separator) :
            null;
    }

    
    public static void mkManifestWithClassPath(String mainClass,
            String... classes) throws IOException {
        List <String> lines = new ArrayList<>();

        StringBuilder sb = new StringBuilder("Class-Path: ".length() +
                classes[0].length()).append("Class-Path: ").append(classes[0]);
        for (int i = 1; i < classes.length; i++) {
            sb.append(" ").append(classes[i]);
        }
        lines.add(sb.toString());
        if (mainClass != null) {
            lines.add(new StringBuilder("Main-Class: ".length() +
                      mainClass.length())
                      .append("Main-Class: ")
                      .append(mainClass).toString());
        }
        Files.write(Paths.get("MANIFEST.MF"), lines, null);
    }

    
    static String getSimpleName(File inFile) {
        return inFile.toPath().getFileName().toString();
    }

    
    public static File writeFile(Path path, String body) throws IOException {
        File result;
        if (path.getParent() != null) {
            Files.createDirectories(path.getParent());
        }
        try (FileWriter out = new FileWriter(result = path.toAbsolutePath().toFile())) {
            out.write(body);
        }
        return result;
    }

    public static File writeFile(String path, String body) throws IOException {
        return writeFile(Paths.get(path), body);
    }

    
    public static void rm(Path path) throws Exception {
        Files.deleteIfExists(path);
    }

    public static void rm(String filename) throws Exception {
        rm(Paths.get(filename));
    }

    public static void rm(File f) throws Exception {
        rm(f.toPath());
    }

    
    public static void copyFile(File destfile, File srcfile)
        throws IOException {
        copyFile(destfile.toPath(), srcfile.toPath());
    }

    public static void copyFile(Path destPath, Path srcPath)
        throws IOException {
        Files.createDirectories(destPath);
        Files.copy(srcPath, destPath, REPLACE_EXISTING);
    }

    
    public static List<String> splitLines(String lines, String sep) {
        return Arrays.asList(lines.split(sep));
    }

    
    private static String listToString(List<String> lines) {
        StringBuilder sb = new StringBuilder();
        for (String s : lines) {
            sb.append(s).append(lineSeparator);
        }
        return sb.toString();
    }

    
    public static boolean isWindows() {
        String osName = System.getProperty("os.name");
        return osName.toUpperCase().startsWith("WINDOWS");
    }

    
    public static class JavaSource extends SimpleJavaFileObject {
        String source;
        String name;

        public JavaSource(String className, String source) {
            super(URI.create(className),
                    JavaFileObject.Kind.SOURCE);
            this.name = className;
            this.source = source;
        }

        public JavaSource(String source) {
            super(URI.create(getJavaFileNameFromSource(source)),
                    JavaFileObject.Kind.SOURCE);
            this.name = getJavaFileNameFromSource(source);
            this.source = source;
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return source;
        }
    }
}
