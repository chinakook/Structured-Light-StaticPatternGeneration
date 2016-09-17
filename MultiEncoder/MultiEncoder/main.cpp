#include "head.h"
using namespace cv;

int main()
{
	// 格雷码进行编码
	CEncoder_Gray EGray_v, EGray_h;
	EGray_v.SetCodeFileName("Gray_v/GrayCode.txt");
	EGray_v.SetMatFileName("Gray_v/GrayMat", ".bmp");
	if (!EGray_v.Encode(6, true))
		printf("Gray_v Encode failed.\n");
	EGray_v.Visualization();

	EGray_h.SetCodeFileName("Gray_h/GrayCode.txt");
	EGray_h.SetMatFileName("Gray_h/GrayMat", ".bmp");
	if (!EGray_h.Encode(5, false))
		printf("Gray_h Encode failed.\n");
	EGray_h.Visualization();
	
	// PhaseShifting进行编码
	CEncoder_Phase EPS_v, EPS_h;
	EPS_v.SetMatFileName("Phase_v/PhaseMat", ".bmp");
	if (!EPS_v.Encode(PROJECTOR_RESLINE / 64, true))
		printf("PhaseShifting_v Encode failed.\n");
	EPS_v.Visualization();

	EPS_h.SetMatFileName("Phase_h/PhaseMat", ".bmp");
	if (!EPS_h.Encode(PROJECTOR_RESROW / 32, false))
		printf("PhaseShifting_h Encode failed.\n");
	EPS_h.Visualization();

	system("PAUSE");
	return 0;
}