
class BadlyTypedLabel1 {
    String m(String s) {
        switch(s) {
        case "Hello World":
            return(s);
        case 42:
            return ("Don't forget your towel!");
        }
    }
}
