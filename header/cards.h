#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>

class Card {
     private:
        std::string nameOfCard;
        int typeOfCard;
    public:
        Card ();
        Card (std::string nameOfCard, int typeOfCard);
        std::string getNameOfCard() {return nameOfCard;};
        int getTypeOfCard() {return typeOfCard;};
        void setNameOfCard(std::string newName) {nameOfCard = newName;};
        void setTypeOfCard(int newType) {typeOfCard = newType;};
};

class Cards {
    private:
        Card* cardsInDeck;
        int amountOfCards;
        int capacity;
    public:
        Cards();
        ~Cards();
        void printDeck();
        Card getLastCard();
        void pop();
        void shuffle ();
};