

class T7102515 {
    T7102515 badBinary = new T7102515() + new T7102515();
    Object badUnary = badBinary++;
}
