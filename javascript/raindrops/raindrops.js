let DROPS = {
    3: 'Pling',
    5: 'Plang',
    7: 'Plong',
};

export default class Raindrops {
    convert(drops) {
        let getSound = (a, k) => drops % k == 0 ? a + DROPS[k] : a;
        return Object.keys(DROPS).reduce(getSound, '') || String(drops);
    }
};

