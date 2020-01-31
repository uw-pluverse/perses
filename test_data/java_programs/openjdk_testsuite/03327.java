
class RepeatedStringCaseLabels2 {
    String m(String s) {
        final String constant = "Hello" + " " + "World";
        switch(s) {
        case "Hello World":
            return(s);
        case constant:
            return (s + s);
        }
    }
}
