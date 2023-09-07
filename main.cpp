#include <iostream>
#include <vector>

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

class Cards {
    private:
        Card* cardsInDeck;
        int amountOfCards;
        int capacity;
    public:
        Cards() {
            cardsInDeck = new Card[52];
            capacity = 52;
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
        Card getLastCard() {
            return cardsInDeck[amountOfCards-1];
        };
        void pop() {
            if (amountOfCards == 0) {
                throw std::out_of_range("There are no cards in the deck");
            }
            amountOfCards -= 1;
        };
};

int main(int argc, char const *argv[])
{
    Cards paket1;
    Card lastCard = paket1.getLastCard();
    paket1.pop();
    Card lastCard2 = paket1.getLastCard();
    return 0;
}
