#include <gtest/gtest.h>
#include "shopping_cart.h"

// ESEMPIO PROFESSORE:
TEST(ShoppingCartTest, StartsEmptyAndAddsSuccessfully) {
    ShoppingCart cart;
    EXPECT_EQ(cart.GetItemCount(), 0);
    EXPECT_EQ(cart.GetTotalCents(), 0);
    
    cart.AddItem("Mela", 150); // 1.50 euro
    EXPECT_EQ(cart.GetItemCount(), 1);
    EXPECT_EQ(cart.GetTotalCents(), 150);
}

// TODO STUDENTE 1: Aggiungi tre prodotti diversi al carrello.
// Usa EXPECT_EQ per verificare il conteggio totale e il prezzo totale.
// Usa messaggi personalizzati << se l'asserzione fallisce.
TEST(ShoppingCartTest, CalculatesTotalForMultipleItems) {
    ShoppingCart cart;

    cart.AddItem("Banana", 100); // 1.00 euro
    cart.AddItem("Arancia", 200); // 2.00 euro
    cart.AddItem("Pera", 250); // 2.50 euro

    EXPECT_EQ(cart.GetItemCount(), 3) << "Il conteggio degli articoli dovrebbe essere 3 dopo aver aggiunto tre prodotti";
    EXPECT_EQ(cart.GetTotalCents(), 550) << "Il totale dovrebbe essere 550 centesimi dopo aver aggiunto tre prodotti";
}

// TODO STUDENTE 2: Testa l'estrazione di un prodotto esistente.
// Ricorda di controllare che il puntatore restituito da ExtractItem NON sia nullptr 
// usando ASSERT_NE prima di verificarne il nome e il prezzo.
// Dopo averlo estratto, verifica che il totale e il conteggio del carrello siano diminuiti.
// Ricordati di fare delete del puntatore estratto!
TEST(ShoppingCartTest, ExtractsExistingItemCorrectly) {
    // IL TUO CODICE QUI
    ShoppingCart cart;
    cart.AddItem("Banana", 100);
    cart.AddItem("Arancia", 200);
    EXPECT_EQ(cart.GetItemCount(), 2);
    EXPECT_EQ(cart.GetTotalCents(), 300);
    
    Item* extracted = cart.ExtractItem("Banana");
    ASSERT_NE(extracted, nullptr) << "ExtractItem should return a valid pointer for existing item";
    EXPECT_EQ(extracted->name, "Banana");
    EXPECT_EQ(extracted->price_cents, 100);
    delete extracted; // Clean-up
    EXPECT_EQ(cart.GetItemCount(), 1);
    EXPECT_EQ(cart.GetTotalCents(), 200);
}

// TODO STUDENTE 3: Testa l'estrazione di un prodotto NON esistente.
// Verifica che ExtractItem restituisca nullptr.
TEST(ShoppingCartTest, ExtractNonExistingItemReturnsNull) {
    // IL TUO CODICE QUI
}