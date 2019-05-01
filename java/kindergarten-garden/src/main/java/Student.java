import java.util.List;

public class Student {
    private static List<String> students =
        List.of("Alice", "Bob", "Charlie",
                "David", "Eve", "Fred",
                "Ginny", "Harriet", "Ileana",
                "Joseph", "Kincaid", "Larry");

    static long getStart(String student) {
        return students.indexOf(student) * getCups();
    }

    static long getCups() {
        return 2;
    }
}
