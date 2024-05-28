#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct Client {
    string nom;
    string prenom;
    int numeroCompte;
    float solde;
};

bool verifierLogin(string login, string password) {
    return (login == "vendeur" && password == "1234");
}

void initialiserCompte(Client& client) {
    cout << "Entrez le nom du client : ";
    cin >> client.nom;
    cout << "Entrez le prénom du client : ";
    cin >> client.prenom;
    cout << "Entrez le numéro de compte du client : ";
    cin >> client.numeroCompte;
    client.solde = 0;

    ofstream fichier("clients.txt", ios::app);
    if (fichier.is_open()) {
        fichier << client.nom << " " << client.prenom << " " << client.numeroCompte << " " << client.solde << endl;
        fichier.close();
        cout << "Client enregistré avec succès !" << endl;
    } else {
        cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
    }
}

void verifierSolde(int numeroCompte) {
    ifstream fichier("clients.txt");
    if (fichier.is_open()) {
        string nom, prenom;
        int compte;
        float solde;
        bool trouve = false;
        while (fichier >> nom >> prenom >> compte >> solde) {
            if (compte == numeroCompte) {
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

void retirer(Client& client, float montant) {
    if (client.solde - montant < -350) {
        cout << "Le solde après retrait ne peut pas être inférieur à -350 EUR." << endl;
        return;
    }
    client.solde -= montant;

    ofstream fichier("retrait.txt", ios::app);
    if (fichier.is_open()) {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        fichier << ltm->tm_mday << "/" << ltm->tm_mon + 1 << "/" << 1900 + ltm->tm_year << " " << montant << " " << client.numeroCompte << endl;
        fichier.close();
        cout << "Retrait effectué avec succès !" << endl;
    } else {
        cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
    }
}

void deposer(Client& client, float montant) {
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
    while (tentative < 3) {
        cout << "Login: ";
        cin >> login;
        cout << "Password: ";
        cin >> password;
        if (verifierLogin(login, password)) {
            cout << "Connexion réussie !" << endl;
            break;
        } else {
            cout << "Login ou mot de passe incorrect. Réessayez." << endl;
            tentative++;
        }
    }

    if (tentative == 3) {
        cout << "Tentatives de connexion épuisées. Programme terminé." << endl;
        return 0;
    }

    Client client;
    int choix;
    float montant;

    do {
        cout << "\nMenu de gestion client :" << endl;
        cout << "1. Initialiser compte" << endl;
        cout << "2. Vérifier solde" << endl;
        cout << "3. Retirer" << endl;
        cout << "4. Déposer" << endl;
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
                cout << "Entrez le montant à déposer : ";
                cin >> montant;
                deposer(client, montant);
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