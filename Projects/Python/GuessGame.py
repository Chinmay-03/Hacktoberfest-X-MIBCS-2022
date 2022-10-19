from random import randint

print('')
print('')
print('### GAME START ###')
print('')
print('')

aleatorio = randint(1, 10)
chute = 0
chances = 3

while chances != aleatorio:
    print('You have {} attempts'.format(chances))
    chute=(input('Choose a number between 1 and 10:  '))
    if chute.isnumeric():
        chute = int(chute)
        chances = chances - 1
        if chute == aleatorio:
            print('')
            print('Congratulations, you got it right!')
            print('')
            break
        else:
            if chute > aleatorio:
                print('')
                print('You made a mistake, try again!') 
                print('You have {} attempts'.format(chances))
                print('Hint, the number is smaller')   
                print('')
            else:
                print('')
                print('You made a mistake, try again')
                print('You have {} attempts'.format(chances))
                print('Hint, the number is bigger')
                print('')
        if chances == 0:
            print('')
            print('Your attempts are over, you lost')
            print('The number was {}'.format(aleatorio))
            break
print('### END OF GAME ###')