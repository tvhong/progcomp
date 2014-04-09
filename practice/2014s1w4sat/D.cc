#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

#define x first
#define y second
using namespace std;
const double EPS = 1e-4;
typedef pair<double, double> Point;

Point p[4];
Point center;
double A1, B1, C1, A2, B2, C2;
pair<double, double> res[4];

double length(Point a, Point b) {
  return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main() {
  for (int i=0; i<4; i++)
    cin >> p[i].x >> p[i].y;
  while (!(abs(p[0].x) < EPS && abs(p[0].y) < EPS &&
      abs(p[1].x) < EPS && abs(p[1].y) < EPS &&
      abs(p[2].x) < EPS && abs(p[2].y) < EPS &&
      abs(p[3].x) < EPS && abs(p[3].y) < EPS)) {

    A1 = p[0].y - p[2].y;
    B1 = p[2].x - p[0].x;
    C1 = A1*p[0].x + B1*p[0].y;

    A2 = p[1].y - p[3].y;
    B2 = p[3].x - p[1].x;
    C2 = A2*p[1].x + B2*p[1].y;

    if (A1*B2 - B1*A2 == 0) {
      printf("0.000 0.000 0.000 0.000 0.000 0.000\n");
      for (int i=0; i<4; i++)
        cin >> p[i].x >> p[i].y;
      continue;
    }
    double det = 1.0/(A1*B2 - B1*A2);
    center.x = det*(C1*B2 - C2*B1);
    center.y = det*(A1*C2 - A2*C1);
    //cout << "center=(" << center.x << "," << center.y << ")" << endl;

    for (int i=0; i<4; i++) {
      int j = (i+1)%4;
      double len[3] = {length(p[i], p[j]), length(p[i], center), length(p[j], center)};
      res[i].second = (len[0] + len[1] + len[2]);
      //double s =  res[i].second / 2.0;
      //res[i].first = sqrt(s*(s - len[0])*(s-len[1])*(s-len[2]));
      double x1 = center.x - p[i].x;
      double y1 = center.y - p[i].y;
      double x2 = center.x - p[j].x;
      double y2 = center.y - p[j].y;
      res[i].first = abs(x1*y2 - x2*y1)/2.0;
    }
    sort(res, res+4, greater<pair<double, double> >());
    for (int i=0; i<4; i++) {
      if (i != 0)
        cout << " ";
      printf("%.3f %.3f", res[i].first, res[i].second);
    }
    cout << endl;
    for (int i=0; i<4; i++)
      cin >> p[i].x >> p[i].y;
  }

  return 0;
}
