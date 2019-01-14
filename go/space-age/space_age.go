package space

// Planet defines a planet name
type Planet string

const earthYear = 365.25 * 24 * 60 * 60

var yearOn = map[Planet]float64{
	"Earth":   1,
	"Mercury": 0.2408467,
	"Venus":   0.61519726,
	"Mars":    1.8808158,
	"Jupiter": 11.862615,
	"Saturn":  29.447498,
	"Uranus":  84.016846,
	"Neptune": 164.79132,
}

// Age calculates how old someone is on a given planet.
func Age(seconds float64, planet Planet) float64 {
	return seconds / (earthYear * yearOn[planet])
}
