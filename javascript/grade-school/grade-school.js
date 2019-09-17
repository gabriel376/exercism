export class GradeSchool {
    constructor() {
        this.DB = {};
    }

    roster() {
        return Object.keys(this.DB)
            .reduce((copy, grade) => {
                copy[grade] = this.grade(grade);
                return copy;
            }, {});
    }

    add(name, grade) {
        this.DB[grade] = this.grade(grade).concat(name).sort();
    }

    grade(grade) {
        return Object.assign([], this.DB[grade]);
    }
}
