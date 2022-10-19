print('')
print('')
print('#### WELCOME TO CALCULATOR ####')
print('')
print('')

n1=int(input('Type the first number:  '))
n2=int(input('Type the second number:  '))
sinal=str(input('Enter the operation symbol:  '))
soma= n1 + n2
subtracao= n1 - n2
multiplicacao= n1 * n2
divisao= n1 / n2

if sinal == '+':
    print('The result is {}'.format(soma))
if sinal == '-':
    print('The result is {}'.format(subtracao))
if sinal == '*':
    print('The result is {}'.format(multiplicacao))
if sinal == '/':
    print('The result is {}'.format(divisao))