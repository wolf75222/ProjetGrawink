#include <iostream>
#include "../include/Grawink.hpp"
#include "../include/utils/Color.hpp"
#include "../include/shapes/Shapes.hpp"
#include <memory>

int main() {
    GrawEditor& editor = GrawEditor::GetEditor();
    
    Point center = Point(50, 50);
    Point translate = Point(10, 10);

    Circle* s1 = new Circle(1, center, 10, 0);
    Ellipse* s2 = new Ellipse(2, center, 20, 10, 0);
    Rectangle* s3 = new Rectangle(3, center, 20, 10, 0);

    // Adding shapes s1 
    editor.Add<Circle>(&s1);

    // Deleting a shape
    editor.Delete(1); // Assuming the ID of the shape to be deleted is 1

    // Resizing and cropping the canvas
    editor.Resize(800, 600); // Resize the canvas to 800x600
    editor.Crop(100, 100, 400, 300); // Crop the canvas to a region defined by the rectangle (100,100) to (400,300)

    // Selecting shapes and printing
    editor.Select(GrawEditor::ShapeType::All); // Select all shapes // Select all shapes
    editor.Print(); // Print the details of the selected shapes

    // Exporting to SVG
    editor.ExportSVG("shapes_output.svg");

    // Testing Undo/Redo functionality
    editor.Undo(2); // Undo the last two actions
    editor.Redo(1); // Redo one action

    return 0;
}
