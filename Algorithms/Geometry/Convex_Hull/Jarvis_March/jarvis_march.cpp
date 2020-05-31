/*
 *
 *          Author    : Amit Kumar
 *          E-mail    : offamitkumar@gmail.com 
 *          File Name : Jarvis March - Convex Hull 
 *          Date      : 26 May, 2020 
 *          Copyright : Open-Source 
 *          Last Update: 31 May, 2020
 *
 *
 */

#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

using Point = pair<int, int>;

class Solution {
    private: // added for proper indentation in vim 
        vector<Point> collinear_points; // these are possible boundary points 
        // if a point is potential candidate for boundary then all of it's 
        // collinear coordinates will be on boundary.
        set<Point>result;

        Point get_closer_point(Point&a, Point&b, Point&c){
            int x1 = a.first - b.first;
            int x2 = a.first - c.first;
            int y1 = a.second - b.second;
            int y2 = a.second - c.second;
            int distance_a_to_b = x1*x1 + y1*y1;
            int distance_a_to_c = x2*x2 + y2*y2;
            if (distance_a_to_c == distance_a_to_b) {
                return a; 
            } else if(distance_a_to_b > distance_a_to_c) {
                return c;
            } else {
                return b;
            }
        }

        int cross_product_(Point &a, Point &b, Point &c) {
            int x1 = a.first - b.first;
            int x2 = a.first - c.first;
            int y1 = a.second - b.second;
            int y2 = a.second - c.second;
            return y2 * x1 - y1 * x2; 
        }

    public:
        void find_convex_hull( vector< Point > & points ) {
            /* 
             * first -> x coordinate 
             * second -> y coordinate 
             */
            const int total_points = static_cast<int>(points.size());
            // get the left-most point in given points 
            Point start = points[0];
            for (int i = 0; i < total_points; ++i) {
                if (start.first > points[i].first) {
                    start = points[i];
                }
            }
            Point current = start;
            result.insert(start);
            while (true) {
                Point target = points.at(0);
                for (int i=0; i < total_points; ++i) {
                    if ( current == points.at(i) ) {
                        continue;
                    }
                    int cross_product = cross_product_(current, target, points[i]);
                    if (cross_product > 0) {
                        target = points.at(i);
                        collinear_points.clear();
                    } else if (cross_product == 0) { // point are collinear 
                        // add closer point to collinear array & make farthest point 
                        // our next target 
                        Point closer_point = get_closer_point(current, target, points[i]);
                        if(closer_point == target){
                            collinear_points.push_back(closer_point);
                            target = points[i];
                        }else {
                            collinear_points.push_back(points[i]);
                        }
                    }
                }
                for (auto&itr: collinear_points) {
                    result.insert(itr);
                }
                collinear_points.clear();
                if (target == start) {
                    break;
                }
                result.insert(target);
                current = target;
            }
            cout << "Boundary Points are : " << '\n'; 
            for (const Point &point : result) {
                cout << point.first << '\t' << point.second << '\n'; 
            }
            cout<<'\n'; 
            collinear_points.clear();
            result.clear();
        }
};

int main(int argc , char **argv) {
    vector<Point>v = {
        make_pair(0, 0), make_pair(0, 4), make_pair(-4, 0), make_pair(5, 0), 
        make_pair(0, -6), make_pair(1, 0)
    };
    Solution s1;
    s1.find_convex_hull(v);
    v.clear();
    v = {
        {0, 3}, {1, 1}, {2, 2}, {4, 4}, 
        {0, 0}, {1, 2}, {3, 1}, {3, 3}
    };
    s1.find_convex_hull(v);
    return 0;
}

