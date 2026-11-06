
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// Classe abstraite Plugin
class Plugin {
public:
    virtual string nom() const = 0;
    virtual string traiter(const string& texte) = 0;

    virtual ~Plugin() {}

    // Methode Factory
    static unique_ptr<Plugin> creerPlugin(const string& type);
};

// Plugin 1 : Correcteur orthographique
class CorrecteurOrthographique : public Plugin {
public:
    string nom() const override {
        return "Correcteur orthographique";
    }

    string traiter(const string& texte) override {
        string resultat = texte;

        // Correction de quelques fautes simples
        size_t pos;

        while ((pos = resultat.find("bonjor")) != string::npos) {
            resultat.replace(pos, 6, "bonjour");
        }

        while ((pos = resultat.find("salu")) != string::npos) {
            resultat.replace(pos, 4, "salut");
        }

        while ((pos = resultat.find("mercie")) != string::npos) {
            resultat.replace(pos, 6, "merci");
        }

        return resultat;
    }
};

// Plugin 2 : Traducteur anglais
class TraducteurAnglais : public Plugin {
public:
    string nom() const override {
        return "Traducteur anglais";
    }

    string traiter(const string& texte) override {
        string resultat = texte;

        size_t pos;

        // Traduction de quelques mots
        while ((pos = resultat.find("bonjour")) != string::npos) {
            resultat.replace(pos, 7, "hello");
        }

        while ((pos = resultat.find("merci")) != string::npos) {
            resultat.replace(pos, 5, "thank you");
        }

        while ((pos = resultat.find("chat")) != string::npos) {
            resultat.replace(pos, 4, "cat");
        }

        while ((pos = resultat.find("maison")) != string::npos) {
            resultat.replace(pos, 6, "house");
        }

        return resultat;
    }
};

// Plugin 3 : Analyseur de style
class AnalyseurStyle : public Plugin {
public:
    string nom() const override {
        return "Analyseur de style";
    }

    string traiter(const string& texte) override {
        string resultat = texte;

        int nbPhrasesLongues = 0;
        int longueur = 0;

        // Compter les caracteres de chaque phrase
        for (size_t i = 0; i < texte.length(); i++) {
            if (texte[i] == '.' || texte[i] == '!' || texte[i] == '?') {
                if (longueur > 50) {
                    nbPhrasesLongues++;
                }
                longueur = 0;
            } else {
                longueur++;
            }
        }

        // Verifier la derniere phrase
        if (longueur > 50) {
            nbPhrasesLongues++;
        }

        resultat += "\n\n--- Analyse du style ---\n";

        if (nbPhrasesLongues > 0) {
            resultat += "Attention : ";
            resultat += to_string(nbPhrasesLongues);
            resultat += " phrase(s) trop longue(s).";
        } else {
            resultat += "Le texte est bien structure.";
        }

        return resultat;
    }
};

// Implementation de la Factory
unique_ptr<Plugin> Plugin::creerPlugin(const string& type) {

    if (type == "correcteur") {
        return make_unique<CorrecteurOrthographique>();
    }

    if (type == "traducteur") {
        return make_unique<TraducteurAnglais>();
    }

    if (type == "analyseur") {
        return make_unique<AnalyseurStyle>();
    }

    return nullptr;
}

// Programme principal
int main() {

    string texte;

    cout << "===== SYSTEME DE PLUGINS =====" << endl;

    // Saisie du texte
    cout << "Entrez votre texte : ";
    getline(cin, texte);

    // Vecteur des plugins
    vector<unique_ptr<Plugin>> plugins;

    // Creation des plugins avec la Factory
    plugins.push_back(Plugin::creerPlugin("correcteur"));
    plugins.push_back(Plugin::creerPlugin("traducteur"));
    plugins.push_back(Plugin::creerPlugin("analyseur"));

    // Application successive des plugins
    for (const auto& plugin : plugins) {

        if (plugin != nullptr) {

            cout << "\nPlugin applique : "
                 << plugin->nom() << endl;

            texte = plugin->traiter(texte);

            cout << "Texte apres traitement : " << endl;
            cout << texte << endl;

            cout << "-----------------------------" << endl;
        }
    }

    return 0;
}
