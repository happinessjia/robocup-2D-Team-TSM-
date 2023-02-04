#ifndef INTERCEPT_H
#define INTERCEPT_H


#include "WorldModel.h"
#include "Objects.h"      
#include "PlayerSettings.h" 

typedef struct TagInterceptInfo
{
//�����������
	VecPosition Vel;

	ObjectT OppFastest;
	double OppCycles;

	ObjectT OurFastest;
	double OurCycles;
	VecPosition posEnd;
	
	bool isCaled;
} InterceptInfo;


class InterceptUtil	//using tsinghua method
{
public:
	//ͨ����������:ֻ�Ǹı����٣���������Ա�Ĳ�������
	//�õ�������Ϣ
	InterceptInfo* getInterceptInfo(const VecPosition& ballVel);
	int getInterceptCyc(const VecPosition& ballVel);
	//����
	VecPosition ballPos;
	VecPosition playerPos, playerVel;
	double angBody;
	double maxSpeed;
	double maxDashEffect;
	double kickableArea;//kickArea���ڲ������õĲ���
private:
	double kickArea;//kickArea���ڲ������õĲ���
	void getinterceptioninfo2(const VecPosition& ballVel, InterceptInfo& inf);
	VecPosition calc_interception_solution(const VecPosition& startpoint, double ballspeed);
	double calc_peakpoint(const VecPosition& pos);
};

extern InterceptUtil interUtil;

#endif
