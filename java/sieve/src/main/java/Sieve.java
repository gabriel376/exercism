import java.util.List;
import java.util.ArrayList;
import java.util.BitSet;

class Sieve {
    private int limit;

    Sieve(int limit) {
        this.limit = limit;
    }

    List<Integer> getPrimes() {
        BitSet bits = new BitSet();
        List<Integer> list = new ArrayList<Integer>();

        for (int i = 2; i <= limit; i++) {
            if (!bits.get(i)) {
                list.add(i);
            }
            for (int j = i+i; j <= limit; j+=i) {
                bits.set(j);
            }
        }

        return list;
    }
}
