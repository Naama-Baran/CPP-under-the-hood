#ifndef  __IMAMMALS_H__
#define __IMAMMALS_H__

class IMammals
{
public:
	virtual ~IMammals(){};
	
	virtual unsigned short getPregnancyDuration() const =0;
	virtual unsigned short getNumberOfYoungBorn() const =0;	
};
#endif