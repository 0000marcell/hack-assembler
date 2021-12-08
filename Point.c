#include <stdio.h>
#include "Point.h"

Point Point_value(double x, double y)
{
  Point initialzed = { x, y };
  return initialzed;
}

void Point_print(Point *self)
{
  printf("(%f, %f)\n", self->x, self->y);
}
