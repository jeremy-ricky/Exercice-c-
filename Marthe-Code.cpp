#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>
#include <unistd.h>

using namespace std;

struct Client {
    string numeroCompte;
    string nom;
    string postNom;
    string username;
    int password;
    int solde;
};

bool verifierLogin(string login, string password) {
    return (login == "vendeur" && password == "1234");
}

std::string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

void creerCompte(Client& client) {
    cout << "Saisissez votre nom : ";
    cin >> client.nom;
    cout << "Saisissez votre Postnom : ";
    cin >> client.postNom;
    cout << "Saisissez votre nom d'utilisateur : ";
    cin >> client.username;
    cout << "Saisissez votre mot de passe : ";
    cin >> client.password;
    client.solde = 0;

    srand((unsigned)time(NULL) * getpid());
    client.numeroCompte = gen_random(6);    
    //std::cout << "Voir === : " << gen_random(12) << "\n"; 

    ofstream fichier("clients.txt", ios::app);
    if (fichier.is_open()) {
        fichier << client.numeroCompte << " " << client.nom << " " << client.postNom << " " << client.username << " " << client.password << " " << client.solde << endl;
        fichier.close();
        cout << "Cher(e) " << client.nom << ", " << "votre compte a été enregistré avec succès, notez bien votre numéro de compte quelque part : " << client.numeroCompte << endl;
    } else {
        cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
    }
}

void initialiserCompte(Client& client) {
    cout << "Entrez le nom du client : ";
    cin >> client.nom;
    cout << "Entrez le prénom du client : ";
    cin >> client.postNom;
    cout << "Entrez le numéro de compte du client : ";
    cin >> client.numeroCompte;
    client.solde = 0;

    ofstream fichier("clients.txt", ios::app);
    if (fichier.is_open()) {
        fichier << client.nom << " " << client.postNom << " " << client.numeroCompte << " " << client.solde << endl;
        fichier.close();
        cout << "Client enregistré avec succès !" << endl;
    } else {
        cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
    }
}

int getSolde(string numeroCompte) {
    ifstream fichier("clients.txt");
    if (fichier.is_open()) {
        string nCpte, nom, postNom, username, password;
        int solde;
        bool trouve = false;
        //int s;

        while (fichier >> nCpte >> nom >> postNom >> username >> password >> solde) {
            int res = nCpte.compare(numeroCompte);
            if (res == 0) {
                trouve = true;
                //s = stoi(solde);
                return solde;
                break;
            }
        }
        if (!trouve) {
            cout << "Compte inexistant." << endl;
        }
        fichier.close();
    } else {
        cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
    }

}

void updateSoldes(string numeroCompte) {
    ifstream fichier("clients.txt");
    if (fichier.is_open()) {
        string nCpte, nom, postNom, username, password;
        int solde;
        bool trouve = false;
        //int s;

        while (fichier >> nCpte >> nom >> postNom >> username >> password >> solde) {
            int res = nCpte.compare(numeroCompte);
            if (res == 0) {
                trouve = true;
                //s = stoi(solde);
                
                break;
            }
        }
        if (!trouve) {
            cout << "Compte inexistant." << endl;
        }
        fichier.close();
    } else {
        cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
    }

}

void updateSolde(string numeroCompte, int nSolde) {

    fstream fichier("clients.txt", ios::in);
    if (fichier.is_open()) {
        string nCpte, nom, postNom, username, password;
        int solde;
        bool trouve = false;

        while (fichier >> nCpte >> nom >> postNom >> username >> password >> solde) {
            int res = nCpte.compare(numeroCompte);
            if (res == 0) {
                trouve = true;
                //int s = stoi(solde);
                //string s2 = to_string(nSolde); 
                int sd = solde+nSolde;
                //string sSolde = to_string(sd);
                cout << " =============== " << solde << " - " << sd;
                //cin.getline(s, 5);
                fichier << nCpte << " " << nom << " " << postNom << " " << username << " " << password << " " << sd << endl;
                //fichier << sd << endl;
                break;
            }
        }

        //fichier << client.numeroCompte << " " << client.nom << " " << client.postNom << " " << client.username << " " << client.password << " " << client.solde << endl;
        fichier.close();
    } else {
        cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
    }
}

void verifierSolde(string numeroCompte) {
    ifstream fichier("clients.txt");
    if (fichier.is_open()) {
        string nCpte, nom, postNom, username, password, solde;
        bool trouve = false;

        while (fichier >> nCpte >> nom >> postNom >> username >> password >> solde) {
            int res = nCpte.compare(numeroCompte);
            if (res == 0) {
                trouve = true;
                cout << "Solde du compte " << numeroCompte << " : " << solde << " $" << endl;
                break;
            }
        }
        if (!trouve) {
            cout << "Compte inexistant." << endl;
        }
        fichier.close();
    } else {
        cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
    }
}

void retirer(Client& client, string montant1) {
    int montant = stoi(montant1);
    //int solde = stoi(client.solde);
    if (client.solde - montant < -350) {
        cout << "Le solde après retrait ne peut pas être inférieur à -350 $." << endl;
        return;
    }
    client.solde -= montant;

    ofstream fichier("retrait.txt", ios::app);
    if (fichier.is_open()) {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        fichier << ltm->tm_mday << "/" << ltm->tm_mon + 1 << "/" << 1900 + ltm->tm_year << " " << montant << " " << client.numeroCompte << endl;
        
        // --------------------- Debut ajout ------------------
        fstream monFichier("clients.txt", ios::in);

        // --------------------- Fin ajout --------------------

        fichier.close();
        cout << "Retrait effectué avec succès !" << endl;
    } else {
        cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
    }
}

void deposer(Client& client, string montant1, string numeroCompte) {
    int montant = stoi(montant1);
    client.solde += montant;

    ofstream fichier("depot.txt", ios::app);
    if (fichier.is_open()) {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        fichier << ltm->tm_mday << "/" << ltm->tm_mon + 1 << "/" << 1900 + ltm->tm_year << " " << montant << " " << client.numeroCompte << endl;
        fichier.close();
        cout << "Dépôt effectué avec succès !" << endl;
    } else {
        cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
    }
}

int main() {
    string login, password;
    int tentative = 0;
    int choix1;
    Client client1;
    int s = getSolde("OS50ID");

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
                        cout << "Connexion réussie ! " << s << endl;
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
                creerCompte(client1);
                break;
            default:
                cout << "Choix invalide. Réessayez." << endl;
                break;
        }

    

    Client client;
    int choix;
    string montant;
    int mt;

    do {
        cout << "\nMenu de gestion client :" << endl;
        cout << "1. Initialiser le compte client" << endl;
        cout << "2. Vérifier le solde" << endl;
        cout << "3. Retirer au compte" << endl;
        cout << "4. Déposer dans le compte" << endl;
        cout << "5. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                initialiserCompte(client);
                break;
            case 2:
                cout << "Entrez le numéro de compte : ";
                cin >> client.numeroCompte;
                verifierSolde(client.numeroCompte);
                break;
            case 3:
                cout << "Entrez le montant à retirer : ";
                cin >> montant;
                retirer(client, montant);
                break;
            case 4:
                cout << "Entrez le numéro de compte : ";
                cin >> client.numeroCompte;
                cout << "Entrez le montant à déposer : ";
                cin >> mt;
                updateSolde(client.numeroCompte, mt);
                //deposer(client, montant, client.numeroCompte);
                break;
            case 5:
                cout << "Programme terminé." << endl;
                break;
            default:
                cout << "Choix invalide. Réessayez." << endl;
                break;
        }
    } while (choix != 5);

    return 0;
}