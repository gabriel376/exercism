import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Collectors;
import java.util.Collections;
import java.util.BitSet;

class HandshakeCalculator {
    List<Signal> calculateHandshake(int number) {
        Signal[] signals = Signal.values();
        BitSet bits = BitSet.valueOf(new long[] { number });

        List<Signal> handshake = IntStream.range(0, signals.length)
            .filter(bits::get)
            .mapToObj(i -> signals[i])
            .collect(Collectors.toList());

        if (bits.get(signals.length)) {
            Collections.reverse(handshake);
        }

        return handshake;
    }
}
