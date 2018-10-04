#pragma once

const int MaxStack = 4;

class Istack
{
public:
	Istack() :_top(0) {}
	void Push(int i);
	int Pop();
private:
	int _arr[MaxStack];
	int _top;
};