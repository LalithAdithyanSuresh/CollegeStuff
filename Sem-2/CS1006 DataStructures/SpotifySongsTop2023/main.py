import csv

File = open(r"C:\Users\lalit\OneDrive - SSN Trust\College\Sem-2\CS1006 DataStructures\SpotifySongsTop2023\spotify-2023.csv",'r')
Data = csv.reader(File)
print(type(Data))
for i in Data:
    print(i)