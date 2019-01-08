const clone = data => JSON.parse(JSON.stringify(data));

export default class Zipper {
    static fromTree(tree, parent = null) {
        return tree
            ? new Zipper(parent ? tree : clone(tree), parent)
            : null;
    }

    constructor(tree, parent) {
        this.tree =  tree;
        this.parent =  parent;
    }

    toTree() {
        return this.parent
            ? this.parent.toTree()
            : this.tree;
    }

    value() {
        return this.tree.value;
    }

    left() {
        return Zipper.fromTree(this.tree.left, this);
    }

    right() {
        return Zipper.fromTree(this.tree.right, this);
    }

    up() {
        return this.parent;
    }

    setValue(value) {
        this.tree.value = value;
        return this;
    }

    setLeft(left) {
        this.tree.left = left;
        return this;
    }

    setRight(right) {
        this.tree.right = right;
        return this;
    }
};
