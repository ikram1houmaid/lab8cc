
#include <iostream>
#include <string>
using namespace std;

// Classe abstraite
class SortieAudio {
public:
    virtual void ouvrir() = 0;
    virtual void jouer(const string& son) = 0;
    virtual void fermer() = 0;

    // Destructeur virtuel
    virtual ~SortieAudio() {
        cout << "Destruction de SortieAudio" << endl;
    }
};

// Classe HautParleur
class HautParleur : public SortieAudio {
public:
    void ouvrir() override {
        cout << "Haut-parleur ouvert." << endl;
    }

    void jouer(const string& son) override {
        cout << "Haut-parleur joue : " << son << endl;
    }

    void fermer() override {
        cout << "Haut-parleur ferme." << endl;
    }

    ~HautParleur() {
        cout << "Destruction du Haut-parleur" << endl;
    }
};

// Classe CasqueBT
class CasqueBT : public SortieAudio {
public:
    void ouvrir() override {
        cout << "Casque Bluetooth connecte." << endl;
    }

    void jouer(const string& son) override {
        cout << "Casque Bluetooth joue : " << son << endl;
    }

    void fermer() override {
        cout << "Casque Bluetooth deconnecte." << endl;
    }

    ~CasqueBT() {
        cout << "Destruction du Casque Bluetooth" << endl;
    }
};

// Classe SortieHDMI
class SortieHDMI : public SortieAudio {
public:
    void ouvrir() override {
        cout << "Sortie HDMI activee." << endl;
    }

    void jouer(const string& son) override {
        cout << "Sortie HDMI joue : " << son << endl;
    }

    void fermer() override {
        cout << "Sortie HDMI desactivee." << endl;
    }

    ~SortieHDMI() {
        cout << "Destruction de la sortie HDMI" << endl;
    }
};

// Fonction de test polymorphique
void tester(SortieAudio* sortie) {
    sortie->ouvrir();
    sortie->jouer("Musique de test");
    sortie->fermer();

    cout << "------------------------" << endl;
}

int main() {

    // Tableau de pointeurs
    SortieAudio* sorties[3];

    // Allocation dynamique
    sorties[0] = new HautParleur();
    sorties[1] = new CasqueBT();
    sorties[2] = new SortieHDMI();

    // Parcours du tableau
    for (int i = 0; i < 3; i++) {
        tester(sorties[i]);
    }

    // Liberation de la memoire
    for (int i = 0; i < 3; i++) {
        delete sorties[i];
    }

    return 0;
}
