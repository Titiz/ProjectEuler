f = open("codes.txt", "r")

neighbors = []

for i in range(10):
    neighbors.append([[], []])


used_numbers = []

for line in f:
    for i in range(3):
        integer = int(line[i])
        if integer not in used_numbers:
            used_numbers.append(integer)
        if i == 0:
            neighbors[integer][1].append(int(line[1]))
            neighbors[integer][1].append(int(line[2]))
        elif i == 1:
            neighbors[integer][0].append(int(line[0]))
            neighbors[integer][1].append(int(line[2]))
        elif i == 2:
            neighbors[integer][0].append(int(line[1]))
            neighbors[integer][0].append(int(line[0]))
        
        neighbors[integer][0] = list(set(neighbors[integer][0]))
        neighbors[integer][1] = list(set(neighbors[integer][1]))

answer_list = [None] * len(used_numbers)

for i in used_numbers:
    answer_list[len(neighbors[i][0])] = i

string = ""
for item in answer_list:
    string += str(item)

print(string)

f.close()





