#if 0

#include <iostream>
#include <cuda_runtime.h>

#pragma comment(lib, "cudart.lib")


bool print_device_info(int dev_id = 0)
{
	cudaDeviceProp devProp;
	cudaGetDeviceProperties(&devProp, dev_id);

	std::cout << "使用GPU device " << dev_id << ": " << devProp.name << std::endl;
	std::cout << "SM的数量：" << devProp.multiProcessorCount << std::endl;
	std::cout << "最大常量内存： "<<devProp.totalConstMem / 1024.0 << " KB" << std::endl;
	std::cout << "每个block线程块的共享内存大小：" << devProp.sharedMemPerBlock / 1024.0 << " KB" << std::endl;
	std::cout << "每个MP的寄存器数量： "<<devProp.regsPerMultiprocessor << std::endl;
	std::cout << "线程束尺寸： "<<devProp.warpSize << std::endl;
	std::cout << "每个block线程块的最大线程数：" << devProp.maxThreadsPerBlock << std::endl;

	std::cout << "每个MP -EM的最大线程数：" << devProp.maxThreadsPerMultiProcessor << std::endl;
	std::cout << "每个EM的最大线程束数：" << devProp.maxThreadsPerMultiProcessor / 32 << std::endl;

	//-------------------------------------
	std::cout << "最大流数量：" << devProp.streamPrioritiesSupported << std::endl;
	std::cout << "canUseHostPointerForRegisteredMem：" << devProp.canUseHostPointerForRegisteredMem << std::endl;
	std::cout << "是否支持overlaps： " << (devProp.deviceOverlap ? "是" : "否") << std::endl;

	return true;
}

int device_check_demo()
{
	print_device_info();

	return 0;
}

#endif

