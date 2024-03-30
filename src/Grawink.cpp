#include "../include/Grawink.hpp"

#include <iostream>
#include <fstream>

GrawEditor& GrawEditor::add(std::shared_ptr<Shape> shape) {
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
    auto it = std::find_if(shapes.begin(), shapes.end(), [shapeId](const std::shared_ptr<Shape> &shape) {
        return shape->getId() == shapeId;
    });

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

    auto ratio = static_cast<double>(width) / static_cast<double>(height);

    for (auto &shape : shapes)
    {
        if (shape->isOutside(x, y, width, height))
        {
            shape->scale(ratio);
        }
    }

    this->width = width;
    this->height = height;

    return GetEditor();
}

GrawEditor &GrawEditor::select(ShapeType types)
{
    selectedShapes = types;
    return GetEditor();
}

GrawEditor &GrawEditor::print()
{
    if (shapes.empty())
    {
        std::cout << "No shapes to display." << std::endl;
        return GetEditor();
    }

    for (const auto &shape : shapes)
    {
        if (selectedShapes == ShapeType::All || static_cast<uint64_t>(shape->getType()) & static_cast<uint64_t>(selectedShapes))
        {
            std::cout << shape->getName() << " - ID: " << shape->getId() << std::endl;
        }
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

GrawEditor &GrawEditor::undo(unsigned int steps)
{
    for (unsigned int i = 0; i < steps; i++)
    {
        if (!shapes.empty())
        {
            auto shape = std::move(shapes.back());
            removedShapes.push_back(std::move(shape));
            shapes.pop_back();
        }
    }
    return GetEditor();
}

GrawEditor &GrawEditor::redo(unsigned int steps)
{
    for (unsigned int i = 0; i < steps; i++)
    {
        if (!removedShapes.empty())
        {
            auto shape = std::move(removedShapes.back());
            shapes.push_back(std::move(shape));
            removedShapes.pop_back();
        }
    }
    return GetEditor();
}

template <typename TShape, typename... Args>
std::unique_ptr<TShape> GrawEditor::get_new(Args &&...args)
{
    return std::unique_ptr<TShape>(new TShape(std::forward<Args>(args)...));
}

GrawEditor::~GrawEditor()
{
    shapes.clear();
    addedShapes.clear();
    removedShapes.clear();
}

/* GrawEditor& GrawEditor::GetEditor() {
    static GrawEditor instance;
    return instance;
}
 */
