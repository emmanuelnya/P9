#include <gtest/gtest.h>
#include "../transaction.h"
#include "../destinatario.h"
#include "../comptebancaire.h"

// DESTINATARIO_test
TEST(DestinatarioTest, CreationStandard) {
    destinatario d("Mario Rossi", "IT1234567890");
    EXPECT_EQ(d.getName(), "Mario Rossi");
    EXPECT_EQ(d.getIban(), "IT1234567890");
}

TEST(DestinataireTest, CreationSansIban) {
    destinatario d("Supermercato");
    EXPECT_EQ(d.getIban(), "N/A");
    EXPECT_EQ(d.getName(), "Supermercato");
}

// TRANSACTION_test
TEST(TransactionTest, CreationValide) {
    destinatario d("Cliente", "IT9876543210");
    transaction t(150, "entrata", "2025-03-01", d);
    EXPECT_EQ(t.getMontant(), 150);
    EXPECT_EQ(t.getType(), "entrata");
    EXPECT_EQ(t.getDate(), "2025-03-01");
    EXPECT_EQ(t.getDestinatario().getName(), "Cliente");
}

TEST(TransactionTest, MontantInvalide) {
    destinatario d("Client", "IT0000000000");
    EXPECT_THROW(transaction(0, "uscita", "2025-03-01", d), std::invalid_argument);
    EXPECT_THROW(transaction(-50, "uscita", "2025-03-01", d), std::invalid_argument);
}
// COMPTEBANCAIRE_test
TEST(CompteBancaireTest, AjoutEntrataEtUscita) {
    comptebancaire compte;
    compte.addTransaction(100, "entrata", "2025-04-01", "Marco", "IT001");
    compte.addTransaction(30, "uscita", "2025-04-02", "Spesa", "IT002");
    EXPECT_DOUBLE_EQ(compte.getSolde(), 70);
    EXPECT_EQ(compte.getNumeroTransazioni(), 2);
}

TEST(CompteBancaireTest, SaldoInsufficienteNonAjoute) {
    comptebancaire compte;
    compte.addTransaction(50, "entrata", "2025-04-01", "Pag", "IT001");
    compte.addTransaction(100, "uscita", "2025-04-02", "Fail", "IT002"); // Trop élevé
    EXPECT_DOUBLE_EQ(compte.getSolde(), 50); // inchangé
    EXPECT_EQ(compte.getNumeroTransazioni(), 1); // seulement l’entrée
}

TEST(CompteBancaireTest, SuppressionTransazione) {
    comptebancaire compte;
    compte.addTransaction(100, "entrata", "2025-04-01", "Marco", "IT001");
    compte.cancellaTransazione(0);
    EXPECT_EQ(compte.getNumeroTransazioni(), 0);
    EXPECT_DOUBLE_EQ(compte.getSolde(), 0);
}

TEST(CompteBancaireTest, ModificationTransazione) {
    comptebancaire compte;
    compte.addTransaction(200, "entrata", "2025-04-01", "Lavoro", "IT100");
    compte.addTransaction(100,"entrata","2025-04-02","SISAL");
    transaction modif(50, "uscita", "2025-04-03", destinatario("Spesa", "IT200"));
    compte.modificaTransazione(0, modif);
    size_t lastIndex = compte.getNumeroTransazioni()-1;
    EXPECT_EQ (compte.getTransactionAt(lastIndex).getType(), "uscita");
    EXPECT_EQ(compte.getNumeroTransazioni(), 2);
    EXPECT_EQ(compte.getTransactionAt(lastIndex).getType(), "uscita");
    EXPECT_DOUBLE_EQ(compte.getSolde(), 50);
}

TEST(CompteBancaireTest, RechercheParNom) {
    comptebancaire compte;
    compte.addTransaction(100, "entrata", "2025-04-03", "Mario", "IT123");
    int index = compte.cercaTransazione("Mario");
    EXPECT_EQ(index, 0);
    EXPECT_EQ(compte.getTransactionAt(index).getDestinatario().getName(), "Mario");
}