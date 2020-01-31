

public class MissingInterfaceTestDep implements Intermediate {}
interface Intermediate extends Closeable { }
interface Closeable {}
