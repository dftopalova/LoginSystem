#include "Admin.h"

Admin::Admin(const char * uName, const char * Password, const char * Title, const char * ip, int Reputation)
	: User(uName,Password,Title,ip), PowerUser(uName,Password,Title,Reputation,ip)
{
}

void Admin::setUserNameToAdmin(const char * uName)
{
	User::setUserName(uName);
}

void Admin::changeUserNameTo(User& u, const char * newName)
{
	if (newName == nullptr)
		return;
	u.setUserName(newName);
}

void Admin::print() const
{
	PowerUser::print();
}
