# Get the name of the players and their scored and print the range of players in the range given by the user

Scores =dict([(input("ENter Name : "),int(input("Enter Score : "))) for x in range(int(input("Enter number of Players : ")))])
a = int(input("Enter starting Range : "))
b = int(input("Enter Ending Range : "))

for i in Scores:
    if Scores[i] <=b and Scores[i] >= a:
        print(i," : ",Scores[i])