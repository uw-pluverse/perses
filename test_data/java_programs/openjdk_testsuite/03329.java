
import static java.math.RoundingMode.*;

class BadlyTypedLabel2 {
    String m(String s) {
        switch(s) {
        case "Oh what a feeling...":
            return(s);
        case CEILING:
            return ("... switching on the ceiling!");
        }
    }
}
