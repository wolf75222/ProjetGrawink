#include "../include/Grawink.hpp"

#include <iostream>
#include <fstream>
#include <map>

GrawEditor &GrawEditor::add(std::shared_ptr<Shape> shape)
{
    shapes.push_back(shape);
    addedShapes.push_back(shape);

    return GetEditor();
}

GrawEditor &GrawEditor::add(std::vector<std::shared_ptr<Shape>> shapes)
{
    for (const auto &shape : shapes)
    {
        this->shapes.push_back(shape);
        addedShapes.push_back(shape);
    }

    return GetEditor();
}

GrawEditor &GrawEditor::remove(int shapeId)
{
    auto it = std::find_if(shapes.begin(), shapes.end(), [shapeId](const std::shared_ptr<Shape> &shape)
                           { return shape->getId() == shapeId; });

    if (it != shapes.end())
    {
        removedShapes.push_back(std::move(*it));
        shapes.erase(it);
    }

    return GetEditor();
}

GrawEditor &GrawEditor::resize(int width, int height)
{

    auto ratio = static_cast<double>(width) / static_cast<double>(height);

    for (auto &shape : shapes)
    {
        shape->scale(ratio);
    }

    this->width = width;
    this->height = height;

    return GetEditor();
}

GrawEditor &GrawEditor::crop(int x, int y, int width, int height)
{
    std::vector<std::shared_ptr<Shape>> shapesInside;

    for (auto &shape : shapes)
    {
        if (!shape->isOutside(x, y, width, height))
        {
            // std::cout << "Shape inside: " << shape->getId() << std::endl;
            shapesInside.push_back(shape);
        }
    }

    shapes = shapesInside;

    this->width = width;
    this->height = height;

    return GetEditor();
}

// Sélectionne les objets à exporter/afficher.
// La sélection pourra se faire sous la forme d'une disjonction ("OU" binaires) de `enum ShapeType`.
// Par exemple pour sélectionner uniquement les triangles, les rectangles et les octogones, on pourra passer en paramètre :
//  ShapeType::Triangle | ShapeType::Rectangle | ShapeType::Octogon, ou
//  bien l'équivalent en hexadécimal (0x46ULL), ou en décimal (70ULL).
// Passer ShapeType::All resélectionne l'ensemble des formes du canevas.
// std::vector<std::shared_ptr<Shape>> selectedShapes;
GrawEditor &GrawEditor::select(ShapeType types)
{
    selectedShapes.clear(); // Videz le vecteur des formes sélectionnées avant de commencer

    // Si le type est All, copiez simplement toutes les formes dans selectedShapes
    if (types == ShapeType::All)
    {
        selectedShapes = shapes; // Copie toutes les formes dans selectedShapes
    }
    else
    {
        // Itère sur chaque forme dans shapes
        for (const auto &shape : shapes)
        {
            // Utilise un masque pour vérifier si le type de la forme correspond aux types spécifiés
            if (static_cast<uint64_t>(types) & static_cast<uint64_t>(shape->getType()))
            {
                selectedShapes.push_back(shape);
                //printf("Shape %d selected\n", shape->getId());
            }
/*             else
            {
                printf("Shape %d not selected\n", shape->getId());
                // type : 
                printf("Shape type : %s\n", ShapeTypeToString(ConvertShapeType(shape->getType())).c_str());
            } */
        }
    }

    return GetEditor();
}

std::string GrawEditor::ShapeTypeToString(ShapeType type)
{
    switch (type)
    {
    case ShapeType::Stroke:
        return "Stroke";
    case ShapeType::Triangle:
        return "Triangle";
    case ShapeType::Rectangle:
        return "Rectangle";
    case ShapeType::Pentagon:
        return "Pentagon";
    case ShapeType::Hexagon:    
        return "Hexagon";
    case ShapeType::Heptagon:
        return "Heptagon";
    case ShapeType::Octogon:
        return "Octogon";
    case ShapeType::Ellipsis:
        return "Ellipsis";
    case ShapeType::Polygon:
        return "Polygon";
    default:
        return "Complex";
    }
}

GrawEditor::ShapeType GrawEditor::ConvertShapeType(Shape::ShapeType type)
{
    switch (type)
    {
    case Shape::ShapeType::Stroke:
        return ShapeType::Stroke;
    case Shape::ShapeType::Triangle:
        return ShapeType::Triangle;
    case Shape::ShapeType::Rectangle:
        return ShapeType::Rectangle;
    case Shape::ShapeType::Pentagon:
        return ShapeType::Pentagon;
    case Shape::ShapeType::Hexagon:
        return ShapeType::Hexagon;
    case Shape::ShapeType::Heptagon:
        return ShapeType::Heptagon;
    case Shape::ShapeType::Octogon:
        return ShapeType::Octogon;
    case Shape::ShapeType::Ellipsis:
        return ShapeType::Ellipsis;
    case Shape::ShapeType::Polygon:
        return ShapeType::Polygon;
    default:
        return ShapeType::All;
    }
}

    

GrawEditor &GrawEditor::print()
{
    if (shapes.empty())
    {
        std::cout << "No shapes to display." << std::endl;
        return *this;
    }

    std::sort(shapes.begin(), shapes.end(), [](const std::shared_ptr<Shape> &a, const std::shared_ptr<Shape> &b)
              { return a->getType() < b->getType(); });

    ShapeType currentType = ShapeType::All;
    for (const auto &shape : shapes)
    {
        if (ConvertShapeType(shape->getType()) != currentType)
        {
            currentType = ConvertShapeType(shape->getType());
            std::cout << ShapeTypeToString(currentType) << "s:" << std::endl;
        }
        std::cout << "  " << shape->getName() << " - ID: " << shape->getId() << std::endl;
    }

    return GetEditor();
}

GrawEditor &GrawEditor::draw(const std::string &filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        file << "<svg width=\"" << width << "\" height=\"" << height << "\">" << std::endl;
        for (const auto &shape : shapes)
        {
            file << shape->draw() << std::endl;
        }
        file << "</svg>" << std::endl;
        file.close();
    }
    return GetEditor();
}

GrawEditor &GrawEditor::undo(size_t steps)
{
    steps = std::min(addedShapes.size(), steps);
    for (size_t i = 0; i < steps; i++)
    {
        if (!addedShapes.empty())
        {
            auto shape = std::move(addedShapes.back());
            shapes.pop_back();
            removedShapes.push_back(std::move(shape));
            addedShapes.pop_back();
        }
    }
    return GetEditor();
}

GrawEditor &GrawEditor::redo(size_t steps)
{
    steps = std::min(removedShapes.size(), steps); // Limite le nombre de pas à l'état actuel
    for (size_t i = 0; i < steps; i++)
    {
        if (!removedShapes.empty())
        {
            auto shape = std::move(removedShapes.back());
            shapes.push_back(shape);
            addedShapes.push_back(std::move(shape));
            removedShapes.pop_back();
        }
    }
    return GetEditor();
}


GrawEditor::~GrawEditor()
{
    shapes.clear();
    addedShapes.clear();
    removedShapes.clear();
}

int GrawEditor::GetShapeCount() const
{
    return shapes.size();
}

/* GrawEditor& GrawEditor::GetEditor() {
    static GrawEditor instance;
    return instance;
}
 */

void GrawEditor::reset()
{
    shapes.clear();
    addedShapes.clear();
    removedShapes.clear();
}

int GrawEditor::GetWidth() const
{
    return width;
}

int GrawEditor::GetHeight() const
{
    return height;
}

int GrawEditor::GetSelectedShapeCount() const
{
    return selectedShapes.size();
}