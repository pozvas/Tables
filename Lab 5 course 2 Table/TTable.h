#pragma once
#include "TTabRecord.h"
#include "TDatCom.h"
#define TAB_OK 0
#define TAB_EMPTY -101
#define TAB_FULL -102
#define TAB_NO_RECORD -103
#define TAB_REC_DOUBLE -104
#define TAB_NO_MEM -105

class TTable : public TDatCom{
protected:
	size_t dataCount;
	size_t efficiency;
public:
	TTable():dataCount(0), efficiency(0) {}
	~TTable(){} // убрали virual

	size_t GetDataCount() const { return dataCount; }
	size_t GetEfficiency() const { return efficiency; }

	virtual bool IsFull() const = 0;
	bool IsEmpty() const { return dataCount == 0; }

	virtual PTDatValue FindRecord(TKey key) = 0;
	virtual bool InsertRecord(TKey key, PTDatValue value) = 0; // PTDatValue по ссылке
	virtual void DeleteRecord(TKey key) = 0;

	// итератор
	virtual int Reset() = 0;
	virtual int IsTabEnded() const = 0;
	virtual int GoNext() = 0;
	virtual TKey GetKey() const = 0;
	virtual PTDatValue GetValuePTR() const = 0;

	friend std::ostream& operator<<(std::ostream& out, TTable& table) {
		for (table.Reset(); !table.IsTabEnded(); table.GoNext()) {
			out << "Key: " << table.GetKey() << " Value: " << *table.GetValuePTR() << std::endl;
		}
		return out;
	}
};