# Projet Grawink

![docs/grawink.webp]()

## Introduction

Le projet Grawink est une bibliothèque C++ conçue pour la création et la gestion de dessins SVG. Il permet aux utilisateurs de créer des dessins vectoriels en utilisant une variété de formes géométriques et de les exporter en format SVG. Cette bibliothèque vise à offrir une interface simple pour la programmation orientée objet et la manipulation graphique.

## Architecture du projet

Le projet est structuré comme suit :

```
ProjetGrawink/
│
├── Makefile               # Makefile pour compiler le projet
├── build/                 # Dossier pour les fichiers objets compilés
├── docs/                  # Documentation et diagrammes UML
│   └── UML/
├── include/               # Fichiers d'en-tête (.h)
│   ├── Grawink.h          # Classe principale de l'éditeur
│   ├── shapes/            # Définitions des formes géométriques
│   └── utils/             # Utilitaires (comme l'export SVG)
├── src/                   # Fichiers sources (.cpp)
│   ├── Grawink.cpp        # Implémentation de l'éditeur
│   ├── shapes/            # Implémentations des formes géométriques
│   └── utils/             # Implémentations des utilitaires
└── tests/                 # Tests unitaires
    └── test_main.cpp
```

## ToDo List

- [ ] Définir la classe de base `Shape` et ses méthodes.
- [ ] Implémenter les classes de formes géométriques : `Circle`, `Ellipse`, `Polygon`, `Rectangle`, `Triangle`.
- [ ] Développer l'utilitaire `SvgExporter` pour l'exportation SVG.
- [ ] Compléter l'implémentation de `Grawink`, le cœur de l'application.
- [ ] Écrire le code principal (`main.cpp`) pour tester la bibliothèque.
- [ ] Rédiger des tests unitaires pour valider les fonctionnalités (`test_main.cpp`).
- [ ] Documenter le projet et finaliser le README.

## Compilation et exécution

Pour compiler le projet, naviguez dans le répertoire racine du projet et exécutez :

```
make
```

Cela générera un exécutable dans le dossier `build/`. Pour lancer l'application, exécutez :

```
./build/...
```
## Contribution

Nous accueillons les contributions au projet Grawink ! Si vous souhaitez contribuer, veuillez suivre les instructions suivantes :

1. Forkez le projet.
2. Créez une branche pour votre fonctionnalité (`git checkout -b feature/nouvelleFonctionnalité`).
3. Validez vos modifications (`git commit -am 'Ajout de quelques fonctionnalités'`).
4. Poussez la branche (`git push origin feature/nouvelleFonctionnalité`).
5. Ouvrez une Pull Request.


