#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int maxrow = 20;

string accountNumber[maxrow] = {};
string customerName[maxrow] = {};
string customerPostname[maxrow] = {};
string username[maxrow] = {};
string password[maxrow] = {};
string solde[maxrow] = {};

void AddRecord(){
	char name[20];
	char empno[5];

	char postname[20];
	char tusername[20];

	char pwd[15];
	char tsolde[5];

	cin.ignore();

	cout << "Customer ID: ";
	cin.getline(empno, 5);

	cout << "Customer Name: ";
	cin.getline(name, 20);

	cout << "Customer PostName: ";
	cin.getline(postname, 20);
	cout << "Customer username: ";
	cin.getline(tusername, 20);

	cout << "Customer password: ";
	cin.getline(pwd, 15);

	cout << "Customer solde: ";
	cin.getline(tsolde, 5);

	// Checking the list index
	for (int i = 0; i < maxrow; ++i){
		if (accountNumber[i] == "\0"){

			accountNumber[i] = empno;
			customerName[i] = name;
			password[i] = pwd;
			customerPostname[i] = postname;
			username[i] = tusername;
			solde[i] = tsolde;

			break;
		}
	}

}

void ListRecord(){
	system("clear");
	cout << "Current Record(s)" << endl;
	cout << "==========================================================" << endl;

	int counter = 0;
	cout << " No. | ID | NAME | POST-NOM | USERNAME | PASSWORD | SOLDE " << endl << "---------------------------------------------------------\n";
	for (int i = 0; i < maxrow; ++i)
	{
		if (accountNumber[i] != "\0")
		{
			counter++;
			cout << "   " << counter << "   " << accountNumber[i] << "   " << customerName[i] << "   " << customerPostname[i] << "   " << username[i] << "    " << password[i] << "    " << solde[i] << endl;
		}
	}
	if (counter == 0)
	{
		cout << "No Record found !" << endl;
	}

	cout << "===========================================================" << endl;

}

void SearchRecord(string epID){
	system("clear");
	cout << "Current Record(s)" << endl;
	cout << "===================================================" << endl;

	int counter = 0;
	for (int i = 0; i < maxrow; ++i)
	{
		if (accountNumber[i] == epID)
		{
			counter++;
			cout << "   " << counter << "   " << accountNumber[i] << "   " << customerName[i] << "   " << customerPostname[i] << "   " << username[i] << "    " << password[i] << "    " << solde[i] << endl;
			break;
		}
	}
	if (counter == 0)
	{
		cout << "No Record found !" << endl;
	}

	cout << "===================================================" << endl;
}

void UpdateRecord(string epID){
	char s[5];

	int counter = 0;

	for (int i = 0; i < maxrow; ++i)
	{
		if (accountNumber[i] == epID)
		{
			counter++;

			cout << "Customer solde: ";
			cin.getline(s, 5);

			solde[i] = s;

			cout << "Update Successfull !" << endl;
			break;

		}
	}
}

bool verifierLogin(string login, string pwd) {
	for (int i = 0; i < maxrow; ++i)
	{
		return (username[i] == login && password[i] == pwd);
	}
}

int main()
{
	std::cout << "MENU\n";
	int option;
	string empID;

	string login, password;
    int tentative = 0;
    int choix1;

	// system("CLS"); // Clear screen for windows
	system("clear"); // Clear screen for linux

	cout << "\nSe connecter ou Créer un compte :" << endl;
    cout << "1. Se connecter" << endl;
    cout << "2. Créer un compte" << endl;
    cout << "Choix : ";
    cin >> choix1;

        switch (choix1) {
            case 1:
                while (tentative < 3) {
                    cout << "Login: ";
                    cin >> login;
                    cout << "Password: ";
                    cin >> password;
                    if (verifierLogin(login, password)) {
                        cout << "Connexion réussie ! " << login << endl;
                        break;
                    } else {
                        cout << "Login ou mot de passe incorrect. Réessayez." << endl;
                        tentative++;
                    }
                }

                if (tentative >= 3) {
                    cout << "Tentatives de connexion épuisées. Programme terminé." << endl;
                    return 0;
                }
                break;
            case 2:
                //creerCompte(client1);
                break;
            default:
                cout << "Choix invalide. Réessayez." << endl;
                break;
        }

	do
	 {
	 	cout << "1-Create Records" << endl;
	 	cout << "2-Update Records" << endl;
	 	cout << "3-Delete Records" << endl;
	 	cout << "4-Search Records" << endl;
	 	cout << "5-Display all Records" << endl;
	 	cout << "6-Exit and Save to TextFile" << endl;
	 	cout << "===================================================" << endl;

	 	cout << "Select option >> ";
	 	cin >> option;

	 	switch (option){
	 		case 1:AddRecord();
	 			system("clear");
	 			break;
	 		case 2:
	 			cin.ignore();
	 			cout << "Update by ID >> ";
	 			getline(cin, empID);
	 			UpdateRecord(empID);
	 			break;
	 		case 4:
	 			cin.ignore();
	 			cout << "Search by ID >> ";
	 			getline(cin, empID);
	 			SearchRecord(empID);
	 			break;
	 		case 5:ListRecord();
	 			break;
	 	}

	 } while (option != 6); 

	//return 0;
}