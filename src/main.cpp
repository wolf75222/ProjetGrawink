#include "../include/Grawink.hpp"
#include "../include/utils/Color.hpp"
#include "../include/shapes/Shapes.hpp"

#include <iostream>

int main() {
    GrawEditor& editor = GrawEditor::GetEditor();
    
    Point center = Point(50, 50);
    Point translate = Point(10, 10);

    Circle* s1 = new Circle(1, center, 10, 0);
    Ellipse* s2 = new Ellipse(2, center, 20, 10, 0);
    Rectangle* s3 = new Rectangle(3, center, 20, 10, 0);

    printf("Testing Add\n");
    editor.Add(std::shared_ptr<Shape>(s1));
    editor.Add(std::shared_ptr<Shape>(s2));
    printf("Add Ok\n");

    printf("Testing Delete\n");
    editor.Delete(1); // Assuming the ID of the shape to be deleted is 1
    printf("Delete Ok\n");

    // Resizing and cropping the canvas
    printf("Testing Resize and Crop\n");
    editor.Resize(800, 600); // Resize the canvas to 800x600
    printf("Resize Ok\n");
    editor.Crop(100, 100, 400, 300); // Crop the canvas to a region defined by the rectangle (100,100) to (400,300)
    printf("Crop Ok\n");

    // Selecting shapes and printing
    printf("Testing Select and Print\n");
    editor.Select(GrawEditor::ShapeType::All); // Select all shapes // Select all shapes
    printf("Select Ok\n");
    editor.Print(); 
    printf("Print Ok\n");

    
    
    // Exporting to SVG
    printf("Testing ExportSVG\n");
    editor.ExportSVG("shapes_output.svg");
    printf("ExportSVG Ok\n");

    // Testing Undo/Redo functionality
    printf("Testing Undo/Redo\n");
    editor.Undo(2); // Undo the last two actions
    printf("Undo Ok\n");
    editor.Redo(1); // Redo one action
    printf("Redo Ok\n");    
    return 0;
}
