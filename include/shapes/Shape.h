#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <vector>

// Définition de la structure pour les points, utile pour les transformations
struct Point {
    double x, y;
};

// Classe de base abstraite Shape pour toutes les formes géométriques
class Shape {
public:
    virtual ~Shape() {}

    // Méthode virtuelle pure pour dessiner la forme, retournant une représentation SVG sous forme de chaîne de caractères
    virtual std::string toSVG() const = 0;

    // Méthodes pour les transformations géométriques de base
    virtual void translate(double dx, double dy) = 0;
    virtual void rotate(double angle, const Point& center) = 0;
    virtual void scale(double scaleFactor) = 0;
    
    // Méthodes pour les transformations de couleur
    virtual void setFill(const std::string& color) = 0;
    virtual void setOpacity(double opacity) = 0;
    virtual void setStrokeColor(const std::string& color) = 0;
    virtual void setStrokeWidth(double width) = 0;


    // Sélecteurs pour les opérations de gestion de la bibliothèque
    virtual bool isSelected() const = 0;
    virtual void select(bool select) = 0;

    // Retourne le type de la forme en tant que chaîne pour faciliter le tri et l'affichage
    virtual std::string type() const = 0;
    
    // Retourne l'identifiant unique de la forme 
    virtual int id() const = 0; 

    // Couleur de remplissage de la forme 
    virtual std::string fill() const = 0;

    // Opacité de la forme 
    virtual double opacity() const = 0;
    
    // Couleur du trait
    virtual std::string strokeColor() const = 0;
    
    // Épaisseur du trait
    virtual double strokeWidth() const = 0;
    
    // Méthode pour appliquer une transformation à la forme complexe 
    virtual void applyTransformation(const std::string& transform) = 0;

    // Méthode pour afficher les informations de débogage de la forme 
    virtual void printDebugInfo() const = 0;


  
};

#endif // SHAPE_H


