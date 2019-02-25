import java.util.Map;

class RaindropConverter {
    private Map<Integer, String> DROPS = Map.of(
        3, "Pling",
        5, "Plang",
        7, "Plong");

    String convert(int number) {
        return DROPS
            .keySet()
            .stream()
            .sorted()
            .filter(key -> number % key == 0)
            .map(DROPS::get)
            .reduce(String::concat)
            .orElse(Integer.toString(number));
   }
}
