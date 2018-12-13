class Year {
	constructor(y) {
		this.year = y;
	}
	isLeap(y) {
		return (this.year % 4 === 0 && this.year % 100 !== 0) || this.year % 400 === 0;
	}
}

export default Year;