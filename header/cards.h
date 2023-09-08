#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>
#include <stack>

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
        std::stack<Card> cards;
        int amount;
    public:
        Cards();
        Cards(bool empty);
        void shuffle();
        Card top();
        void push();
};