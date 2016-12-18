#pragma once
#include <iostream>

class HorBar
{
public:
	HorBar(int n)
	{
		std::cout << "+";
		for (int i = 0; i < n; ++i)
			std::cout << "-";
		std::cout << "+\n";

	}
};

class VerBar
{
public:
	VerBar(int n)
	{
		for (int i = 0; i < n; ++i)
			std::cout << "|\n";
	}
};

class Frame
{
public:
	Frame(int hor, int ver)
		: _highBar(hor),
		_verBar(ver),
		_lowBar(hor)
	{}
private:
	HorBar _highBar;
	VerBar _verBar;
	HorBar _lowBar;

};