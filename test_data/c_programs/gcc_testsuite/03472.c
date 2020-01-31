typedef struct JSObject JSObject;
typedef struct JSObjectMap *(*JSNewObjectMapOp) (JSObject *obj);
typedef JSObject *(*JSGetMethodOp) (JSObject *obj);
struct JSObjectOps {
    JSNewObjectMapOp newObjectMap;
};
struct JSXMLObjectOps {
    struct JSObjectOps base;
    JSGetMethodOp getMethod;
};
struct JSObjectMap {
    struct JSObjectOps *ops;
};
struct JSObject {
    struct JSObjectMap *map;
};

struct JSXMLObjectOps js_XMLObjectOps;




JSObject *JS_GetMethod(JSObject *obj)
{
    if (obj->map->ops == &js_XMLObjectOps.base) {
        struct JSXMLObjectOps *ops;
        ops = (struct JSXMLObjectOps *) obj->map->ops;
        obj = ops->getMethod(obj);
    }
    return obj;
}
