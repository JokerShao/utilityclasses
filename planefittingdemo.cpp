#if 0

#include <vector>
#include "Eigen/SVD"


/**
 * see:https://stackoverflow.com/questions/39370370/eigen-and-svd-to-find-best-fitting-plane-given-a-set-of-points
 * 其原理就是计算协方差矩阵 然后找方差分布最大的维度 与其垂直的向量就是该平面的法向量
 * 这个好像和 PCA降维有相似之处
 */
std::pair<Eigen::Vector3d, Eigen::Vector3d> plane_fitting(const std::vector<Eigen::Vector3d>& ps)
{
	// 地面mark点少于3个，拟合不出来结果，直接返回原始的激光定位系
	if (ps.size() < 3) return std::make_pair(Eigen::Vector3d::Zero(), Eigen::Vector3d::UnitY());

	Eigen::MatrixXd point_coord = Eigen::MatrixXd::Random(ps.size(), 3);
	for (int r = 0; r < ps.size(); r++)
	{
		auto P = ps[r];
		point_coord(r, 0) = P.x();
		point_coord(r, 1) = P.y();
		point_coord(r, 2) = P.z();
	}

	// 转置 生成符合要求的数据
	Eigen::MatrixXd points = point_coord.transpose();

	// 转置后的矩阵 求行均值 各方向平均的 x y z坐标
	Eigen::Matrix<double, 3, 1> mean = points.rowwise().mean();

	// 求协方差矩阵
	const Eigen::Matrix3Xd points_centered = points.colwise() - mean;

	int setting = Eigen::ComputeFullU | Eigen::ComputeThinV;
	Eigen::JacobiSVD<Eigen::Matrix3Xd> svd = points_centered.jacobiSvd(setting);

	Eigen::MatrixXd U = svd.matrixU();
	//std::cout << "SVD U:\n" << U << "\n\n";
	//std::cout << "SVD V:\n" << svd.matrixV() << "\n\n";
	Eigen::Vector3d normal = U.col(2);

	// 返回值为 平面中心 和 平面的方向向量
	return std::make_pair(mean, normal);
}

#endif

