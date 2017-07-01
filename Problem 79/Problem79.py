
f = open("codes.txt", "r") # Open the request codes that are given in the problem

# Create an empty used to track neighbors [0] for left and [1] for right
neighbors = []
for i in range(10):
    neighbors.append([[], []])


used_numbers = [] # Track what numbers are used in the code

for line in f:
    for i in range(3):
        integer = int(line[i])
        if integer not in used_numbers:
            used_numbers.append(integer)
        if i == 0: # First number
            neighbors[integer][1].append(int(line[1])) # two right neighbors
            neighbors[integer][1].append(int(line[2]))
        elif i == 1: #Second number
            neighbors[integer][0].append(int(line[0])) # one right one left neighbor
            neighbors[integer][1].append(int(line[2]))
        elif i == 2: #Third number
            neighbors[integer][0].append(int(line[1])) # two left neighbors
            neighbors[integer][0].append(int(line[0]))
        
        neighbors[integer][0] = list(set(neighbors[integer][0])) # Take care of repeated values
        neighbors[integer][1] = list(set(neighbors[integer][1]))

answer_list = [None] * len(used_numbers) # This is going to be the answer

for i in used_numbers:
    answer_list[len(neighbors[i][0])] = i # Outputing the number in order into the list

string = "".join(str(digit) for digit in answer_list) # Convert list into a string 

print(string) # Final answer seen by user

f.close()





