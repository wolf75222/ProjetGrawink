#include <gtest/gtest.h>
#include <memory>
#include "../include/Grawink.hpp"
#include "../include/utils/Color.hpp"
#include "../include/shapes/Shapes.hpp"

TEST(GrawEditorTest, AddShape)
{
    GrawEditor &editor = GrawEditor::GetEditor();
    editor.reset();
    Point p = Point(100, 110);
    Circle *head = new Circle(1, p, 40, 0);
    editor.add(std::shared_ptr<Shape>(head));
    ASSERT_EQ(editor.GetShapeCount(), 1);
}

TEST(GrawEditorTest, AddMultipleShapes)
{
    GrawEditor &editor = GrawEditor::GetEditor();

    editor.reset();

    Point p1 = Point(100, 110);
    Circle *circle = new Circle(1, p1, 40, 0);

    Point p2 = Point(200, 210);
    Rectangle *rectangle = new Rectangle(2, p2, 50, 60, 0);

    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::shared_ptr<Shape>(circle));
    shapes.push_back(std::shared_ptr<Shape>(rectangle));

    editor.add(shapes);

    ASSERT_EQ(editor.GetShapeCount(), 2);
}

TEST(GrawEditorTest, RemoveShape)
{
    GrawEditor &editor = GrawEditor::GetEditor();

    editor.reset();

    Point p1 = Point(100, 110);
    Circle *circle = new Circle(1, p1, 40, 0);

    Point p2 = Point(200, 210);
    Rectangle *rectangle = new Rectangle(2, p2, 50, 60, 0);

    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::shared_ptr<Shape>(circle));
    shapes.push_back(std::shared_ptr<Shape>(rectangle));

    editor.add(shapes);

    editor.remove(1);

    ASSERT_EQ(editor.GetShapeCount(), 1);
}

TEST(GrawEditorTest, UndoAddition)
{
    GrawEditor &editor = GrawEditor::GetEditor();

    editor.reset();

    Point p1 = Point(100, 110);
    Circle *circle = new Circle(1, p1, 40, 0);

    Point p2 = Point(200, 210);
    Rectangle *rectangle = new Rectangle(2, p2, 50, 60, 0);

    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::shared_ptr<Shape>(circle));
    shapes.push_back(std::shared_ptr<Shape>(rectangle));

    editor.add(shapes);

    // Annule l'ajout
    editor.undo(1);

    // Vérifie que les deux formes sont présentes après undo
    ASSERT_EQ(editor.GetShapeCount(), 1);
}

TEST(GrawEditorTest, RedoAddition)
{
    GrawEditor &editor = GrawEditor::GetEditor();

    editor.reset();

    Point p1 = Point(100, 110);
    Circle *circle = new Circle(1, p1, 40, 0);

    Point p2 = Point(200, 210);
    Rectangle *rectangle = new Rectangle(2, p2, 50, 60, 0);

    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::shared_ptr<Shape>(circle));
    shapes.push_back(std::shared_ptr<Shape>(rectangle));

    editor.add(shapes);

    // Annule l'ajout
    editor.undo(1);

    // Réinsère les formes
    editor.redo(1);

    // Vérifie que les deux formes sont présentes après undo
    ASSERT_EQ(editor.GetShapeCount(), 2);
}

TEST(GrawEditorTest, Resize)
{
    GrawEditor &editor = GrawEditor::GetEditor();

    editor.reset();

    Point p1 = Point(100, 110);
    Circle *circle = new Circle(1, p1, 40, 0);

    Point p2 = Point(200, 210);
    Rectangle *rectangle = new Rectangle(2, p2, 50, 60, 0);

    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::shared_ptr<Shape>(circle));
    shapes.push_back(std::shared_ptr<Shape>(rectangle));

    editor.add(shapes);

    editor.resize(800, 600);

    ASSERT_EQ(editor.GetWidth(), 800);
    ASSERT_EQ(editor.GetHeight(), 600);
}

// test crop : Redimensionne le canevas en supprimant les objets extérieurs
TEST(GrawEditorTest, Crop)
{
    GrawEditor &editor = GrawEditor::GetEditor();

    editor.reset();

    Point p1 = Point(100, 110);
    Circle *circle = new Circle(1, p1, 40, 0);

    Point p2 = Point(200, 210);
    Rectangle *rectangle = new Rectangle(2, p2, 50, 60, 0);

    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::shared_ptr<Shape>(circle));
    shapes.push_back(std::shared_ptr<Shape>(rectangle));

    editor.add(shapes);

    editor.crop(0, 0, 100, 100);

    ASSERT_EQ(editor.GetShapeCount(), 1);
}

// test select : Sélectionne les objets à exporter/afficher GetSelectedShapeCount()
TEST(GrawEditorTest, Select)
{
    GrawEditor &editor = GrawEditor::GetEditor();

    editor.reset();

    Point p1 = Point(100, 110);
    Circle *circle = new Circle(1, p1, 40, 0);

    Point p2 = Point(200, 210);
    Rectangle *rectangle = new Rectangle(2, p2, 50, 60, 0);

    Polygon *polygon = new Polygon(3, p2, 0, Point(100, 100), Point(200, 100), Point(200, 200), Point(100, 200), Point(50, 150));


    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::shared_ptr<Shape>(circle));
    shapes.push_back(std::shared_ptr<Shape>(rectangle));
    shapes.push_back(std::shared_ptr<Shape>(polygon));

    editor.add(shapes);

    editor.select(GrawEditor::ShapeType::Pentagon);

    ASSERT_EQ(editor.GetSelectedShapeCount(), 1);
}

/* 
TEST(GrawEditorTest, Print)
{
    GrawEditor &editor = GrawEditor::GetEditor();

    editor.reset();

    Point p1 = Point(100, 110);
    Circle *circle = new Circle(1, p1, 40, 0);

    Point p2 = Point(200, 210);
    Rectangle *rectangle = new Rectangle(2, p2, 50, 60, 0);

    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::shared_ptr<Shape>(circle));
    shapes.push_back(std::shared_ptr<Shape>(rectangle));

    editor.add(shapes);

    editor.print();

} */

// test draw 
TEST(GrawEditorTest, Draw)
{
    GrawEditor &editor = GrawEditor::GetEditor();

    editor.reset();

    Point p1 = Point(100, 110);
    Circle *circle = new Circle(1, p1, 40, 0);

    Point p2 = Point(200, 210);
    Rectangle *rectangle = new Rectangle(2, p2, 50, 60, 0);

    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::shared_ptr<Shape>(circle));
    shapes.push_back(std::shared_ptr<Shape>(rectangle));

    editor.add(shapes);

    editor.draw("test.svg");

    std::ifstream file("test.svg");
    ASSERT_TRUE(file.good());
}

/*
    template <typename Shape, typename... Args> Shape *GetNew(Args &&... args)
    {
        return new Shape(std::forward<Args>(args)...);
    }
*/


// test GetNew
TEST(GrawEditorTest, GetNew)
{
    GrawEditor &editor = GrawEditor::GetEditor();

    editor.reset();

    // circle 
    Point p1 = Point(100, 110);
    Circle *circle = new Circle(1, p1, 40, 0);

    
    // rectangle
    Point p2 = Point(200, 210);
    Rectangle *rectangle = new Rectangle(2, p2, 50, 60, 0);


    // getnew 
    std::shared_ptr<Shape> circlePtr = editor.getNew<Circle>(1, p1, 40, 0);
    std::shared_ptr<Shape> rectanglePtr = editor.getNew<Rectangle>(2, p2, 50, 60, 0);


    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::shared_ptr<Shape>(circlePtr));
    shapes.push_back(std::shared_ptr<Shape>(rectanglePtr));
    
    editor.add(shapes);

    ASSERT_EQ(editor.GetShapeCount(), 2);
}



int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}