#include <iostream>
#include "List_Gen.h"

int main() {
    List_Gen<int> maListe;

    maListe.ajouterDebut(10);
    maListe.ajouterDebut(20);
    maListe.ajouterFin(30);
    maListe.afficher();

    std::cout << "Supprimer le début : " << (maListe.supprimerDebut() ? "Réussi" : "Échec") << std::endl;
    maListe.afficher();

    std::cout << "Supprimer la fin : " << (maListe.supprimerFin() ? "Réussi" : "Échec") << std::endl;
    maListe.afficher();

    std::cout << "Recherche 10 : " << (maListe.rechercher(10) ? "Trouvé" : "Non trouvé") << std::endl;
    std::cout << "Supprimer 10 : " << (maListe.supprimer(10) ? "Réussi" : "Échec") << std::endl;
    maListe.afficher();

    return 0;
}
