#include "card.h"
#include <stdio.h>

void printCard(struct Card card) {
    printf("The %s of %s.\n",
        (card.rank == Ace) ? "Ace" : (card.rank == Jack) ? "Jack" : (card.rank == Queen) ? "Queen" : (card.rank == King) ? "King" : (char)('2' + card.rank),
        (card.suit == Club) ? "Clubs" : (card.suit == Spade) ? "Spades" : (card.suit == Heart) ? "Hearts" : "Diamonds");
}