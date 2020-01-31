enum kobject_action {
        KOBJ_ADD,
        KOBJ_REMOVE,
        KOBJ_CHANGE,
        KOBJ_MOVE,
        KOBJ_ONLINE,
        KOBJ_OFFLINE,
        KOBJ_MAX
};
struct kobject;
int kobject_uevent(struct kobject *kobj, enum kobject_action action) {}
