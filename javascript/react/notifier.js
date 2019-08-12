import Notification from './notification.js';

export default class Notifier {
    constructor() {
        this.notifications = [];
    }

    on(evt, obj, func, args) {
        const notification = new Notification(evt, obj, func, args);
        if (!this.notifications.find(other => notification.equals(other))) {
            this.notifications.push(notification);
        }
    }

    cancel(evt, obj, func) {
        const notification = new Notification(evt, obj, func);
        const index = this.notifications.findIndex(other => notification.equals(other));
        if (index >= 0) {
            this.notifications.splice(index, 1);
        }
    }

    sequence(evt) {
        return this.notifications
            .filter(n => n.evt === evt)
            .reduce((arr, n) => arr.concat(n).concat(n.obj.Notifier.sequence(evt)), [])
            .filter((n, i, arr) => !arr.slice(i + 1).find(other => n.equals(other)));
    }

    notify(evt) {
        this.sequence(evt).forEach(n => n.fire());
    }
}
