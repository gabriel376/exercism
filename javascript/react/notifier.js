export default class Notifier {
    constructor() {
        this.notifications = [];
    }

    on(event, obj, func, params) {
        let index = this.notifications.findIndex(n => n.event == event && n.obj == obj && n.func == func);
        if (index >= 0) return;
        this.notifications.push({
            event: event,
            obj: obj,
            func: func,
            params: params,
        });
    }

    cancel(event, obj, func) {
        let index = this.notifications.findIndex(n => n.event == event && n.obj == obj && n.func == func);
        if (index < 0) return;
        this.notifications.splice(index, 1);
    }

    sequence(event) {
        return this.notifications
            .filter(n => n.event == event)
            .reduce((arr, n) => arr.concat(n).concat(n.obj.Notifier.sequence(event)), [])
            .filter((n, i, arr) => !arr.slice(i + 1).find(x => x.obj == n.obj && x.func == n.func));
    }

    notify(event) {
        this.sequence(event).forEach(n => {
            n.obj[n.func](n.params());
        });
    }
};
