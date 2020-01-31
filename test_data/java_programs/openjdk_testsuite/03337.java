
class RepeatedStringCaseLabels1 {
    String m(String s) {
        switch(s) {
        case "Hello World":
            return(s);
        case "Hello" + " " + "World":
            return (s + s);
        }
    }
}
