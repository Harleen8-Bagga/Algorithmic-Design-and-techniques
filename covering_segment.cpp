#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;


struct Segment {
	int start, end;
};
bool sorting(Segment a, Segment b) { return(a.end < b.end); }

vector<int> optimal_points(vector<Segment> &segments) {

	std::sort(segments.begin(), segments.end(), sorting);
	vector<int> points;
	int point = segments[0].end;/*intialise the point with the leastmost right element*/
	points.push_back(point);/*pust the least right element ont the stack */
  //write your code here
	for (int i = 1; i < segments.size(); i++)
	{
		if (point<segments[i].start || point>segments[i].end)/*menas the rightmest elment is present in none of the segments*/
		{
			point = segments[i].end;
			points.push_back(point);/*push another point into the stack*/
		}
	}
	/* for (size_t i = 0; i < segments.size(); ++i) {
	   points.push_back(segments[i].start);
	   points.push_back(segments[i].end);
	 }*/
	return points;
}

int main() {
	int n;
	std::cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i) {
		std::cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	std::cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
}
