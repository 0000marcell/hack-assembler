#ifndef POINT_H
#define POINT_H

typedef struct Point {
  double x;
  double y;
} Point;

Point Point_value(double x, double y);

void Point_print(Point *self);

#endif
