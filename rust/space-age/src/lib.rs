#[derive(Debug)]
pub struct Duration {
    seconds: f64,
}

impl From<u64> for Duration {
    fn from(s: u64) -> Self {
        Duration {
            seconds: s as f64
        }
    }
}

pub trait Planet {
    const BASE_PERIOD: f64 = 365.25 * 24.0 * 60.0 * 60.0;
    const ORBITAL_PERIOD: f64 = 1.0;

    fn years_during(d: &Duration) -> f64 {
        d.seconds / (Self::BASE_PERIOD * Self::ORBITAL_PERIOD)
    }
}

pub struct Mercury;
pub struct Venus;
pub struct Earth;
pub struct Mars;
pub struct Jupiter;
pub struct Saturn;
pub struct Uranus;
pub struct Neptune;

impl Planet for Mercury {
    const ORBITAL_PERIOD: f64 = 0.2408467;
}

impl Planet for Venus {
    const ORBITAL_PERIOD: f64 = 0.61519726;
}

impl Planet for Earth {
    const ORBITAL_PERIOD: f64 = 1.0;
}

impl Planet for Mars {
    const ORBITAL_PERIOD: f64 = 1.8808158;
}

impl Planet for Jupiter {
    const ORBITAL_PERIOD: f64 = 11.862615;
}

impl Planet for Saturn {
    const ORBITAL_PERIOD: f64 = 29.447498;
}

impl Planet for Uranus {
    const ORBITAL_PERIOD: f64 = 84.016846;
}

impl Planet for Neptune {
    const ORBITAL_PERIOD: f64 = 164.79132;
}