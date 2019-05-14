#include "Animal.h"

Animal::Animal(int id) : m_id(id)
{
}

int Animal::GetId()
{
	return m_id;
}
