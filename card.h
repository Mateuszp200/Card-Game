#pragma once
#ifndef CARD_H
#define CARD_H

// Enumeration for suits
enum Suit {
    Club,
    Spade,
    Heart,
    Diamond
};

// Enumeration for ranks
enum Rank {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

// Structure to represent a card
struct Card {
    enum Suit suit;
    enum Rank rank;
};

void printCard(struct Card card);

#endif  // CARD_H