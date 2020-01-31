
class NonConstantLabel {
    String m(String s) {
        String fauxConstant = "Goodbye Cruel World";
        switch(s) {
        case "Hello World":
            return(s);
        case fauxConstant:
            return (s + s);
        }
    }
}
