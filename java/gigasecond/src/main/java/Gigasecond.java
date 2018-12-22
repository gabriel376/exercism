import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;

class Gigasecond {

    private static final long GIGA = 1_000_000_000;
    private final LocalDateTime dateTime;    
        
    Gigasecond(LocalDate date) {
        this(date.atTime(0, 0));
    }

    Gigasecond(LocalDateTime dateTime) {
        this.dateTime = dateTime.plusSeconds(GIGA);
    }

    LocalDateTime getDateTime() {
        return dateTime;
    }
}
