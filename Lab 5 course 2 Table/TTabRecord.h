#pragma once
#include <iostream>
#include "TDatValue.h"

typedef std::string TKey;

class TTabRecord : public TDatValue {

protected:

	TKey key;
	PTDatValue value;

	void Print(std::ostream& os) const override {
		os << key << " " << *value << std::endl;
	}

	void SetKey(const TKey& key) { this->key = key; }
	void SetValue(PTDatValue value) { this->value = value; }

public:


	TTabRecord(const TKey& key = "", PTDatValue value = nullptr) : key(key), value(value) {}

	TKey GetKey() { return key; }
	PTDatValue GetValue(){ return value; }

	TTabRecord& operator=(const TTabRecord& tab) {
		key = tab.key;
		value = tab.value;
		return *this;
	}

	bool operator==(const TTabRecord& tab) const {
		return key == tab.key;
	}

	bool operator>(const TTabRecord& tab) const {
		return key > tab.key;
	}

	bool operator<(const TTabRecord & tab) const {
		return key < tab.key;
	}

	PTDatValue GetCopy() override {
		PTDatValue val = new TTabRecord(key, value);
		return val;
	}

	friend class TScanTable;
	friend class TArrayTable;
};

typedef TTabRecord* PTTabRecord;