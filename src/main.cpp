#include "../header/cards.h"

class Player {
    private:
        std::string name;
        std::vector<Card> playersCards;
        int score;
    public:
        Player (std::string naam) : name(name) {};
};

class Game {
    private:
        bool gameState;
        std::vector<Player> players;
        Cards gameCards;
    public:
        bool getGameState () {return gameState;}; 
        Game () {gameState = true;};
        int join (Player player) {
            if (players.size() >= 2) {
                return -1;
            };
            players.push_back(player);
            return 0;
        };
};

int main() {
    char option;
    std::string playerName1, playerName2;

    std::cout << "Welcome to the game Bullying!!!" << std::endl;
    std::cout << "Press 1 to start a game!" << std::endl;
    std::cout << "Type your option: ";
    std::cin >> option;

    if (option == 'q') {exit(1);};

    Game game;
    std::cout << "Type name for player 1 and player 2";
    std::cin >> playerName1 >> playerName2;
    game.join(playerName1);
    game.join(playerName2);
    while (game.getGameState()) {


    };
    return 0;
}; 