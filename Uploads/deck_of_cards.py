from random import shuffle, choice

""" I created this program just for fun, it returns any amount of unique cards less than 52. 
You can use this package to create any game you want. (I used it for Poker)"""

def assign_cards(set_of_cards):
    if  set_of_cards <= 0 or set_of_cards > 52:
        return

    cards = {
        "NUM" : ["Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "King", "Queen"],
        "SUIT":  ["Diamond", "Heart", "Club", "Spade"]
    }

    shuffle(cards["NUM"])
    shuffle(cards["SUIT"])

    assigned_cards = set()

    while True:
        assigned_cards.add(choice(cards["NUM"]) + "-" + choice(cards["SUIT"]))
        if len(assigned_cards) == set_of_cards:
            break

    return assigned_cards
