#pragma once
#ifndef CARDDECK_H
#define CARDDECK_H

#include "card.h"

// Structure to represent a deck of cards
struct CardDeck {
    struct Card* cards;
    int size;  // Number of cards in the deck
};


// Function to create a new card deck with a specified number of packs
struct CardDeck createCardDeck(int numPacks);

// Function to shuffle the cards in a deck
void shuffleCardDeck(struct CardDeck* deck);

// Function to sort the cards in a deck using bubble sort
void sortCardDeck(struct CardDeck* deck);

// Function to draw the top card from the deck
struct Card drawCard(struct CardDeck* deck);

// Function to add a card to the top of the deck
void addCardToTop(struct CardDeck* deck, struct Card card);

// Function to add a card at a random location in the deck
void addCardAtRandom(struct CardDeck* deck, struct Card card);

// Function to remove the top card from the deck
void removeCardFromTop(struct CardDeck* deck);

// Function to remove a specific card from the deck
void removeCard(struct CardDeck* deck, int index);

// Function to print the cards in a deck
void printCardDeck(struct CardDeck deck);

// Function to free the memory allocated for the deck
void freeCardDeck(struct CardDeck* deck);

struct CardDeck createEmptyCardDeck();

#endif  // CARDDECK_H