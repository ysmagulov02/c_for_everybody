#include <stdio.h>
#include <stdlib.h> // random num genenrator
#include <time.h>

/*
clubs (♣), diamonds (♦), hearts (♥), and spades (♠)
*/
#define NCARDS 52
#define HAND_NCARDS 7


typedef enum suit {club, diamond, heart, spade} suit;
typedef struct card {suit suit; short pip} card;

all_cards[NCARDS] = {};


void shuffle_deck(card *deck, int n) {
    int i;
    for (i = 0; i < n; i++) {
        int j = rand() % (i+1);
        // swapping cards i and j
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}


void main() {
    // random seed generator
    srand((unsigned)time(0)); 

    // creating an array for the deck of cards
    card deck[NCARDS];
    
    
}