

package org.openjdk.tests.shapegen;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.io.IOException;
import java.io.StringReader;

import static java.lang.Character.isLetter;
import static java.lang.Character.isUpperCase;
import static java.lang.Character.isWhitespace;


public class TTParser extends StringReader {

    private Map<Character, TTNode> letterMap = new HashMap<>();
    private char ch;

    private final String def;

    public TTParser(String s) {
        super(s);
        this.def = s;
    }

    private void advance() throws IOException {
        do {
            ch = (char)read();
        } while (isWhitespace(ch));
    }

    public TTNode parse() {
        try {
            advance();
            return classDef();
        } catch (IOException t) {
            throw new RuntimeException(t);
        }
    }

    private TTNode classDef() throws IOException {
        if (!isLetter(ch)) {
            if (ch == (char)-1) {
                throw new IOException("Unexpected end of type template in " + def);
            } else {
                throw new IOException("Unexpected character in type template: " + (Character)ch + " in " + def);
            }
        }
        char nodeCh = ch;
        TTNode node = letterMap.get(nodeCh);
        boolean canBeClass = isUpperCase(nodeCh);
        advance();
        if (node == null) {
            List<TTNode> subtypes = new ArrayList<>();
            if (ch == '(') {
                advance();
                while (ch != ')') {
                    subtypes.add(classDef());
                }
                advance();
            }
            node = new TTNode(subtypes, canBeClass);
            letterMap.put(nodeCh, node);
        }
        return node;
    }
}
