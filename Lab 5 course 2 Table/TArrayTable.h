#pragma once
#include "TTable.h"

enum class Position {
	FIRST,
	CURRENT,
	LAST
};

class TArrayTable : public TTable {
protected:
	PTTabRecord* pData;
	size_t size;
	size_t curPos;
public:
	TArrayTable(size_t size = 50) : size(size), curPos(0) {
		pData = new PTTabRecord[this->size];
		for (int i = 0; i < this->size; i++)
			pData[i] = nullptr;
	}
	virtual ~TArrayTable() {
		for (int i = 0; i < size; i++)
			delete pData[i];
		delete[] pData;
	}

	virtual bool IsFull() const override { return dataCount >= size; }
	size_t GetSize() { return size;}

	virtual TKey GetKey(Position pos) const {
		int localPos = -1;
		if (!IsEmpty()) {
			switch (pos)
			{
			case Position::FIRST:
				localPos = 0;
				break;
			case Position::LAST: 
				localPos = dataCount - 1;
				break;
			default:
				localPos = curPos;
				break;
			}
		}
		return localPos == -1 ? TKey("") : pData[localPos]->GetKey();
	}
	virtual TKey GetKey() const {
		return GetKey(Position::CURRENT);
	}
	virtual PTDatValue GetValuePTR(Position pos) const {
		int localPos = -1;
		if (!IsEmpty()) {
			switch (pos)
			{
			case Position::FIRST:
				localPos = 0;
				break;
			case Position::LAST:
				localPos = dataCount - 1;
				break;
			default:
				localPos = curPos;
				break;
			}
		}
		return localPos == -1 ? nullptr : pData[localPos]->GetValue();
	}
	virtual PTDatValue GetValuePTR() const {
		return GetValuePTR(Position::CURRENT);
	}

	virtual int Reset() {
		curPos = 0;
		return IsTabEnded();
	}
	virtual int IsTabEnded() const {
		return curPos >= dataCount;
	}
	virtual int GoNext() {
		if (!IsTabEnded()) {
			curPos++;
		}
		return IsTabEnded();
	}

	virtual int SetCurrentPos(int pos) {
		if (pos < 0 || pos > dataCount)
			curPos = 0;
		else
			curPos = pos;
		return IsTabEnded();
	}
	int GetCurrentPos() const {
		return curPos;
	}
};