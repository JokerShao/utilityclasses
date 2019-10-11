//#include "../../src/dbscan.h"
//
//
///**
// * DBSCAN 基于密度的聚类算法
// */
//std::vector<int> CameraPoseCorrection::cluster(double * ellipses, int e_num, double eps, int min_samples)
//{
//	//// normalize
//	//double u_max = ellipses[0];
//	//double v_max = ellipses[1];
//	//double theta_max = MatlabToCVAngle(ellipses[4]);
//	//for (int i = 0; i < e_num; i++)
//	//{
//	//	if (ellipses[i * 5 + 0] > u_max)
//	//		u_max = ellipses[i * 5 + 0];
//	//	if (ellipses[i * 5 + 1] > v_max)
//	//		v_max = ellipses[i * 5 + 1];
//	//	if (MatlabToCVAngle(ellipses[i * 5 + 4]) > theta_max)
//	//		theta_max = ellipses[i * 5 + 4];
//	//}
//
//	std::vector<DBSCAN::Point> points;
//	for (int i = 0; i < e_num; i++)
//	{
//		//points.push_back(DBSCAN::Point{ ellipses[i * 5 + 0] / u_max, ellipses[i * 5 + 1] / v_max, ellipses[i * 5 + 4] / theta_max, UNCLASSIFIED });
//		//points.push_back(DBSCAN::Point{ ellipses[i * 5 + 0], ellipses[i * 5 + 1], MatlabToCVAngle(ellipses[i * 5 + 4]), UNCLASSIFIED });
//	}
//
//	// constructor
//	DBSCAN ds(eps, min_samples, points);
//
//	// main loop
//	ds.run();
//	return ds.clusterResult();
//}
