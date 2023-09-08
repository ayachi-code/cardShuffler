#include "../header/cards.h"

Card::Card() = default;

Card::Card(std::string nameOfCard, int typeOfCard) : nameOfCard(nameOfCard), typeOfCard(typeOfCard) {};

Cards::Cards() {
    cardsInDeck = new Card[52];
    capacity = 52;
    std::vector<std::string> nameOfCards = {"harten", "schoppen", "klaveren", "ruiten"};
    int cardCount = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 14; j++) {
            cardsInDeck[cardCount] = Card(nameOfCards.at(i), j);
            cardCount++;
        };
    }
    amountOfCards = cardCount;
};

Card Cards::top() {
    if (amountOfCards == 0) {
        return cardsInDeck[0];
    };
    return cardsInDeck[amountOfCards-1];
}

void Cards::printDeck() {
    for (int i = 0; i < amountOfCards; i++) {
        std::cout << cardsInDeck[i].getNameOfCard() << " " << cardsInDeck[i].getTypeOfCard() << std::endl;
    };  
};

void Cards::pop() {
    if (amountOfCards == 0) {
        throw std::out_of_range("There are no cards in the deck");
    };
    amountOfCards -= 1;
};

void Cards::shuffle() {
    int cardsShuffled = 0;
    Card* tempDeck = new Card[52];
    std::unordered_set<int> usedNumbers;
    int randomNumber = rand() % 52;
    while (cardsShuffled != amountOfCards) {
        if (usedNumbers.count(randomNumber) <= 0) {
            usedNumbers.insert(randomNumber);
            tempDeck[cardsShuffled] = cardsInDeck[randomNumber];
            cardsShuffled++;
        };
        randomNumber = rand() % 52;
    };
    delete[] cardsInDeck;
    cardsInDeck = tempDeck;
};

 void Cards::clearDeck() {
    amountOfCards = 0;
 };

void Cards::push(Card card) {
    cardsInDeck[amountOfCards] = card;
    amountOfCards++;
};

Cards::~Cards() {delete[] cardsInDeck;};