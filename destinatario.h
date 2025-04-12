#ifndef DESTINATARIO_H
#define DESTINATARIO_H

#include <string>

class destinatario {
private:
    std::string name;
    std::string iban;
    std::string Numtransaction;

public:
    destinatario(std::string n, std::string i);
    destinatario(const std::string &n);

    std::string getName() const;
    std::string getIban() const;
    std::string getNumtransaction() const;

    static std::string genererNumeroTransaction();
    std::string toString() const;
    static destinatario fromString(const std::string& line);
};

#endif // DESTINATARIO_H
