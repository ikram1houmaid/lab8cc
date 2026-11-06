# TP : Programmation Orientée Objet en C++

## Présentation générale

Ce projet regroupe trois exercices réalisés en **C++** dans le cadre de la programmation orientée objet (POO).

Les exercices mettent en pratique les notions d'héritage, de classes abstraites, de polymorphisme, de méthodes virtuelles, de pointeurs intelligents et de gestion dynamique de la mémoire.

Les trois programmes ont été développés en C++ et sont destinés à être compilés et exécutés dans l'environnement Eclipse avec un compilateur C++ compatible.

---

# Exercice 1 : Gestion de périphériques audio

## Description

Cet exercice consiste à développer un système permettant de gérer différents périphériques audio : haut-parleur, casque Bluetooth et sortie HDMI.

Une classe abstraite `SortieAudio` définit les opérations communes à tous les périphériques :
- `ouvrir()` : ouvrir ou activer le périphérique.
- `jouer()` : lire un son.
- `fermer()` : fermer ou désactiver le périphérique.

Trois classes dérivées implémentent ces méthodes :
- `HautParleur`
- `CasqueBT`
- `SortieHDMI`

## Notions utilisées
- Classe abstraite et méthodes virtuelles pures.
- Héritage et redéfinition des méthodes.
- Polymorphisme à travers un tableau de pointeurs.
- Destructeur virtuel.
- Allocation et libération dynamique avec `new` et `delete`.

## Fonctionnement

Le programme crée trois périphériques audio, les stocke dans un tableau de pointeurs vers la classe mère et appelle une fonction `tester()` pour exécuter les opérations de chaque périphérique.

La mémoire est correctement libérée grâce au destructeur virtuel.

---

# Exercice 2 : Moteur de rendu 3D

## Description

Cet exercice consiste à développer un système simplifié de gestion des sources lumineuses dans un moteur graphique 3D.

Une classe abstraite `Lumiere` définit une méthode virtuelle pure :

`intensite(const Vec3& position)`

La structure `Vec3` représente les coordonnées d'un point dans l'espace 3D.

Trois types de lumières sont implémentés :
- `LumiereDirectionnelle` : fournit une intensité constante.
- `LumierePonctuelle` : calcule une intensité qui diminue avec la distance.
- `LumiereSpot` : éclaire uniquement les points situés dans son cône lumineux.

## Notions utilisées
- Structure personnalisée `Vec3`.
- Classe abstraite et héritage.
- Polymorphisme et méthodes virtuelles.
- Conteneur `std::vector`.
- Pointeurs intelligents `std::unique_ptr`.
- Création des objets avec `std::make_unique`.
- Calcul de distance et produit scalaire.

## Fonctionnement

Le programme crée plusieurs sources lumineuses et les stocke dans un vecteur de pointeurs intelligents.

La fonction `calculerEclairage()` parcourt toutes les lumières, récupère leur intensité pour un point donné et additionne les résultats.

Plusieurs points 3D sont testés afin d'afficher leur intensité lumineuse totale.

La gestion de la mémoire est automatique grâce à `std::unique_ptr`.

---

# Exercice 3 : Système de plugins de traitement de texte

## Description

Cet exercice consiste à développer un système de plugins permettant de transformer et d'analyser un texte à travers plusieurs modules indépendants.

Une classe abstraite `Plugin` définit deux méthodes virtuelles pures :
- `nom()` : retourne le nom du plugin.
- `traiter()` : applique un traitement au texte.

Trois plugins sont implémentés :

### 1. CorrecteurOrthographique
Corrige certaines fautes simples dans le texte, notamment :
- bonjor → bonjour
- salu → salut
- mercie → merci

### 2. TraducteurAnglais
Remplace quelques mots français par leurs équivalents anglais :
- bonjour → hello
- merci → thank you
- chat → cat
- maison → house

### 3. AnalyseurStyle
Analyse le texte et :
- Compte les phrases contenant plus de 50 caractères.
- Détecte les phrases trop longues.
- Ajoute un message indiquant le résultat de l'analyse.

## Notions utilisées
- Classe abstraite et méthodes virtuelles pures.
- Héritage et polymorphisme.
- Méthode Factory `creerPlugin()`.
- Manipulation des chaînes de caractères avec `string`.
- Fonctions `find()`, `replace()` et `to_string()`.
- Conteneur `std::vector`.
- Pointeurs intelligents `std::unique_ptr`.

## Fonctionnement

L'utilisateur saisit un texte dans la console.

La Factory crée les plugins demandés et les stocke dans un vecteur.

Les plugins sont ensuite appliqués successivement au texte. Après chaque traitement, le programme affiche le nom du plugin utilisé ainsi que le texte transformé.

Le chargement des plugins est simulé à l'aide de la Factory, sans chargement réel de fichiers externes.

---

# Technologies et environnement utilisés

- **Langage :** C++
- **IDE :** Eclipse
- **Bibliothèques :** iostream, string, vector, memory, cmath
- **Standard C++ :** C++14 ou supérieur

# Compilation et exécution

Chaque exercice possède son propre programme principal (`main()`).

Pour compiler un exercice avec g++ :

```bash
g++ -std=c++14 main.cpp -o programme
```

Pour exécuter :

```bash
./programme
```

Sous Windows :

```bash
programme.exe
```

# Conclusion générale

Ce TP a permis de mettre en pratique plusieurs concepts fondamentaux de la programmation orientée objet en C++.

À travers les trois exercices, nous avons réalisé des programmes fonctionnels basés sur :
- L'abstraction pour définir des interfaces communes.
- L'héritage pour créer des classes spécialisées.
- Le polymorphisme pour utiliser différentes implémentations à travers une classe de base.
- Les pointeurs pour gérer les objets.
- Les pointeurs intelligents pour assurer une gestion automatique de la mémoire.
- Le modèle Factory pour faciliter la création des objets.

**Les trois exercices sont réalisés en C++ et conçus pour être compilés et exécutés séparément dans Eclipse.**
<img width="960" height="540" alt="image" src="https://github.com/user-attachments/assets/5093a1c0-e5db-4046-9b7b-11b7154854dd" />
