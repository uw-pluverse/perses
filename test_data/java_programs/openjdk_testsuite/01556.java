

import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


class MessageFile {
    static final Pattern emptyOrCommentPattern = Pattern.compile("( *#.*)?");
    static final Pattern infoPattern = Pattern.compile("# ([0-9]+: [-A-Za-z ]+, )*[0-9]+: [-A-Za-z ]+");

    
    class Line {
        String text;
        Line prev;
        Line next;

        Line(String text) {
            this.text = text;
        }

        boolean isEmptyOrComment() {
            return emptyOrCommentPattern.matcher(text).matches();
        }

        boolean isInfo() {
            return infoPattern.matcher(text).matches();
        }

        boolean hasContinuation() {
            return (next != null) && text.endsWith("\\");
        }

        Line insertAfter(String text) {
            Line l = new Line(text);
            insertAfter(l);
            return l;
        }

        void insertAfter(Line l) {
            assert l.prev == null && l.next == null;
            l.prev = this;
            l.next = next;
            if (next == null)
                lastLine = l;
            else
                next.prev = l;
            next = l;
        }

        Line insertBefore(String text) {
            Line l = new Line(text);
            insertBefore(l);
            return l;
        }

        void insertBefore(Line l) {
            assert l.prev == null && l.next == null;
            l.prev = prev;
            l.next = this;
            if (prev == null)
                firstLine = l;
            else
                prev.next = l;
            prev = l;
        }

        void remove() {
            if (prev == null)
                firstLine = next;
            else
                prev.next = next;
            if (next == null)
                lastLine = prev;
            else
                next.prev = prev;
            prev = null;
            next = null;
        }
    }

    
    static final class Message {
        final Line firstLine;
        private Info info;

        Message(Line l) {
            firstLine = l;
        }

        boolean needInfo() {
            Line l = firstLine;
            while (true) {
                if (l.text.matches(".*\\{[0-9]+\\}.*"))
                    return true;
                if (!l.hasContinuation())
                    return false;
                l = l.next;
            }
        }

        Set<Integer> getPlaceholders() {
            Pattern p = Pattern.compile("\\{([0-9]+)\\}");
            Set<Integer> results = new TreeSet<Integer>();
            Line l = firstLine;
            while (true) {
                Matcher m = p.matcher(l.text);
                while (m.find())
                    results.add(Integer.parseInt(m.group(1)));
                if (!l.hasContinuation())
                    return results;
                l = l.next;
            }
        }

        
        Info getInfo() {
            if (info == null) {
                Line l = firstLine.prev;
                if (l != null && l.isInfo())
                    info = new Info(l.text);
                else
                    info = new Info();
            }
            return info;
        }

        
        void setInfo(Info info) {
            this.info = info;
            Line l = firstLine.prev;
            if (l != null && l.isInfo())
                l.text = info.toComment();
            else
                firstLine.insertBefore(info.toComment());
        }

        
        List<Line> getLines(boolean includeAllPrecedingComments) {
            List<Line> lines = new ArrayList<Line>();
            Line l = firstLine;
            if (includeAllPrecedingComments) {
                
                while (l.prev != null && l.prev.isEmptyOrComment())
                    l = l.prev;
                
                while (l.text.isEmpty())
                    l = l.next;
            } else {
                if (l.prev != null && l.prev.isInfo())
                    l = l.prev;
            }

            
            for ( ; l != firstLine; l = l.next)
                lines.add(l);

            
            for (l = firstLine; l != null && l.hasContinuation(); l = l.next)
                lines.add(l);
            lines.add(l);

            
            l = l.next;
            if (l != null && l.text.isEmpty())
                lines.add(l);

            return lines;
        }
    }

    
    static final class Info {
        
        static class Field {
            boolean unused;
            Set<String> values;
            boolean listOfAny = false;
            boolean setOfAny = false;
            Field(String s) {
                s = s.substring(s.indexOf(": ") + 2);
                values = new LinkedHashSet<String>(Arrays.asList(s.split(" or ")));
                for (String v: values) {
                    if (v.startsWith("list of"))
                        listOfAny = true;
                    if (v.startsWith("set of"))
                        setOfAny = true;
                }
            }

            
            boolean contains(Field other) {
                if (unused != other.unused)
                    return false;

                for (String v: other.values) {
                    if (values.contains(v))
                        continue;
                    if (v.equals("null") || v.equals("string"))
                        continue;
                    if (v.equals("list") && listOfAny)
                        continue;
                    if (v.equals("set") && setOfAny)
                        continue;
                    return false;
                }
                return true;
            }

            
            void merge(Field other) {
                unused |= other.unused;
                values.addAll(other.values);

                

                if (values.contains("null") && values.size() > 1) {
                    
                    values.remove("null");
                }

                if (values.contains("string") && values.size() > 1) {
                    
                    values.remove("string");
                }

                if (values.contains("list")) {
                    
                    for (String s: values) {
                        if (s.startsWith("list of ")) {
                            values.remove("list");
                            break;
                        }
                    }
                }

                if (values.contains("set")) {
                    
                    for (String s: values) {
                        if (s.startsWith("set of ")) {
                            values.remove("set");
                            break;
                        }
                    }
                }

                if (other.values.contains("unused")) {
                    values.clear();
                    values.add("unused");
                }
            }

            void markUnused() {
                values = new LinkedHashSet<String>();
                values.add("unused");
                listOfAny = false;
                setOfAny = false;
            }

            @Override
            public String toString() {
                return values.toString();
            }
        }

        
        List<Field> fields = new ArrayList<Field>();

        Info() { }

        Info(String text) throws IllegalArgumentException {
            if (!text.startsWith("# "))
                throw new IllegalArgumentException();
            String[] segs = text.substring(2).split(", ");
            fields = new ArrayList<Field>();
            for (String seg: segs) {
                fields.add(new Field(seg));
            }
        }

        Info(Set<String> infos) throws IllegalArgumentException {
            for (String s: infos)
                merge(new Info(s));
        }

        boolean isEmpty() {
            return fields.isEmpty();
        }

        boolean contains(Info other) {
            if (other.isEmpty())
                return true;

            if (fields.size() != other.fields.size())
                return false;

            Iterator<Field> oIter = other.fields.iterator();
            for (Field values: fields) {
                if (!values.contains(oIter.next()))
                    return false;
            }

            return true;
        }

        void merge(Info other) {
            if (fields.isEmpty()) {
                fields.addAll(other.fields);
                return;
            }

            if (other.fields.size() != fields.size())
                throw new IllegalArgumentException();

            Iterator<Field> oIter = other.fields.iterator();
            for (Field d: fields) {
                d.merge(oIter.next());
            }
        }

        void markUnused(Set<Integer> used) {
            for (int i = 0; i < fields.size(); i++) {
                if (!used.contains(i))
                    fields.get(i).markUnused();
            }
        }

        @Override
        public String toString() {
            return fields.toString();
        }

        String toComment() {
            StringBuilder sb = new StringBuilder();
            sb.append("# ");
            String sep = "";
            int i = 0;
            for (Field f: fields) {
                sb.append(sep);
                sb.append(i++);
                sb.append(": ");
                sep = "";
                for (String s: f.values) {
                    sb.append(sep);
                    sb.append(s);
                    sep = " or ";
                }
                sep = ", ";
            }
            return sb.toString();
        }
    }

    Line firstLine;
    Line lastLine;
    Map<String, Message> messages = new TreeMap<String, Message>();

    MessageFile(File file) throws IOException {
        Reader in = new FileReader(file);
        try {
            read(in);
        } finally {
            in.close();
        }
    }

    MessageFile(Reader in) throws IOException {
        read(in);
    }

    final void read(Reader in) throws IOException {
        BufferedReader br = (in instanceof BufferedReader)
                ? (BufferedReader) in
                : new BufferedReader(in);
        String line;
        while ((line = br.readLine()) != null) {
            Line l;
            if (firstLine == null)
                l = firstLine = lastLine = new Line(line);
            else
                l = lastLine.insertAfter(line);
            if (line.startsWith("compiler.")) {
                int eq = line.indexOf("=");
                if (eq > 0)
                    messages.put(line.substring(0, eq), new Message(l));
            }
        }
    }

    void write(File file) throws IOException {
        Writer out = new FileWriter(file);
        try {
            write(out);
        } finally {
            out.close();
        }
    }

    void write(Writer out) throws IOException {
        BufferedWriter bw = (out instanceof BufferedWriter)
                ? (BufferedWriter) out
                : new BufferedWriter(out);
        for (Line l = firstLine; l != null; l = l.next) {
            bw.write(l.text);
            bw.write("\n"); 
        }
        bw.flush();
    }
}
