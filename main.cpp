#include <iostream>
#include <vector>

class Cards {
    private:
        class Card {
            private:
                std::string nameOfCard;
                int typeOfCard;
            public:
                Card () = default;
                Card (std::string nameOfCard, int typeOfCard) : nameOfCard(nameOfCard), typeOfCard(typeOfCard) {};
                std::string getNameOfCard() {return nameOfCard;};
                int getTypeOfCard() {return typeOfCard;};
                void setNameOfCard(std::string newName) {nameOfCard = newName;};
                void setTypeOfCard(int newType) {typeOfCard = newType;};
        };
        Card* cardsInDeck;
        int amountOfCards;
    public:
        Cards() {
            cardsInDeck = new Card[52];
            std::vector<std::string> nameOfCards = {"harten", "schoppen", "klaveren", "ruiten"};
            int cardCount = 0;
            for (int i = 0; i < nameOfCards.size(); i++) {
                for (int j = 1; j < 14; j++) {
                    cardsInDeck[cardCount] = Card(nameOfCards.at(i), j);
                    cardCount++;
                };
            }
            amountOfCards = cardCount;
        };
        ~Cards() {delete[] cardsInDeck;};
        void printDeck() {
            for (int i = 0; i < amountOfCards; i++) {
                std::cout << cardsInDeck[i].getNameOfCard() << "\t" << cardsInDeck[i].getTypeOfCard() << std::endl;
            };  
        };
};


int main(int argc, char const *argv[])
{
    Cards paket1;
    return 0;
}
