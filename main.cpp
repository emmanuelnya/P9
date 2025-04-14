#include <iostream>
#include <ctime>
#include "comptebancaire.h"
#include "destinatario.h"

int main() {
    srand(time(0)); // Initialise le générateur de nombres aléatoires

    comptebancaire compte;
    compte.addTransaction(1500, "entrata", "2025-03-25", "stipendio");
    compte.addTransaction(300, "uscita", "2025-03-30", "Andrea Fabrizio", "IT13K1523654780000001236547");
    compte.addTransaction(1000, "entrata", "2025-04-01", "DEMIAN CANT");
    compte.addTransaction(25, "uscita", "2025-04-02", "CONAD CITY-VIA DALMAZIA");
    compte.addTransaction(0, "uscita","2025-01-31","SISAL");
    compte.affichercompte();

    return 0;
}
