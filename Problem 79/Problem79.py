f = open("codes.txt", "r")


class integer:
    value = 0
    left = []
    right = []




order = []
neighbors = []

for i in range(10):
    print(i)
    neighbors.append([[], []])




for line in f:
    for i in range(3):
        integer = int(line[i])
        print("CURRENT INTEGER", integer)
        if i == 0:
            neighbors[integer][1].append(int(line[1]))
            neighbors[integer][1].append(int(line[2]))
        elif i == 1:
            neighbors[integer][0].append(int(line[0]))
            neighbors[integer][1].append(int(line[2]))
        elif i == 2:
            neighbors[integer][0].append(int(line[1]))
            neighbors[integer][1].append(int(line[0]))
        
        neighbors[integer][0] = list(set(neighbors[integer][0]))
        neighbors[integer][1] = list(set(neighbors[integer][1]))

for i in range(10):
    print(i, "  :", len(neighbors[i][1]))
    print(i, " LEFT: ", neighbors[i][0])
    print(i, "RIGHT: ", neighbors[i][1])

        





