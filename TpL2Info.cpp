#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int maxrow = 5;

string accountNumber[maxrow] = {};
string customerName[maxrow] = {};
string customerPostname[maxrow] = {};
string username[maxrow] = {};
string password[maxrow] = {};
string customerBalance[maxrow] = {};
//string customerID[maxrow] = {};

void AddRecord(){
	char accountNumberR[6];
	char customerNameR[20];
	char customerPostnameR[20];
	char usernameR[20];
	char passwordR[15];
	char customerBalanceR[5];

	cin.ignore();

	cout << "Customer Name: ";
	cin.getline(customerNameR, 20);

	cout << "Customer PostName: ";
	cin.getline(customerPostnameR, 20);

	cout << "Username: ";
	cin.getline(usernameR, 20);

	cout << "Password: ";
	cin.getline(passwordR, 15);

	// Checking the list index
	for (int i = 0; i < maxrow; ++i){
		if (accountNumber[i] == "\0"){

			accountNumber[i] = accountNumberR;
			customerName[i] = customerNameR;
			customerPostname[i] = customerPostnameR;
			username[i] = usernameR;
			password[i] = passwordR;
			customerBalance[i] = customerBalanceR;

			break;
		}
	}


}

int main()
{
	std::cout << "MENU\n";
	int option;
	// system("CLS"); // Clear screen for windows
	system("clear"); // Clear screen for linux

	do
	 {
	 	cout << "1-Create Records" << endl;
	 	cout << "2-Update Records" << endl;
	 	cout << "3-Delete Records" << endl;
	 	cout << "4-Search Records" << endl;
	 	cout << "5-Display all Records" << endl;
	 	cout << "6-Exit and Save to TextFile" << endl;
	 	cout << "================================" << endl;

	 	cout << "Select option >> ";
	 	cin >> option;

	 	switch (option){
	 		case 1:AddRecord();
	 			system("clear");
	 		break;
	 	}

	 } while (option != 6); 

	//return 0;
}