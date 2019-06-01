#include "User.h"

void User::encrypt(const char * str, char* encrypted)
{
	int len = strlen(str);
	char key = 'D';
	int i;
	for (i = 0; i < len; i++)
	{
		encrypted[i] = str[i] ^ key;
	}
	encrypted[i] = '\0';
}

void User::setPassword(const char * Password)
{
	if (Password == nullptr)
		return;
	int len = strlen(Password) + 1;
	delete[] this->password;
	this->password = new char[len];
	encrypt(Password,this->password);
}

void User::setUserName(const char * Name)
{
	if (Name == nullptr)
		return;
	int lenName = strlen(Name) + 1;
	delete[] this->userName;
	this->userName = new char[lenName];
	strcpy_s(userName, lenName, Name);
}

void User::setTitle(const char * Title)
{
	if (Title == nullptr)
		return;
	int lenTitle = strlen(Title) + 1;
	delete[] this->title;
	this->title = new char[lenTitle];
	strcpy_s(title, lenTitle, Title);
}

User::User()
	:Guest(nullptr),userName(nullptr),password(nullptr),title(nullptr)
{
	this->userName = new char[1];
	userName[0] = '\0';
	
	this->title = new char[1];
	title[0] = '\0';
	
	setPassword("");
}

User::User(const char * Name, const char * passw, const char * Title, const char* ip)
	: Guest(ip), userName(nullptr), password(nullptr), title(nullptr)
{
	setUserName(Name);
	setPassword(passw);
	setTitle(Title);
}

User::User(const User & other)
	:Guest(other), userName(nullptr), password(nullptr), title(nullptr)
{
	setUserName(other.userName);
	setTitle(other.title);
	setPassword(other.password);
}

User & User::operator=(const User & other)
{
	if (this != &other)
	{
		Guest::operator=(other);
		setUserName(other.userName);
		setTitle(other.title);
		setPassword(other.password);
	}
	return *this;
}

User::~User()
{
	delete[] this->userName;
	delete[] this->password;
	delete[] this->title;
}

void User::setNewPassword(const char* oldPassword, const char* newPassword)
{
	if(oldPassword == nullptr || newPassword == nullptr)
		return;	

	char* checkPassword = new char[strlen(oldPassword) + 1];
	encrypt(oldPassword,checkPassword);
	if (strcmp(checkPassword, getPassword()) == 0)
	{
		setPassword(newPassword);
	} 
	else
	{
		std::cout << "The entered password is not correct!" << std::endl;
	}
	delete[] checkPassword;
}

const char * User::getPassword() const
{
	return this->password;
}

const char * User::getUserName() const
{
	return this->userName;
}

const char * User::getTitle() const
{
	return this->title;
}

void User::print() const
{
	std::cout << "Name: " << getUserName() << std::endl;
	std::cout << "Password: " << getPassword() << std::endl;
	std::cout << "Title: " << getTitle() << std::endl;
}

