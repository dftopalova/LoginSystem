#pragma once
#include "PowerUser.h"
#include "VIP.h"

class Admin : public PowerUser, public VIP
{
public:
	Admin(const char* uName, const char* Password, const char* Title, const char* ip, int Reputation);
	
	void setUserNameToAdmin(const char* uName);
	void changeUserNameTo(User& u, const char* newName);

	void print() const;
};