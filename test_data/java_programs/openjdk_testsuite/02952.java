



import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class MethodRef5 {

    static class Person {

        private String firstName;
        private String lastName;
        private int age;

        public Person() { }

        public Person(String fn, String ln, int a) {
            firstName = fn;
            lastName = ln;
            age = a;
        }

        public String getLastName() {
            return lastName;
        }

        public int getAge() {
            return age;
        }

        
        public static int compareByAge(Person a, Person b) {
            return a.age - b.age;
        }

        public int compareByLastName(Person a, Person b) {
            return a.lastName.compareToIgnoreCase(b.lastName);
        }
    }

    private static void assertTrue(boolean cond) {
        if (!cond)
            throw new AssertionError();
    }

    public static void main(String[] args) {

        List<Person> persons = new ArrayList<Person>();
        persons.add(new Person("John", "Smith", 49));
        persons.add(new Person("Abraham", "Lincoln", 30));
        persons.add(new Person("George", "Washington", 29));
        persons.add(new Person("Peter", "Derby", 50));
        Collections.sort(persons, Person::compareByAge);
        String age = "";
        for (Person p : persons) {
            age += p.getAge() + " ";
        }
        assertTrue( (age.equals("29 30 49 50 ")) );
        Collections.sort(persons, new Person()::compareByLastName);
        String lastName = "";
        for (Person p : persons) {
            lastName += p.getLastName() + " ";
        }
        assertTrue( lastName.equals("Derby Lincoln Smith Washington ") );
    }
}
