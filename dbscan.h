#pragma once
#include <vector>

#define UNCLASSIFIED     -1
#define CORE_POINT        1
#define BORDER_POINT      2
#define NOISE            -2
#define SUCCESS           0
#define FAILURE          -3


class DBSCAN
{
public:
	typedef struct Point_
	{
		double x, y, z;  // X, Y, Z position
		int clusterID;   // clustered ID
	}Point;

	DBSCAN() = delete;

	DBSCAN(double eps, int minPts, const std::vector<Point>& points) :m_minPoints(minPts), m_epsilon(eps), m_points(points) {
		m_pointSize = (int)points.size();
	}

	~DBSCAN() {}

	int run();
	std::vector<int> calculateCluster(const Point& point);
	int expandCluster(Point& point, int clusterID);
	inline double calculateDistance(const Point& pointCore, const Point& pointTarget);

	int getTotalPointSize() const { return m_pointSize; }
	int getMinimumClusterSize() const { return m_minPoints; }
	double getEpsilonSize() const { return m_epsilon; }
	std::vector<int> clusterResult();

private:
	std::vector<Point> m_points;
	int m_pointSize;
	int m_minPoints;
	double m_epsilon;
};

