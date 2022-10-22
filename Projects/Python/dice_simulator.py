import random
while True:
  print('what you want to do\n1.roll the dice\n2.To exit')
  user = int(input(">>"))
  if user==1:
    number = random.randint(1,6)
    print(number)
  else:
    break