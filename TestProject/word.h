#pragma once

#ifdef WORLD
class Matter
{
public:
	Matter(int id)
		: _indentifier(id)
	{
		std::cout << " Matter for " << _indentifier << " created\n";
	}
	~Matter()
	{
		std::cout << " Matter in " << _indentifier << " annihilated\n";
	}

private:
	const int _indentifier;
};

class World
{
public:
	World(int id)
		: _identifier(id),
		_matter(_identifier)
	{
		std::cout << "Hello from world " << _identifier << ".\n";
	}
	~World()
	{
		std::cout << "GoodBye from world " << _identifier << ".\n";
	}
private:
	const int _identifier;
	const Matter _matter;
};

World TheUniverse(1);

#endif // WORLD