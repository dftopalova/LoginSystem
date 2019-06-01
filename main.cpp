#include<iostream>
#include"Guest.h"
#include"User.h"
#include"PowerUser.h"
#include"VIP.h"
#include"Admin.h"

using namespace std;

int main()
{
	cout << "USER" << endl;
	User user("Daniel", "dani_password", "Dani_title", "10.45.75.69");
	user.print();
	user.setNewPassword("dani_password", "nova_parola");
	user.print();
	cout << "----------------------------" << endl;

	cout << "POWER USER" << endl;
	PowerUser pUser("Pesho", "pesho_password", "pesho_title", 5, "192.54.26.75");
	pUser.getReputationFrom(user);
	pUser.setNewPassword("pesho_password", "pesho_new_password");
	pUser.print();
	cout << "----------------------------" << endl;

	cout << "VIP" << endl;
	VIP vUser("Petko", "petko_password", "petko_title", "181.54.47.214");
	vUser.setVipTitle("petko_new_title");
	vUser.setNewPassword("petko_password", "petko_new_password");
	vUser.print();
	cout << "----------------------------" << endl;

	cout << "ADMIN" << endl;
	Admin admin("Dragan","dragan_password","dragan_title","145.25.8.125",2);
	admin.setNewPassword("dragan_password", "dragan_new_password");
	admin.setUserNameToAdmin("Dragancho Draganchev");
	admin.setVipTitle("dragan_new_title");
	admin.getReputationFrom(vUser);
	admin.print();
	cout << endl;
	admin.changeUserNameTo(user, "Dankata");
	user.print();
	cout << "----------------------------" << endl;

	system("pause");
	return 0;
}