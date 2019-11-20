export class InvalidInputError extends Error {

}

export class Robot {
    orient(direction) {
        if (!['east', 'west', 'north', 'south'].includes(direction))
            throw new InvalidInputError();
        this.direction = direction;
    }

    get bearing() {
        return this.direction;
    }

    get coordinates() {
        return [this.x, this.y];
    }

    turnRight() {
        switch (this.bearing) {
        case 'east':
            return this.orient('south');
        case 'west':
            return this.orient('north');
        case 'north':
            return this.orient('east');
        case 'south':
            return this.orient('west');
        }
    }

    turnLeft() {
        switch (this.bearing) {
        case 'east':
            return this.orient('north');
        case 'west':
            return this.orient('south');
        case 'north':
            return this.orient('west');
        case 'south':
            return this.orient('east');
        }
    }

    at(x, y) {
        this.x = x;
        this.y = y;
    }

    advance() {
        switch (this.bearing) {
        case 'east':
            return this.at(this.x + 1, this.y);
        case 'west':
            return this.at(this.x - 1, this.y);
        case 'north':
            return this.at(this.x, this.y + 1);
        case 'south':
            return this.at(this.x, this.y - 1);
        }
    }

    static instructions(command) {
        return [...command].map(command => {
            switch (command) {
            case 'R':
                return new Robot().turnRight.name;
            case 'L':
                return new Robot().turnLeft.name;
            case 'A':
                return new Robot().advance.name;
            }
        });
    }

    place({x, y, direction}) {
        this.at(x, y);
        this.orient(direction);
    }

    evaluate(commands) {
        Robot.instructions(commands).forEach(command => this[command]());
    }
}
