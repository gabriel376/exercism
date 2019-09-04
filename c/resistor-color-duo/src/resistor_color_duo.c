#include "resistor_color_duo.h"

int colorCode(resistor_band_t bands[]) {
    return 10*bands[0] + bands[1];
}
