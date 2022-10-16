''' To calculate salary of an employee given his basic pay(take as input from user). Calculate salary of employee. Let HRA be 10% of basic pay and TA be 5% of basic pay. Let employee pay professional tax as 2% of total salary. Calculate net salary payable after deductions.''' 

BS=int(input("Enter Basic Salary:"))
HRA=(BS*10)/100
TA=(BS*5)/100
GS=BS+HRA+TA
PT=(GS*2)/100
NS=GS-PT
print("Basic Salary is=",BS)
print("HRA=",HRA)
print("TA+",TA)
print("Gross Salary",GS)
print("Professional tax=",PT)
print("Net Salary=",NS)

"""5OUTPUT
Enter Basic Salary:50000
Basic Salary is= 50000
HRA= 5000.0
TA+ 2500.0
Gross Salary 57500.0
Professional tax= 1150.0
Net Salary= 56350.0"""