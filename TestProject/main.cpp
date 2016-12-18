#include <iostream>
#include "switch.h"

int main() 
{

#ifdef STACK
	Istack stack;
	
	for (int i = 1; i < MaxStack + 1 ; ++i)
		stack.Push(i);
	for (int i = 1; i < MaxStack + 1; ++i)
		std::cout << "Popped " << stack.Pop() << std::endl;
#endif //STACK

#ifdef FRAME
	Frame aFrame(5,3);
	Frame bFrame(3, 2);
#endif //FRAME

#ifdef GETNUM
	InputNum num;
	std::cout << "The Value is: " << num.GetValue() << ".\n";
	num.AddInput();
	std::cout << "Now the Value is: " << num.GetValue() << ".\n";

#endif //GETNUM

#ifdef WORLD
	World smallWorld(2);
	/*for (int i = 3; i < 6; ++i)
	World aWorld(i);

	World oneMoreWorld(6);*/
#endif // WORLD

#ifdef STAER
	std::cout << " Entering Main.\n";
	Star aStar(123.5, 0.1);
	std::cout << " Exiting Main.\n";

#endif //STAR

}