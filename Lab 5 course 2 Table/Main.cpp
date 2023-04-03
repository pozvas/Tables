#include "TScanTable.h"


class TMark : public TDatValue
{
private:
	int _marks[5];
public:
	TMark(int first, int second, int third, int fourth, int fifth) {
		_marks[0] = first;
		_marks[1] = second;
		_marks[2] = third;
		_marks[3] = fourth;
		_marks[4] = fifth;
	}
	void Print(std::ostream& os) const override{
		for (int i = 0; i < 5; i++) {
			os << _marks[i] << " ";
		}
		os << std::endl;
	}
	TDatValue* GetCopy() override {
		return new TMark(_marks[0], _marks[1], _marks[2], _marks[3], _marks[4]);
	}
};
int main() {
	TScanTable scan;
	scan.InsertRecord("First", new TMark(1, 2, 3, 4, 5));
}