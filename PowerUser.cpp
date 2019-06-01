#include "PowerUser.h"

PowerUser::PowerUser()
	: User(), reputation(0)
{
}

PowerUser::PowerUser(const char * uName, const char * Password, const char * Title, int Reputation, const char * ip)
	: User(uName,Password,Title,ip), reputation(Reputation)
{
}

PowerUser::PowerUser(const PowerUser & other)
	:User(other), reputation(other.reputation)
{
}

PowerUser & PowerUser::operator=(const PowerUser & other)
{
	if (this != &other)
	{
		User::operator=(other);
		this->reputation = other.reputation;
	}
	return *this;
}

PowerUser::~PowerUser()
{
}

void PowerUser::getReputationFrom(const User& u)
{
	if (strcmp(u.getUserName() , this->getUserName()) != 0)
	{
		this->reputation++;
	}
	else
		std::cout << "Invalid operation! User can`t update his own reputation!" << std::endl;
}

int PowerUser::getReputation() const
{
	return this->reputation;
}

void PowerUser::print() const
{
	User::print();
	std::cout << "Reputation: " << getReputation() << std::endl;
}
