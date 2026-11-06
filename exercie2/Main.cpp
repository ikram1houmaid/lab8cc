
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
using namespace std;

// Structure Vec3 : represente un point ou un vecteur 3D
struct Vec3 {
    float x, y, z;

    Vec3(float x = 0, float y = 0, float z = 0)
        : x(x), y(y), z(z) {}
};

// Fonction pour calculer la distance entre deux points
float distance(Vec3 a, Vec3 b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float dz = a.z - b.z;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

// Classe abstraite Lumiere
class Lumiere {
public:
    virtual float intensite(const Vec3& position) const = 0;

    virtual ~Lumiere() {}
};

// 1. Lumiere directionnelle
class LumiereDirectionnelle : public Lumiere {
private:
    Vec3 direction;
    float couleur;

public:
    LumiereDirectionnelle(Vec3 d, float c)
        : direction(d), couleur(c) {}

    float intensite(const Vec3& position) const override {
        return couleur;
    }
};

// 2. Lumiere ponctuelle
class LumierePonctuelle : public Lumiere {
private:
    Vec3 position;
    float attenuation;

public:
    LumierePonctuelle(Vec3 p, float a)
        : position(p), attenuation(a) {}

    float intensite(const Vec3& point) const override {
        float d = distance(position, point);

        return 1.0f / (1.0f + attenuation * d * d);
    }
};

// 3. Lumiere spot
class LumiereSpot : public Lumiere {
private:
    Vec3 position;
    Vec3 direction;
    float angleOuverture;

public:
    LumiereSpot(Vec3 p, Vec3 d, float angle)
        : position(p), direction(d), angleOuverture(angle) {}

    float intensite(const Vec3& point) const override {
        float d = distance(position, point);

        if (d == 0)
            return 1.0f;

        // Calcul de la direction vers le point
        float dx = point.x - position.x;
        float dy = point.y - position.y;
        float dz = point.z - position.z;

        // Produit scalaire
        float produit = dx * direction.x
                      + dy * direction.y
                      + dz * direction.z;

        float longueur = sqrt(
            direction.x * direction.x +
            direction.y * direction.y +
            direction.z * direction.z
        );

        if (longueur == 0)
            return 0.0f;

        // Calcul du cosinus de l'angle
        float cosAngle = produit / (d * longueur);

        float limite = cos(angleOuverture * 3.14159f / 180.0f);

        // Verifier si le point est dans le cone lumineux
        if (cosAngle >= limite) {
            return 1.0f / (1.0f + 0.1f * d * d);
        }

        return 0.0f;
    }
};

// Vecteur contenant toutes les lumieres
vector<unique_ptr<Lumiere>> lumieres;

// Fonction qui calcule l'eclairage total
float calculerEclairage(const Vec3& point) {
    float total = 0.0f;

    for (const auto& lumiere : lumieres) {
        total += lumiere->intensite(point);
    }

    return total;
}

// Programme principal
int main() {

    // Creation des lumieres
    lumieres.push_back(
        make_unique<LumiereDirectionnelle>(
            Vec3(0, -1, 0), 0.8f
        )
    );

    lumieres.push_back(
        make_unique<LumierePonctuelle>(
            Vec3(0, 0, 0), 0.05f
        )
    );

    lumieres.push_back(
        make_unique<LumiereSpot>(
            Vec3(0, 0, 5), Vec3(0, 0, -1), 30.0f
        )
    );

    // Points a tester
    Vec3 points[] = {
        Vec3(1, 1, 1),
        Vec3(2, 2, 2),
        Vec3(0, 0, 3)
    };

    // Calcul et affichage des resultats
    for (int i = 0; i < 3; i++) {

        cout << "Point " << i + 1 << " : ("
             << points[i].x << ", "
             << points[i].y << ", "
             << points[i].z << ")" << endl;

        cout << "Intensite totale : "
             << calculerEclairage(points[i]) << endl;

        cout << "------------------------" << endl;
    }

    return 0;
}
