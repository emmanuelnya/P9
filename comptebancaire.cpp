#include "comptebancaire.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

#include "destinatario.h"

comptebancaire::comptebancaire() : solde(0.0) {}

void comptebancaire::addTransaction(double montant, std::string type, std::string date, std::string destname, std::string destiban) {
    try{
        transaction t(montant, type, date, destinatario(destname, destiban));
        addTransaction(t); // appel de la version surchargée
    }catch (const std::exception& e) {
        std::cerr<<"Errore durante la creazione della transazione"<< e.what()<<std::endl;
    }
}


void comptebancaire::addTransaction(const transaction& t) {
    try {
        if (t.getType() == "uscita" && t.getMontant() > solde) {
            throw std::invalid_argument("Fondi insufficienti.");
        }
        transactions.push_back(t);
        solde += (t.getType() == "entrata") ? t.getMontant() : -t.getMontant();
    }catch (const std::exception& e) {
        std::cerr<<"Errore durante l'aggiunta della transazione"<< e.what()<<std::endl;
    }
}

void comptebancaire::affichercompte() const {
    std::cout << "💼 Solde attuale: " << solde << " EUR\n";
    for (const auto& t : transactions) {
        std::cout << t.toString() << std::endl;
    }
}

void comptebancaire::savefile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Errore: impossibile aprire il file." << std::endl;
        return;
    }

    for (const auto& t : transactions) {
        file << t.toString() << std::endl;
    }
}

transaction comptebancaire::getTransactionAt(size_t index) const {
    if (index >= transactions.size()) {
        throw std::out_of_range("Indice fuori intervallo.");
    }
    return transactions[index];
}

size_t comptebancaire::getNumeroTransazioni() const {
    return transactions.size();
}

void comptebancaire::cancellaTransazione(size_t index) {
    if (index >= transactions.size()) {
        throw std::out_of_range("Indice non valido.");
    }
    const transaction& t= transactions[index];
    solde-=(t.getType()=="entrata") ? t.getMontant() : -t.getMontant();
    transactions.erase(transactions.begin() + index);
}

void comptebancaire::modificaTransazione(size_t index, const transaction& nuova) {
    cancellaTransazione(index);
    addTransaction(nuova);
}

void comptebancaire::cercaTransazione(const std::string& nome)const {
    bool trovato = false;
    std::cout<< "risultato per nome: " << nome << std::endl;
    for (const auto& t : transactions) {
        if (t.getDestinatario().getName() == nome) {
            trovato=true;
            std::cout << "Date:"<<t.getDate()
                      << " | type:"<<t.getType()
                      <<" | Montant:"<<t.getMontant()
                       << "| IBAN:"<<t.getDestinatario().getIban()
            <<"| Numero di transazione: "<<t.getDestinatario().getNumtransaction()
            <<std::endl;
        }
    }
    if (!trovato) {
        std::cout<<"nessun transazione trovata."<<std::endl;
    }
}

double comptebancaire::getSolde() const {
    return solde;
}