#include "card.h"
#include "carddeck.h"
#include <stdlib.h>
#include <time.h>


// Helper function to initialize a single pack of cards
void initializeSinglePack(struct CardDeck* deck, int offset) {
    for (int suit = Club; suit <= Diamond; ++suit) {
        for (int rank = Two; rank <= Ace; ++rank) {
            deck->cards[offset].suit = suit;
            deck->cards[offset].rank = rank;
            ++offset;
        }
    }
}

// Function to create a new card deck with a specified number of packs
struct CardDeck createCardDeck(int numPacks) {
    struct CardDeck deck;
    deck.size = numPacks * 52; // Each pack has 52 cards

    // Allocate memory for cards
    deck.cards = (struct Card*)malloc(deck.size * sizeof(struct Card));

    // Check for memory allocation errors
    if (deck.cards == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    // Initialize the deck with the specified number of packs
    int index = 0;
    for (int pack = 0; pack < numPacks; ++pack) {
        for (enum Suit suit = Club; suit <= Diamond; ++suit) {
            for (enum Rank rank = Two; rank <= Ace; ++rank) {
                deck.cards[index].suit = suit;
                deck.cards[index].rank = rank;
                ++index;
            }
        }
    }

    return deck;
}

// Function to shuffle the cards in a deck

void shuffleCardDeck(struct CardDeck* deck) {
    // Use the current time as a seed for the random number generator
    srand((unsigned int)time(NULL));

    // Perform Fisher-Yates shuffle
    for (int i = deck->size - 1; i > 0; --i) {
        // Generate a random index between 0 and i
        int j = rand() % (i + 1);

        // Swap the cards at indices i and j
        struct Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// Function to sort the cards in a deck using bubble sort
void sortCardDeck(struct CardDeck* deck) {
    for (int i = 0; i < deck->size - 1; ++i) {
        for (int j = 0; j < deck->size - i - 1; ++j) {
            // Compare and swap if necessary
            if (deck->cards[j].rank > deck->cards[j + 1].rank ||
                (deck->cards[j].rank == deck->cards[j + 1].rank && deck->cards[j].suit > deck->cards[j + 1].suit)) {
                struct Card temp = deck->cards[j];
                deck->cards[j] = deck->cards[j + 1];
                deck->cards[j + 1] = temp;
            }
        }
    }
}

// Function to draw the top card from the deck
struct Card drawCard(struct CardDeck* deck) {
    if (deck->size > 0) {
        struct Card drawnCard = deck->cards[deck->size - 1];
        --deck->size;
        return drawnCard;
    }
    else {
        // Handle drawing from an empty deck
        exit(EXIT_FAILURE);
    }
}

// Function to add a card to the top of the deck
void addCardToTop(struct CardDeck* deck, struct Card card) {
    // Increase the size of the deck by 1
    deck->size++;

    // Allocate memory for the increased size
    struct Card* temp = realloc(deck->cards, deck->size * sizeof(struct Card));

    // Check if realloc was successful
    if (temp == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    // Assign the new memory block to deck->cards
    deck->cards = temp;

    // Add the card to the top of the deck
    deck->cards[deck->size - 1] = card;
}

// Function to remove the top card from the deck
void removeCardFromTop(struct CardDeck* deck) {
    // Check if the deck is not empty
    if (deck->size > 0) {
        // Decrease the size of the deck by 1
        deck->size--;

        // Allocate memory for the decreased size
        struct Card* temp = realloc(deck->cards, deck->size * sizeof(struct Card));

        // Check if realloc was successful
        if (temp == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        // Assign the new memory block to deck->cards
        deck->cards = temp;
    }
}

// Function to print the cards in a deck
void printCardDeck(struct CardDeck deck) {
    for (int i = 0; i < deck.size; ++i) {
        printCard(deck.cards[i]);
    }
}

// Function to free the memory allocated for the deck
void freeCardDeck(struct CardDeck* deck) {
    free(deck->cards);
}

struct CardDeck createEmptyCardDeck() {
    struct CardDeck emptyDeck;
    emptyDeck.cards = NULL;
    emptyDeck.size = 0;
    return emptyDeck;
}