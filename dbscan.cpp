#include "dbscan.h"


int DBSCAN::run()
{
	int clusterID = CORE_POINT;
	std::vector<Point>::iterator iter;
	for (iter = m_points.begin(); iter != m_points.end(); ++iter) {
		if (iter->clusterID == UNCLASSIFIED) {
			if (expandCluster(*iter, clusterID) != FAILURE) {
				clusterID += 1;
			}
		}
	}
	return 0;
}

std::vector<int> DBSCAN::calculateCluster(const Point& point)
{
	int index = 0;
	std::vector<Point>::iterator iter;
	std::vector<int> clusterIndex;
	for (iter = m_points.begin(); iter != m_points.end(); ++iter) {
		if (calculateDistance(point, *iter) <= m_epsilon) {
			clusterIndex.push_back(index);
		}
		index++;
	}
	return clusterIndex;
}

int DBSCAN::expandCluster(Point& point, int clusterID)
{
	std::vector<int> clusterSeeds = calculateCluster(point);

	if (clusterSeeds.size() < m_minPoints) {
		point.clusterID = NOISE;
		return FAILURE;
	}
	else {
		int index = 0, indexCorePoint = 0;
		std::vector<int>::iterator iterSeeds;
		for (iterSeeds = clusterSeeds.begin(); iterSeeds != clusterSeeds.end(); ++iterSeeds) {
			m_points.at(*iterSeeds).clusterID = clusterID;
			if (m_points.at(*iterSeeds).x == point.x && m_points.at(*iterSeeds).y == point.y && m_points.at(*iterSeeds).z == point.z) {
				indexCorePoint = index;
			}
			++index;
		}
		clusterSeeds.erase(clusterSeeds.begin() + indexCorePoint);

		for (std::vector<int>::size_type i = 0, n = clusterSeeds.size(); i < n; ++i)
		{
			std::vector<int> clusterNeighors = calculateCluster(m_points.at(clusterSeeds[i]));

			if (clusterNeighors.size() >= m_minPoints)
			{
				std::vector<int>::iterator iterNeighors;
				for (iterNeighors = clusterNeighors.begin(); iterNeighors != clusterNeighors.end(); ++iterNeighors)
				{
					if (m_points.at(*iterNeighors).clusterID == UNCLASSIFIED || m_points.at(*iterNeighors).clusterID == NOISE)
					{
						if (m_points.at(*iterNeighors).clusterID == UNCLASSIFIED)
						{
							clusterSeeds.push_back(*iterNeighors);
							n = clusterSeeds.size();
						}
						m_points.at(*iterNeighors).clusterID = clusterID;
					}
				}
			}
		}

		return SUCCESS;
	}
}

inline double DBSCAN::calculateDistance(const Point& pC, const Point& pT)
{
	return pow(pC.x - pT.x, 2) + pow(pC.y - pT.y, 2) + pow(pC.z - pT.z, 2);
}

std::vector<int> DBSCAN::clusterResult()
{
	std::vector<int> res;
	for (const auto& p : m_points)
		res.push_back(p.clusterID);
	return res;
}

