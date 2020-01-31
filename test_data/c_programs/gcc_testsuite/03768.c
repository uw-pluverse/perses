



struct _NSPoint
{
  float x;
  float y;
};

typedef struct _NSPoint NSPoint;

static inline NSPoint
NSMakePoint (float x, float y)
{
  NSPoint point;
  point.x = x;
  point.y = y;
  return point;
}

static inline NSPoint
RelativePoint (NSPoint point, NSPoint refPoint)
{
  return NSMakePoint (refPoint.x + point.x, refPoint.y + point.y);
}

NSPoint g(NSPoint refPoint)
{
  float pointA, pointB;
  return RelativePoint (NSMakePoint (0, pointA), refPoint);
}
