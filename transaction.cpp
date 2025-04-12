#include "transaction.h"
#include <stdexcept>
#include <sstream>

#include "destinatario.h"

transaction::transaction(double montant, std::string type, std::string date, destinatario dest)
    : montant(montant), type(type), date(date), destinataire_info(dest) {

    if (montant <= 0) {
        throw std::invalid_argument("L'importo deve essere maggiore di zero.");
    }

}

double transaction::getMontant() const {
    return montant;
}

std::string transaction::getType() const {
    return type;
}

std::string transaction::getDate() const {
    return date;
}

destinatario transaction::getDestinatario() const {
    return destinataire_info;
}

std::string transaction::toString() const {
    std::ostringstream oss;
    std::string segno = (type == "entrata") ? "+" : "-";
    oss << date << " | " << segno << montant << " EUR | " << destinataire_info.toString();
    return oss.str();
}