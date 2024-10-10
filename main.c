#include <stdio.h>
#include <stdlib.h>
#include "carddeck.h"

void dealInitialCards(struct CardDeck* hiddenDeck, struct CardDeck* player1, struct CardDeck* player2);
void playGame(struct CardDeck* hiddenDeck, struct CardDeck* player1, struct CardDeck* player2, struct CardDeck* playedDeck);

int main() {
    // Set the number of packs of cards to 1
    int numPacks = 1;

    // Create an initialised and shuffled CardDeck for the hidden deck
    struct CardDeck hiddenDeck = createCardDeck(numPacks);
    shuffleCardDeck(&hiddenDeck);

    // Create CardDecks for players and the played deck
    struct CardDeck player1 = createEmptyCardDeck();
    struct CardDeck player2 = createEmptyCardDeck();
    struct CardDeck playedDeck = createEmptyCardDeck();

    // Deal initial cards to players
    dealInitialCards(&hiddenDeck, &player1, &player2);

    // Sort the card deck for each player and print the cards of each player
    sortCardDeck(&player1);
    sortCardDeck(&player2);

    printf("Player 1's cards:\n");
    printCardDeck(player1);

    printf("\nPlayer 2's cards:\n");
    printCardDeck(player2);

    // Play the card game
    playGame(&hiddenDeck, &player1, &player2, &playedDeck);

    // Free the memory allocated for the decks
    freeCardDeck(&hiddenDeck);
    freeCardDeck(&player1);
    freeCardDeck(&player2);
    freeCardDeck(&playedDeck);

    return 0;
}

void dealInitialCards(struct CardDeck* hiddenDeck, struct CardDeck* player1, struct CardDeck* player2) {
    // Deal 8 cards to each player
    for (int i = 0; i < 8; ++i) {
        addCardToTop(player1, drawCard(hiddenDeck));
        addCardToTop(player2, drawCard(hiddenDeck));
    }
}

void playGame(struct CardDeck* hiddenDeck, struct CardDeck* player1, struct CardDeck* player2, struct CardDeck* playedDeck) {
    while (player1->size > 0 && player2->size > 0) {
        // Debug: Print the current state of decks
        printf("\nPlayer 1's cards:\n");
        printCardDeck(*player1);

        printf("\nPlayer 2's cards:\n");
        printCardDeck(*player2);

        // Remove the topmost card from the hidden deck, print it to the screen, and move it to the played deck
        struct Card topCard = drawCard(hiddenDeck);
        printf("\nTop card from the hidden deck: ");
        printCard(topCard);

        addCardToTop(playedDeck, topCard);

        // Player one's turn
        printf("\nPlayer 1's turn:\n");
        if (player1->cards[0].suit == topCard.suit || player1->cards[0].rank == topCard.rank) {
            // Player one has a matching card, play it
            printf("Player 1 played card: ");
            printCard(player1->cards[0]);
            addCardToTop(playedDeck, player1->cards[0]);
            removeCardFromTop(player1);
        }
        else {
            // Player one picks the topmost card from the shuffled deck
            struct Card pickedCard = drawCard(hiddenDeck);
            addCardToTop(player1, pickedCard);
            printf("Player 1 picks card from the shuffled deck: ");
            printCard(pickedCard);

            // Sort player one's card deck
            sortCardDeck(player1);
        }

        // Print all the cards of player one
        printf("Player 1's cards:\n");
        printCardDeck(*player1);

        // Player two's turn
        printf("\nPlayer 2's turn:\n");
        if (player2->cards[0].suit == topCard.suit || player2->cards[0].rank == topCard.rank) {
            // Player two has a matching card, play it
            printf("Player 2 played card: ");
            printCard(player2->cards[0]);
            addCardToTop(playedDeck, player2->cards[0]);
            removeCardFromTop(player2);
        }
        else {
            // Player two picks the topmost card from the shuffled deck
            struct Card pickedCard = drawCard(hiddenDeck);
            addCardToTop(player2, pickedCard);
            printf("Player 2 picks card from the shuffled deck: ");
            printCard(pickedCard);

            // Sort player two's card deck
            sortCardDeck(player2);
        }

        // Print all the cards of player two
        printf("Player 2's cards:\n");
        printCardDeck(*player2);
    }

    // Determine the winner
    if (player1->size == 0) {
        printf("\nPlayer 1 wins!\n");
    }
    else {
        printf("\nPlayer 2 wins!\n");
    }
}
