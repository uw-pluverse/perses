





struct _NSPoint
{
  float x;
  float y;
};

typedef struct _NSPoint NSPoint;

static NSPoint
__attribute__ ((target("arm")))
NSMakePoint (float x, float y)
{
  NSPoint point;
  point.x = x;
  point.y = y;
  return point;
}

static NSPoint
__attribute__ ((target("thumb")))
RelativePoint (NSPoint point, NSPoint refPoint)
{
  return NSMakePoint (refPoint.x + point.x, refPoint.y + point.y);
}

NSPoint
__attribute__ ((target("arm")))
g(NSPoint refPoint)
{
  float pointA, pointB;
  return RelativePoint (NSMakePoint (0, pointA), refPoint);
}
