class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
        this.previous = null;
    }
}

export class LinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    push(value) {
        let node = new Node(value);
        this.size++;

        if (this.size == 1) {
            this.head = node;
            this.tail = node;

        } else {
            node.previous = this.tail;
            this.tail.next = node;
            this.tail = node;
        }
    }

    pop() {
        let node = this.tail;
        this.size--;

        if (this.size == 0) {
            this.head = null;
            this.tail = null;

        } else {
            this.tail = this.tail.previous;
            this.tail.next = null;
        }

        return node.value;
    }

    shift() {
        let node = this.head;
        this.size--;

        if (this.size == 0) {
            this.head == null;
            this.tail == null;

        } else {
            this.head = this.head.next;
            this.head.previous = null;
        }

        return node.value;
    }

    unshift(value) {
        let node = new Node(value);
        this.size++;

        if (this.size == 1) {
            this.head = node;
            this.tail = node;

        } else {
            node.next = this.head;
            this.head.previous = node;
            this.head = node;
        }
    }

    delete(value) {
        let node = this.head;

        while (node && node.value != value) {
            node = node.next;
        }

        if (!node) {
            return;
        }

        if (this.size == 1) {
            this.head = null;
            this.tail = null;

        } else if (node == this.head) {
            node.previous = null;
            this.head = node.next;

        } else if (node == this.tail) {
            node.next = null;
            this.tail = node.previous;

        } else {
            node.next.previous = node.previous;
            node.previous.next = node.next;
        }

        this.size--;
    }

    count() {
        return this.size;
    }
}
