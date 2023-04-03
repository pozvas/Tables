#pragma once
#define DATA_OK 0
#define DATA_ERROR -1

class TDatCom {
protected:
	int retCode;
	int SetRetCode(int ret) {
		return retCode = ret;
	}
public:
	TDatCom() : retCode(DATA_OK) {}
	int GetRetCode() { 
		int tmp = retCode;
		retCode = DATA_OK;
		return tmp;
	}
	virtual ~TDatCom() {}
};