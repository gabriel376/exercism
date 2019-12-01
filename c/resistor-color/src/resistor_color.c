#include "resistor_color.h"

static const resistor_band_t COLORS[] = {
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
};

const resistor_band_t* colors() {
    return COLORS;
}

int color_code(resistor_band_t resistor_band) {
    return resistor_band;
}
