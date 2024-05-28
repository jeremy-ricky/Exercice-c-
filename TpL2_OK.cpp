#include <iostream>
#include <fstream>
#include  <string.h>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

// Function to initialize the account
void initializeAccount(string nbr) {
	fstream stud;
	fstream temp;

	stud.open("clients.txt",ios::in);
	temp.open("temp.txt",ios::out);
	char number[25];
	char name[25];
	char postname[25];
	char login[25];
	char password[25];
	char amount[25];

	const char* n = nbr.data();

	while(!stud.eof()) {
		stud.getline(number,25,'|');
		stud.getline(name,25,'|');
		stud.getline(postname,25,'|');
		stud.getline(login,25,'|');
		stud.getline(password,25,'|');
		stud.getline(amount,25);

		if(strcmp(number,n)==0) {
			string number1 = number;
			string name1 = name;
			string postname1 = postname;
			string login1 = login;
			string password1 = password;

			string sSolde = "0";

			temp << number1<<'|'<<name1<<'|'<<postname1<<'|'<<login1<<'|'<<password1<<'|'<<sSolde<<'\n';

		} else {
			temp << number<<'|'<<name<<'|'<<postname<<'|'<<login<<'|'<<password<<'|'<<amount<<'\n';
		}


	}
	temp.close();
	stud.close();

	stud.open("clients.txt",ios::out);
	temp.open("temp.txt",ios::in);
	while(!temp.eof()) {
		temp.getline(number,25,'|');
		temp.getline(name,25,'|');
		temp.getline(postname,25,'|');
		temp.getline(login,25,'|');
		temp.getline(password,25,'|');
		temp.getline(amount,25);
		stud << number<<'|'<<name<<'|'<<postname<<'|'<<login<<'|'<<password<<'|'<<amount<<'\n';
		\
	}
	temp.close();
	stud.close();
	remove("temp.txt");
	cout<<"\n Operation completed successfully !!! \n";
}

// Function to withdraw money
void withdraw_money(string nbr, string amt) {
	fstream stud;
	fstream temp;

	stud.open("clients.txt",ios::in);
	temp.open("temp.txt",ios::out);
	char number[25];
	char name[25];
	char postname[25];
	char login[25];
	char password[25];
	char amount[25];

	const char *n = nbr.data();
	const char *a = amt.data();

	while(!stud.eof()) {
		stud.getline(number,25,'|');
		stud.getline(name,25,'|');
		stud.getline(postname,25,'|');
		stud.getline(login,25,'|');
		stud.getline(password,25,'|');
		stud.getline(amount,25);

		if(strcmp(number,n)==0) {
			string number1 = number;
			string name1 = name;
			string postname1 = postname;
			string login1 = login;
			string password1 = password;
			std::string amount1 = a;
			std::string amount2 = amount;

			//int a1 = stoi(amount1); // (stoi) was introduced in C++11. Ensure your compiler supports C++11 or later standards
			int a1 = atoi(amount1.c_str());
			int a2 = atoi(amount2.c_str());
			int s = a2 - a1;
			std::stringstream ss;
  			ss << s;
			std::string sSolde = ss.str();

			temp << number1<<'|'<<name1<<'|'<<postname1<<'|'<<login1<<'|'<<password1<<'|'<<sSolde<<'\n';

		} else {
			temp << number<<'|'<<name<<'|'<<postname<<'|'<<login<<'|'<<password<<'|'<<amount<<'\n';
		}


	}
	temp.close();
	stud.close();

	stud.open("clients.txt",ios::out);
	temp.open("temp.txt",ios::in);
	while(!temp.eof()) {
		temp.getline(number,25,'|');
		temp.getline(name,25,'|');
		temp.getline(postname,25,'|');
		temp.getline(login,25,'|');
		temp.getline(password,25,'|');
		temp.getline(amount,25);
		stud << number<<'|'<<name<<'|'<<postname<<'|'<<login<<'|'<<password<<'|'<<amount<<'\n';
		\
	}
	temp.close();
	stud.close();
	remove("temp.txt");
	cout<<"\n Operation completed successfully !!! \n";
}

// Function to deposit money
void deposit_money(string nbr, string amt) {
	fstream stud;
	fstream temp;

	stud.open("clients.txt",ios::in);
	temp.open("temp.txt",ios::out);
	char number[25];
	char name[25];
	char postname[25];
	char login[25];
	char password[25];
	char amount[25];

	const char *n = nbr.data();
	const char *a = amt.data();

	while(!stud.eof()) {
		stud.getline(number,25,'|');
		stud.getline(name,25,'|');
		stud.getline(postname,25,'|');
		stud.getline(login,25,'|');
		stud.getline(password,25,'|');
		stud.getline(amount,25);

		if(strcmp(number,n)==0) {
			string number1 = number;
			string name1 = name;
			string postname1 = postname;
			string login1 = login;
			string password1 = password;
			string amount1 = a;
			std::string amount2 = amount;

			//int a1 = stoi(amount1); // (stoi) was introduced in C++11. Ensure your compiler supports C++11 or later standards
			int a1 = atoi(amount1.c_str());
			int a2 = atoi(amount2.c_str());
			int s = a2 + a1;
			std::stringstream ss;
  			ss << s;
			std::string sSolde = ss.str();

			temp << number1<<'|'<<name1<<'|'<<postname1<<'|'<<login1<<'|'<<password1<<'|'<<sSolde<<'\n';

		} else {
			temp << number<<'|'<<name<<'|'<<postname<<'|'<<login<<'|'<<password<<'|'<<amount<<'\n';
		}


	}
	temp.close();
	stud.close();

	stud.open("clients.txt",ios::out);
	temp.open("temp.txt",ios::in);
	while(!temp.eof()) {
		temp.getline(number,25,'|');
		temp.getline(name,25,'|');
		temp.getline(postname,25,'|');
		temp.getline(login,25,'|');
		temp.getline(password,25,'|');
		temp.getline(amount,25);
		stud << number<<'|'<<name<<'|'<<postname<<'|'<<login<<'|'<<password<<'|'<<amount<<'\n';
		\
	}
	temp.close();
	stud.close();
	remove("temp.txt");
	cout<<"\n Operation completed successfully !!! \n";
}

// Function to view the account amount
void get_amount_client(string nbr) {
	fstream stud;
	stud.open("clients.txt",ios::in);
	char number[25];
	char name[25];
	char postname[25];
	char login[25];
	char password[25];
	char amount[25];

	const char *a = nbr.data();

	cin.ignore();
	int x=0;

	while(!stud.eof()) {
		stud.getline(number,25,'|');
		stud.getline(name,25,'|');
		stud.getline(postname,25,'|');
		stud.getline(login,25,'|');
		stud.getline(password,25,'|');
		stud.getline(amount,25);
		if(strcmp(number, a)==0) {
			cout << "Your balance is : " << amount << " $" << endl;
			x=1;
			break;
		}

	}
	if(x==0) {
		cout<<" \n Not found !!!!\n";
	}

	stud.close();

}

// Recover the amount from the account
int get_amount_client2(string nbr) {

	fstream stud;
	stud.open("clients.txt",ios::in);
	char number[25];
	char name[25];
	char postname[25];
	char login[25];
	char password[25];
	char amount[25];

	const char *a = nbr.data();

	cin.ignore();
	int x=0;

	while(!stud.eof()) {
		stud.getline(number,25,'|');
		stud.getline(name,25,'|');
		stud.getline(postname,25,'|');
		stud.getline(login,25,'|');
		stud.getline(password,25,'|');
		stud.getline(amount,25);
		if(strcmp(number, a)==0) {
			int s = atoi(amount);
			return s;
			x=1;
			break;
		}

	}
	if(x==0) {
		cout<<" \n Not found !!!!\n";
	}

	stud.close();
	return 0;
}

// Function to find and return the customer password
string search_pwd_client(string pwd) {

	fstream stud;
	stud.open("clients.txt",ios::in);
	char number[25];
	char name[25];
	char postname[25];
	char login[25];
	char password[25];
	char amount[25];

	const char *p = pwd.data();

	cin.ignore();
	int x=0;

	while(!stud.eof()) {
		stud.getline(number,25,'|');
		stud.getline(name,25,'|');
		stud.getline(postname,25,'|');
		stud.getline(login,25,'|');
		stud.getline(password,25,'|');
		stud.getline(amount,25);
		if(strcmp(password, p)==0) {
			x=1;
			break;
		}

	}
	if(x==0) {
		//cout<<" \n Not found !!!!\n";
	}

	stud.close();

	return password;
}

// Function to verify the user
bool checkLogin(string pwd) {
	string pwd1 = search_pwd_client(pwd);
	if (pwd == pwd1) {
		return true;
	} else {
		return false;
	}

}

// Function to create a user account
void  insert_client() {
	char number[25];
	char name[25];
	char postname[25];
	char login[25];
	char password[25];
	string amount = "0";
	fstream stud;

	stud.open("clients.txt", ios::app);

	cin.ignore();

	cout <<" \n Enter your number : ";
	cin.getline(number,25);

	cout <<" \n Enter your name : ";
	cin.getline(name,25);

	cout <<" \n Enter your postname : ";
	cin.getline(postname,25);

	cout <<" \n Enter your login : ";
	cin.getline(login,25);

	cout <<" \n Enter your password : ";
	cin.getline(password,25);

	stud << number<<'|'<<name<<'|'<<postname<<'|'<<login<<'|'<<password<<'|'<<amount<<'\n';
	cout << "Dear customer " << name << ", your account has been successfully created !";

	stud.close();
}


int main() {
	string login, password;
	int tentative = 0;
	int choix1;
	string pwd;

	cout << "\nSe connecter ou Creer un compte :" << endl;
	cout << "1. Se connecter" << endl;
	cout << "2. Creer un compte" << endl;
	cout << "Choice : ";
	cin >> choix1;

	switch (choix1) {
		case 1:
			while (tentative < 3) {
				cout << "Login: ";
				cin >> login;
				cout << "Password: ";
				cin >> password;
				ifstream fichier("clients.txt");
				if (fichier.is_open()) {
					if (checkLogin(password)) {
						cout << "Connexion reussie, bienvenue cher(e) " << login << endl;
						break;
					} else {
						cout << "Login ou mot de passe incorrect. Reessayez." << endl;
						tentative++;
					}
				} else {
					cout << "Error : could not find text file !!!" << endl;
				}

			}

			if (tentative >= 3) {
				cout << "Tentatives de connexion epuisees. Programme termine." << endl;
				return 0;
			}
			break;
		case 2:
			insert_client();
			break;
		default:
			cout << "Choix invalide. Reessayez." << endl;
			break;
	}

	int choix;
	string montant;
	string number;
	int rs;
	int mnt;
	int s;

	do {
		cout << "\nMenu de gestion client :" << endl;
		cout << "1. Initialiser le compte client" << endl;
		cout << "2. Verifier le solde" << endl;
		cout << "3. Retirer au compte" << endl;
		cout << "4. Deposer dans le compte" << endl;
		cout << "5. Quitter" << endl;
		cout << "Choix : ";
		cin >> choix;

		switch (choix) {
			case 1:
				cout << "Entrez le numero pour initialiser votre compte, NB. votre solde sera remis a 0 $" << endl;
				cout << "Entrez le numero : ";
				cin >> number;
				initializeAccount(number);
				break;
			case 2:
				cout << "Entrez le numero : ";
				cin >> number;
				get_amount_client(number);
				break;
			case 3:
				cout << "Entrez le numero : ";
				cin >> number;
				cout << "Entrez le montant a retirer : ";
				cin >> montant;
				rs = get_amount_client2(number);
				mnt = atoi(montant.c_str());
				if (rs == 0) {
					cout << "Vous pouvez pas retirer, votre solde est 0 !";
				} else if(mnt > rs) {
					cout << "Le montant saisi est superieur a votre solde !";
				} else {
					withdraw_money(number, montant);
				}
				break;
			case 4:
				cout << "Entrez le numero : ";
				cin >> number;
				cout << "Entrez le montant a  deposer : ";
				cin >> montant;
				rs = get_amount_client2(number);
				mnt = atoi(montant.c_str());
				s = rs + mnt;
				if (s > 350) {
					cout << "Vous pouvez pas deposer plus de 350 $ max !";
				} else {
					deposit_money(number, montant);
					cout << "Votre solde disponible est : " << s << " $" << endl;
				}
				break;
			case 5:
				cout << "Programme termine." << endl;
				break;
			default:
				cout << "Choix invalide. Reessayez." << endl;
				break;
		}
	} while (choix != 5);

	return 0;
}

