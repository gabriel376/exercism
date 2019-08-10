class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

export class LinkedList {
    constructor() {
        this.head = new Node(null);
    }

    push(value) {
        let node = this.head;
        while (node.next) {
            node = node.next;
        }
        node.next = new Node(value);
    }

    pop() {
        let node = this.head;
        while (node.next && node.next.next) {
            node = node.next;
        }
        let value =  node.next.value;
        node.next = null;
        return value;
    }

    shift() {
        let value = this.head.next.value;
        this.head.next = this.head.next.next;
        return value;
    }

    unshift(value) {
        let node = this.head.next;
        this.head.next = new Node(value);
        this.head.next.next = node;
    }

    delete(value) {
        let node = this.head;
        while (node.next) {
            if (node.next.value == value) {
                node.next = node.next.next;
                return;
            }
            node = node.next;
        }
    }

    count() {
        let total = 0;
        let node = this.head;
        while (node.next) {
            node = node.next;
            total += 1;
        }
        return total;
    }
}
