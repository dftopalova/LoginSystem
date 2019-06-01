#include "VIP.h"

VIP::VIP(const char * uName, const char * Password, const char * Title, const char * ip)
	: User(uName,Password,Title,ip)
{
}

VIP::VIP()
	:User()
{
}

VIP::VIP(const VIP & other)
	: User(other)
{
}

VIP & VIP::operator=(const VIP & other)
{
	if (this != &other)
	{
		User::operator=(other);
	}
	return *this;
}

VIP::~VIP()
{
}


void VIP::setVipTitle(const char * newTitle)
{
	User::setTitle(newTitle);
}

void VIP::print() const
{
	User::print();
}
