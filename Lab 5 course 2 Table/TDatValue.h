#pragma once
#include <iostream>



class TDatValue {
protected:
	virtual void Print(std::ostream& os) const = 0;
public:
	TDatValue() = default;
	virtual TDatValue* GetCopy() = 0;
	friend std::ostream& operator<<(std::ostream& os, const TDatValue& dat) {
		//? dat* = nullptr
		dat.Print(os);
		return os;
	}
};

typedef TDatValue* PTDatValue;