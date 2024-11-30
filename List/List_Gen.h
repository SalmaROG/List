#pragma once
#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class List_Gen {
private:
    Node<T>* head;
    int taille;

public:
    List_Gen();

    bool estVide() const;
    int obtenirTaille() const;

    void ajouterDebut(T elem);
    void ajouterFin(T elem);

    bool supprimer(T elem);
    bool supprimerDebut();
    bool supprimerFin();

    bool rechercher(T elem) const;
    void afficher() const;

    ~List_Gen();
};
//Constructeur
template <typename T>
List_Gen<T>::List_Gen() : head(nullptr), taille(0) {}

// Vérifie si la liste est vide
template <typename T>
bool List_Gen<T>::estVide() const {
    return (head == nullptr);
}
//La taille de la liste
template <typename T>
int List_Gen<T>::obtenirTaille() const {
    return taille;
}

// Ajouter un élément au début de la liste
template <typename T>
void List_Gen<T>::ajouterDebut(T elem) {
    Node<T>* nouveau = new Node<T>(elem);
    nouveau->next = head;
    head = nouveau;
    taille++;
}

// Ajouter un élément à la fin de la liste
template <typename T>
void List_Gen<T>::ajouterFin(T elem) {
    Node<T>* nouveau = new Node<T>(elem);
    if (estVide()) {
        head = nouveau;
    }
    else {
        Node<T>* courant = head;
        while (courant->next != nullptr) {
            courant = courant->next;
        }
        courant->next = nouveau;
    }
    taille++;
}

// Supprimer un élément spécifique
template <typename T>
bool List_Gen<T>::supprimer(T elem) {
    if (estVide()) return false;

    if (head->data == elem) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        taille--;
        return true;
    }

    Node<T>* courant = head;
    while (courant->next != nullptr && courant->next->data != elem) {
        courant = courant->next;
    }

    if (courant->next == nullptr) {
        return false; // Élément non trouvé
    }

    Node<T>* temp = courant->next;
    courant->next = courant->next->next;
    delete temp;
    taille--;
    return true;
}

// Supprimer le premier élément de la liste
template <typename T>
bool List_Gen<T>::supprimerDebut() {
    if (estVide()) return false;

    Node<T>* temp = head;
    head = head->next;
    delete temp;
    taille--;
    return true;
}

// Supprimer le dernier élément de la liste
template <typename T>
bool List_Gen<T>::supprimerFin() {
    if (estVide()) return false;

    if (head->next == nullptr) {
        // Si la liste n'a qu'un seul élément
        delete head;
        head = nullptr;
    }
    else {
        Node<T>* courant = head;
        while (courant->next->next != nullptr) {
            courant = courant->next;
        }

        delete courant->next;
        courant->next = nullptr;
    }
    taille--;
    return true;
}

// Recherche un élément dans la liste
template <typename T>
bool List_Gen<T>::rechercher(T elem) const {
    Node<T>* courant = head;
    while (courant != nullptr) {
        if (courant->data == elem) {
            return true;
        }
        courant = courant->next;
    }
    return false;
}

// Affiche les éléments de la liste
template <typename T>
void List_Gen<T>::afficher() const {
    Node<T>* courant = head;
    std::cout << "[";
    while (courant != nullptr) {
        std::cout << courant->data;
        if (courant->next != nullptr) {
            std::cout << " -> ";
        }
        courant = courant->next;
    }
    std::cout << "]" << std::endl;
}

// Destructeur
template <typename T>
List_Gen<T>::~List_Gen() {
    Node<T>* courant = head;
    while (courant != nullptr) {
        Node<T>* temp = courant;
        courant = courant->next;
        delete temp;
    }
}
