#pragma once

#ifdef GETNUM
class InputNum 
{
public:
	InputNum()
	{
		std::cout << "Enter number: ";
		std::cin >> _num;
	}
	
	int GetValue() const { return _num; }
	
	void AddInput()
	{
		InputNum aNum;
		_num = _num + aNum.GetValue();
	}
private:
	int _num;
};
#endif //GETNUM