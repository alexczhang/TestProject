#include "stack.h"
#include <cassert>

void Istack::Push(int i)
{
	assert(_top < MaxStack);
	_arr[_top++] = i;
}

int Istack::Pop()
{
	assert(_top > 0);
	
	return _arr[--_top];
}

