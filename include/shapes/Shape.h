#ifndef SHAPE_H
#define SHAPE_H

#include <string>

// Classe de base abstraite pour toutes les formes géométriques
class Shape {
public:
    // Destructeur virtuel pour assurer une destruction propre des classes dérivées
    virtual ~Shape() = default;

    // Méthode purement virtuelle pour dessiner la forme
    virtual std::string draw() const = 0;

    // Méthodes virtuelles pour la transformation de la forme
    virtual void translate(double dx, double dy) = 0;
    virtual void rotate(double angle) = 0;
    virtual void scale(double factor) = 0;

    // Méthodes d'accès pour les propriétés de la forme
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    // Méthode template pour la transformation générale.
    // Exemple d'utilisation: shape->transform<Rotation>(params...);
    template<typename Transformation, typename... Args>
    void transform(Args&&... args) {
        // La transformation spécifique est appliquée ici.
        // Transformation est une classe qui doit définir un opérateur ()
        // prenant en charge la transformation appropriée.
        Transformation()(*this, std::forward<Args>(args)...);
    }
};

#endif // SHAPE_H

