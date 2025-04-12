#include "destinatario.h"
#include <cstdlib>
#include <sstream>

destinatario::destinatario(std::string n, std::string i) : name(std::move(n)), iban(std::move(i)) {
    Numtransaction = genererNumeroTransaction();
}

destinatario::destinatario(const std::string &n) : name(n), iban("N/A") {
    Numtransaction = genererNumeroTransaction();
}

std::string destinatario::getName() const {return name;}

std::string destinatario::getIban() const {return iban;}

std::string destinatario::getNumtransaction() const {return Numtransaction;}

std::string destinatario::genererNumeroTransaction() {return "TX-" + std::to_string(rand() % 1000000);}

std::string destinatario::toString() const {return name + "," + iban + "," + Numtransaction;}

destinatario destinatario::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::string name, iban, Numtransaction;
    getline(ss, name, ',');
    getline(ss, iban, ',');
    getline(ss, Numtransaction, ',');
    return destinatario(name, iban);
}
