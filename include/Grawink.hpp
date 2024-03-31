#include "shapes/Shape.hpp"

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdint>
#include <list>

/**
 * @class GrawEditor
 * @brief The GrawEditor class represents an editor for creating and manipulating shapes on a canvas.
 *
 * The GrawEditor class provides various methods for adding, removing, selecting, and manipulating shapes on a canvas.
 * It also supports undo and redo operations, as well as exporting and displaying shapes in SVG format.
 * The class follows the singleton design pattern, ensuring that only one instance of GrawEditor can exist.
 */
class GrawEditor
{
public:
    /**
     * @enum ShapeType
     * @brief The ShapeType enum represents the type of the shape.
     */
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
        Polygon = 1ULL << 8,
        All = ~0ULL
    };

    /**
     * @brief GetEditor returns the unique instance of the GrawEditor class.
     * @return The unique instance of the GrawEditor class.
     * @note This method follows the singleton design pattern.
    */
    static GrawEditor &GetEditor()
    {
        static GrawEditor instance;
        return instance;
    };

    /**
     * @brief add adds a shape to the canvas.
     * @param shape The shape to add to the canvas.
     * @return A reference to the GrawEditor instance.
     * @note The shape is added to the canvas and can be manipulated using other methods.
    */
    GrawEditor &add(std::shared_ptr<Shape> shape);

    /**
     * @brief add adds multiple shapes to the canvas.
     * @param shapes A vector of shapes to add to the canvas.
     * @return A reference to the GrawEditor instance.
    */
    GrawEditor &add(std::vector<std::shared_ptr<Shape>> shapes);

    /**
     * @brief remove removes a shape from the canvas.
     * @param shapeId The ID of the shape to remove from the canvas.
     * @return A reference to the GrawEditor instance.
    */
    GrawEditor &remove(int shapeId);

    /**
     * @brief undo undoes the addition of the last shape.
     * @param steps The number of steps to undo.
     * @return A reference to the GrawEditor instance.
    */
    GrawEditor &undo(size_t steps = 1);

    // Réinsère le dernier objet supprimé
    /**
     * @brief redo redoes the addition of the last shape that was removed.
     * @param steps The number of steps to redo.
     * @return A reference to the GrawEditor instance.
    */
    GrawEditor &redo(size_t steps = 1);

    // Redimensionne le canevas
    /**
     * @brief resize resizes the canvas.
     * @param width The new width of the canvas.
     * @param height The new height of the canvas.
     * @return A reference to the GrawEditor instance.
    */
    GrawEditor &resize(int width, int height);

    // Redimensionne le canevas en supprimant les objets extérieurs
    /**
     * @brief crop crops the canvas to the specified dimensions.
     * @param x The x-coordinate of the top-left corner of the crop area.
     * @param y The y-coordinate of the top-left corner of the crop area.
     * @param width The width of the crop area.
     * @param height The height of the crop area.
     * @return A reference to the GrawEditor instance.
    */
    GrawEditor &crop(int x, int y, int width, int height);

    // Sélectionne les objets à exporter/afficher.
    // La sélection pourra se faire sous la forme d'une disjonction ("OU" binaires) de `enum ShapeType`.
    // Par exemple pour sélectionner uniquement les triangles, les rectangles et les octogones, on pourra passer en paramètre :
    //  ShapeType::Triangle | ShapeType::Rectangle | ShapeType::Octogon, ou
    //  bien l'équivalent en hexadécimal (0x46ULL), ou en décimal (70ULL).
    // Passer ShapeType::All resélectionne l'ensemble des formes du canevas.
    /**
     * @brief select selects shapes on the canvas.
     * @param types The types of shapes to select.
     * @return A reference to the GrawEditor instance.
     * @note The selection can be made using a bitwise disjunction of `enum ShapeType`.
    */
    GrawEditor &select(ShapeType types);

    // Affiche l'ensemble des objets contenus dans le canevas, triés par catégorie
    /**
     * @brief print prints the shapes on the canvas.
     * @return A reference to the GrawEditor instance.
     * @note The shapes are displayed sorted by category.
     * @note The shapes are displayed in the console.
    */
    GrawEditor &print();

    // Écrit le code SVG résultant des objets contenus dans le canevas
    /**
     * @brief draw writes the SVG code of the shapes on the canvas to a file.
     * @param filename The name of the file to write the SVG code to.
     * @return A reference to the GrawEditor instance.
    */
    GrawEditor &draw(const std::string &filename);

    // Crée une nouvelle instance de la classe `Shape` (i.e. Rectangle,
    // Triangle, Stroke, Circle, etc.) et retourne un pointeur vers l'objet nouvellement alloué.
    // Cet objet peut ensuite être transformé, passé en paramètre à `Add` ou à `Delete`.
    // template <typename Shape> Shape *GetNew( /* à vous de définir les paramètres */ );
    // avec des  surcharges de getNew pour les différents objets
    /**
     * @brief getNew creates a new instance of the specified shape class.
     * @tparam Shape The type of shape to create.
     * @tparam Args The types of the arguments to pass to the shape constructor.
     * @param args The arguments to pass to the shape constructor.
     * @return A shared pointer to the newly created shape object.
    */
    template <typename Shape, typename... Args>
    std::shared_ptr<Shape> getNew(Args&&... args) {
        return std::make_shared<Shape>(std::forward<Args>(args)...);
    }


    
    /**
     * @brief ~GrawEditor destroys the GrawEditor instance.
     * @note The destructor is private to prevent the deletion of the GrawEditor instance.
     * @note The GrawEditor instance is destroyed when the program exits.
    */
    ~GrawEditor(); // Destructeur

    /**
     * @brief GetShapeCount returns the number of objects contained in the canvas.
     * @return The number of objects contained in the canvas.
     * @note The method returns the number of shapes in the canvas.
    */
    int GetShapeCount() const; // Renvoie le nombre d'objets contenus dans le canevas

    /**
     * @brief GetSelectedShapeCount returns the number of selected objects.
     * @return The number of selected objects.
     * @note The method returns the number of selected shapes.
    */
    int GetSelectedShapeCount() const; // Renvoie le nombre d'objets sélectionnés

    /**
     * @brief reset resets the canvas.
     * @note The method resets the canvas, removing all shapes.
    */
    void reset(); // Réinitialise le canevas

    // Renvoie une chaîne de caractères représentant le type de forme
    /**
     * @brief ShapeTypeToString converts a shape type to a string.
     * @param type The shape type to convert.
     * @return A string representation of the shape type.
    */
    std::string ShapeTypeToString(ShapeType type);

    // Convertit un type de forme en ShapeType
    /**
     * @brief ConvertShapeType converts a shape type to a ShapeType.
     * @param type The shape type to convert.
     * @return The ShapeType corresponding to the shape type.
    */
    ShapeType ConvertShapeType(Shape::ShapeType type);

    /**
     * @brief GetWidth returns the width of the canvas.
     * @return The width of the canvas.
    */
    int GetWidth() const;  // Renvoie la largeur du canevas

    /**
     * @brief GetHeight returns the height of the canvas.
     * @return The height of the canvas.
    */
    int GetHeight() const; // Renvoie la hauteur du canevas

private:
    /*
    * Constructeur privé pour le singleton
    */
    GrawEditor() = default;                             // Constructeur privé pour le singleton
    GrawEditor(const GrawEditor &) = delete;            // Supprime le constructeur de copie
    GrawEditor &operator=(const GrawEditor &) = delete; // Supprime l'opérateur d'affectation

    // Stockage des formes
    std::vector<std::shared_ptr<Shape>> shapes; ///< The shapes on the canvas.

    // Stockage des formes ajoutées et supprimées pour les opérations Undo/Redo
    std::list<std::shared_ptr<Shape>> addedShapes; ///< The shapes that were added.
    std::list<std::shared_ptr<Shape>> removedShapes; ///< The shapes that were removed.

    // Stockage des formes sélectionnées
    std::vector<std::shared_ptr<Shape>> selectedShapes; ///< The selected shapes.
protected:
    int width = 600; ///< The width of the canvas.
    int height = 400; ///< The height of the canvas.
};
