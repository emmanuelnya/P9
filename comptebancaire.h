#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H

#include <vector>
#include "transaction.h"

class comptebancaire {
private:
    double solde;
    std::vector<transaction> transactions;

public:
    comptebancaire();

    void addTransaction(double montant, std::string type, std::string date, std::string destname = "", std::string destiban = "");
    void addTransaction(const transaction& t); // surcharge

    void affichercompte() const;
    void savefile(const std::string& filename) const;

    transaction getTransactionAt(size_t index) const;
    size_t getNumeroTransazioni() const;

    void cancellaTransazione(size_t index);
    void modificaTransazione(size_t index, const transaction& nuova);
    void cercaTransazione(const std::string &nome) const;
    double getSolde() const;
};

#endif