#include "../include/Grawink.hpp"
#include "../include/utils/Color.hpp"
#include "../include/shapes/Shapes.hpp"

#include <iostream>

int main() {
    GrawEditor& editor = GrawEditor::GetEditor();
    
    Point p = Point(100, 110);
    Circle* head = new Circle(1, p, 40, 0);

    p = Point(60, 110);
    Rectangle* body = new Rectangle(2, p, 80, 80, 0);

    p = Point(70, 110);
    Ellipse* visor = new Ellipse(3, p, 25, 20, 0);

    p = Point(60, 190);
    Rectangle* left_leg = new Rectangle(4, p, 25, 20, 0);

    p = Point(115, 190);
    Rectangle* right_leg = new Rectangle(5, p, 25, 20, 0);

    p = Point(140, 110);
    Rectangle* backpack = new Rectangle(6, p, 20, 60, 0);

    editor.Add(std::shared_ptr<Shape>(head));
    editor.Add(std::shared_ptr<Shape>(body));
    editor.Add(std::shared_ptr<Shape>(visor));
    editor.Add(std::shared_ptr<Shape>(left_leg));
    editor.Add(std::shared_ptr<Shape>(right_leg));
    editor.Add(std::shared_ptr<Shape>(backpack));

    Color black = Color(0, 0, 0, 1);
    Color red = Color(255, 0, 0, 1);
    Color light_blue = Color(3, 252, 244, 0.8);

    head->setStrokeColor(black);
    head->setFillColor(red);
    body->setStrokeColor(black);
    body->setFillColor(red);
    backpack->setStrokeColor(black);
    backpack->setFillColor(red);
    visor->setFillColor(light_blue);
    visor->setStrokeColor(black);
    left_leg->setStrokeColor(black);
    left_leg->setFillColor(red);
    right_leg->setStrokeColor(black);
    right_leg->setFillColor(red);


    printf("Testing Delete\n");
    // editor.Delete(1); // Assuming the ID of the shape to be deleted is 1
    printf("Delete Ok\n");

    // Resizing and cropping the canvas
    printf("Testing Resize and Crop\n");
    editor.Resize(2000, 2000); // Resize the canvas to 800x600
    printf("Resize Ok\n");
    editor.Crop(-1000, -1000, 1000, 1000); // Crop the canvas to a region defined by the rectangle (100,100) to (400,300)
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
