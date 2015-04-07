#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define EPS 1e-9

// Represents a point (x,y) coord
struct point {
  double x, y;

  // Constructors
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}

  bool operator < (point other) const {
    if(fabs(x-other.x) > EPS)
      return x < other.x;
    return y < other.y;
  }

  bool operator == (point other) const {
    return (fabs(x - other.x) < EPS && (fabs(y- other.y) < EPS));
  }
};

// Store a line
struct line { double a, b, c; };

// Euclidean Dist
double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

// Build a line from 2 points
void pointsToLine(point p1, point p2, line &l) {
  if(fabs(p1.x - p2.x) < EPS) {
    l.a = 1.0; l.b = 0.0; l.c = -p1.x;
  } else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;
    l.c = -(double)(l.a * p1.x) - p1.y;
  }
}

// Get closest point on line l w.r.t to point p
void closestPoint(line l, point p, point &ans) {
  if (fabs(l.b) < EPS) {      // special case 1: vertical line
    ans.x = -(l.c);
    ans.y = p.y;
    return;
  }

  if (fabs(l.a) < EPS) {      // special case 2: horizontal line
    ans.x = p.x;
    ans.y = -(l.c);
    return;
  }

  ans.x = -(l.b * p.y + l.c) / l.a;
  ans.y = p.y;
}

typedef vector<point> vp;

int main() {
  int cases;
  cin >> cases;

  while(cases--) {
    int n;
    cin >> n;

    if(n < 2) {
      cout << "0.00" << endl; // Lower bound not specified
      continue;
    }

    vp points;
    double x,y;

    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      points.push_back(point(x,y));
    }

    // Sort the points
    sort(points.begin(), points.end());

    // Calculate the distance
    double sum_dist = 0.0;

    // point prev = points[n-1];
    // point last = points[n-2];
    // sum_dist += dist(prev, last);

    double temp, m, c;
    double highest = 0.0;
      for(int j = 1 ; j < n ; j++ ){
        if( points[j].y > highest ){
          m = (points[j].y-points[j-1].y)/(points[j].x-points[j-1].x);
          c = points[j].y - m*points[j].x;
          temp = (highest-c)/m;
          sum_dist += dist(points[j], point(temp, highest));
          highest = points[j].y;
        }
      }

    // cout << "last: " << last.x << ", " << last.y << endl;
    // cout << "prev: " << prev.x << ", " << prev.y << endl;
    // cout << endl;

    // for(int i = points.size() - 3; i >= 0; --i) {
    //   point current = points[i];

    //   // // We want the next point with greater y
    //   if(current.y <= last.y) {
    //     cout << "skipping: " << current.x << ", " << current.y << endl;
    //     prev = current;
    //     continue;
    //   }

    //   cout << "last: " << last.x << ", " << last.y << endl;
    //   cout << "prev: " << prev.x << ", " << prev.y << endl;
    //   cout << "current: " << current.x << ", " << current.y << endl;
    //   cout << endl;


    //   if(last == prev) {
    //     // Straight line calc.
    //     sum_dist += dist(last, current);
    //   } else {
    //     // Find point c on line(prev,current) w.r.t last
    //     line l;
    //     point c;

    //     pointsToLine(prev, current, l);
    //     closestPoint(l, last, c);

    //     // x = closest_point(l, last.y);
    //     // c.x=x; c.y=last.y;
    //     sum_dist += dist(c, current);
    //   }

    //   prev = current;
    //   last = current;
    // }

    // for (int i = 0; i < n; ++i) {
    //   cout << points[i].x << " " << points[i].y;
    //   cout << endl;
    // }
    cout << sum_dist << endl;
  }
  return 0;
}