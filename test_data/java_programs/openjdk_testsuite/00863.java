



public enum SynthValues {
    red, blue, green;
    SynthValues[] $VALUES = null; 
    public static void main(String[] args) {
        for (SynthValues t : values()) {
            System.out.println(t);
        }
    }
}
