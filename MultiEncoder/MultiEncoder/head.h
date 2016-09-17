
// C++���
#include <iostream>
#include <fstream>
#include <strstream>
#include <cmath>

// OpenCV
#include <opencv2/highgui/highgui.hpp>

static int PROJECTOR_RESLINE = 1280;
static int PROJECTOR_RESROW = 800;

// ���������ɡ�
// ����λ�����Ϊ16λ����ʹ��short���ʹ洢������
class CEncoder_Gray
{
private:
	int numDigit;			// λ��
	int grayCodeSize;		// �ܹ��ĸ�������Ŀ
	short *grayCode;		// ������
	cv::Mat *grayCodeMat;	// �������Ӧ��ͼ��
	int resRow;				// ͼ����зֱ���
	int resLine;			// ͼ����зֱ���
	bool lineBased;			// �Ƿ�����������

	std::string codeFileName;	// �洢��������ļ���
	std::string matFileNamePre;	// �洢������ͼ����ļ���
	std::string matFileNameEnd;	// �洢������ͼ��ĺ�׺��

	bool GetBit(short Code, int n);		// ��ȡCode�е������nλ��n��1��ʼ��
	bool EncodeGray();					// ����numDigitλ��GrayCode���洢��
	bool DrawMat();						// ���ݸ��������ݣ����Ƹ�����ͼ��
	bool WriteData();					// ������ļ�

public:
	CEncoder_Gray();										// ���캯����
	~CEncoder_Gray();									// ����������ɾ���������ؿռ䡣
	bool Encode(int numDigit, bool lineBased);			// ��ʼ����GrayCode����Ҫ��������λ����
	bool SetCodeFileName(std::string codeFileName);		// �趨�洢�ļ���
	bool SetMatFileName(std::string matFileNamePre, std::string matFileNameEnd);
	void Visualization();
};

// PhaseShifting���ɡ�
class CEncoder_Phase
{
private:
	int m_numMat;			// Mat��Ŀ
	int m_pixPeriod;		// ÿ���ڵ�pix��Ŀ
	cv::Mat * m_PSMat;		// phaseshifting��Ӧ��ͼ��

	int m_resRow;			// ͼ����зֱ���
	int m_resLine;			// ͼ����зֱ���
	bool m_lineBased;		// �Ƿ�����������

	std::string m_matFileNamePre;	// �洢PSͼ����ļ���
	std::string m_matFileNameEnd;	// �洢PSͼ��ĺ�׺��

	bool DrawMat();						// ����PS���ݣ�����ͼ��
	bool WriteData();					// ������ļ�

public:
	CEncoder_Phase();
	~CEncoder_Phase();
	bool Encode(int pixPeriod, bool lineBased);
	bool SetMatFileName(std::string matFileNamePre, std::string matFileNameEnd);
	void Visualization();
};