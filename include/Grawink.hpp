#include "shapes/Shape.hpp"

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdint>
#include <list>

class GrawEditor
{
public:
    enum class ShapeType : uint64_t
    {
        Stroke = 1ULL << 0,
        Triangle = 1ULL << 1,
        Rectangle = 1ULL << 2,
        Pentagon = 1ULL << 3,
        Hexagon = 1ULL << 4,
        Heptagon = 1ULL << 5,
        Octogon = 1ULL << 6,
        Ellipsis = 1ULL << 7,
        All = ~0ULL
    };

    // Renvoie une référence à l'instance unique de GrawEditor
    static GrawEditor &GetEditor()
    {
        static GrawEditor instance;
        return instance;
    };
    // Ajoute un nouvel objet au canevas
    GrawEditor& add(std::shared_ptr<Shape> shape);

    // Ajoute n objets au canevas
    GrawEditor &add(std::vector<std::shared_ptr<Shape>> shapes);

    // Supprime un objet du canevas par son identifiant ou référence
    GrawEditor &remove(int shapeId);

    // Annule le dernier ajout d'objet
    GrawEditor &undo(unsigned int steps = 1);

    // Réinsère le dernier objet supprimé
    GrawEditor &redo(unsigned int steps = 1);

    // Redimensionne le canevas
    GrawEditor &resize(int width, int height);

    // Redimensionne le canevas en supprimant les objets extérieurs
    GrawEditor &crop(int x, int y, int width, int height);

    // Sélectionne les objets à exporter/afficher
    GrawEditor &select(ShapeType types);

    // Affiche l'ensemble des objets contenus dans le canevas, triés par catégorie
    GrawEditor &print();

    // Écrit le code SVG résultant des objets contenus dans le canevas
    GrawEditor &draw(const std::string &filename);

    // Crée une nouvelle instance de la classe `Shape` et retourne un pointeur vers l'objet nouvellement alloué
    template <typename Shape, typename... Args>
    std::unique_ptr<Shape> get_new(Args &&...args);

    ~GrawEditor(); // Destructeur

private:
    GrawEditor() = default;                             // Constructeur privé pour le singleton
    GrawEditor(const GrawEditor &) = delete;            // Supprime le constructeur de copie
    GrawEditor &operator=(const GrawEditor &) = delete; // Supprime l'opérateur d'affectation

    // Stockage des formes
    std::vector<std::shared_ptr<Shape>> shapes;
    // Stockage des formes ajoutées et supprimées pour les opérations Undo/Redo
    std::list<std::shared_ptr<Shape>> addedShapes;
    std::list<std::shared_ptr<Shape>> removedShapes;

protected:
    int width = 600;
    int height = 400;

    // Stockage des formes selectionnées
    ShapeType selectedShapes = ShapeType::All;
};

