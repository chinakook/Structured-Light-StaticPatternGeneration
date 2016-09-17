
// C++相关
#include <iostream>
#include <fstream>
#include <strstream>
#include <cmath>

// OpenCV
#include <opencv2/highgui/highgui.hpp>

static int PROJECTOR_RESLINE = 1280;
static int PROJECTOR_RESROW = 800;

// 格雷码生成。
// 生成位数最多为16位。即使用short类型存储格雷码
class CEncoder_Gray
{
private:
	int numDigit;			// 位数
	int grayCodeSize;		// 总共的格雷码数目
	short *grayCode;		// 格雷码
	cv::Mat *grayCodeMat;	// 格雷码对应的图像
	int resRow;				// 图像的行分辨率
	int resLine;			// 图像的列分辨率
	bool lineBased;			// 是否按照列来绘制

	std::string codeFileName;	// 存储格雷码的文件名
	std::string matFileNamePre;	// 存储格雷码图像的文件名
	std::string matFileNameEnd;	// 存储格雷码图像的后缀名

	bool GetBit(short Code, int n);		// 获取Code中的右起第n位。n从1开始。
	bool EncodeGray();					// 构建numDigit位的GrayCode并存储。
	bool DrawMat();						// 根据格雷码内容，绘制格雷码图像
	bool WriteData();					// 输出到文件

public:
	CEncoder_Gray();										// 构造函数。
	~CEncoder_Gray();									// 析构函数。删除分配的相关空间。
	bool Encode(int numDigit, bool lineBased);			// 开始构建GrayCode。需要传入具体的位数。
	bool SetCodeFileName(std::string codeFileName);		// 设定存储文件名
	bool SetMatFileName(std::string matFileNamePre, std::string matFileNameEnd);
	void Visualization();
};

// PhaseShifting生成。
class CEncoder_Phase
{
private:
	int m_numMat;			// Mat数目
	int m_pixPeriod;		// 每周期的pix数目
	cv::Mat * m_PSMat;		// phaseshifting对应的图像

	int m_resRow;			// 图像的行分辨率
	int m_resLine;			// 图像的列分辨率
	bool m_lineBased;		// 是否按照列来绘制

	std::string m_matFileNamePre;	// 存储PS图像的文件名
	std::string m_matFileNameEnd;	// 存储PS图像的后缀名

	bool DrawMat();						// 根据PS内容，绘制图像
	bool WriteData();					// 输出到文件

public:
	CEncoder_Phase();
	~CEncoder_Phase();
	bool Encode(int pixPeriod, bool lineBased);
	bool SetMatFileName(std::string matFileNamePre, std::string matFileNameEnd);
	void Visualization();
};