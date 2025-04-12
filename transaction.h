#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "destinatario.h"

class transaction {
private:
    double montant;
    std::string type;
    std::string date;
    destinatario destinataire_info;

public:
    transaction(double montant, std::string type, std::string date, destinatario dest);

    double getMontant() const;
    std::string getType() const;
    std::string getDate() const;
    destinatario getDestinatario() const;

    std::string toString() const;
};

#endif