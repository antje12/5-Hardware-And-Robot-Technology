#The constructor for node objects
class Node:
    def __init__(self, name, x, y, neighbours):
        self.name = name
        self.x = x
        self.y = y
        self.neighbours = neighbours

#A weighted graph of nodes
graph = {
    'A' : Node('A', 4, 1, ['B', 'C', 'D']),
    'B' : Node('B', 4, 2, ['A', 'E', 'F']),
    'C' : Node('C', 5, 2, ['A', 'G', 'H']),
    'D' : Node('D', 6, 2, ['A', 'I', 'J']),
    'E' : Node('E', 1, 7, ['B', 'K']),
    'F' : Node('F', 2, 7, ['B', 'K']),
    'G' : Node('G', 5, 4, ['C', 'K']),
    'H' : Node('H', 6, 4, ['C', 'K']),
    'I' : Node('I', 6, 3, ['D', 'K']),
    'J' : Node('J', 7, 3, ['D', 'K']),
    'K' : Node('K', 3, 6, ['E', 'F', 'G', 'H', 'I', 'J'])
}

#A dictionary used to store the travelled path (neighbour=key, parent=value)
path = {}

#aStar(startNode, endNode)
    #openList - used to store the nodes yet to be visited
    #closedList - used to store the nodes already visited

    #calculate the g-, h-, and f-values of the startNode, and add it to the openList

    #while there are nodes in the openList:
        #pop the node with the smallest f-value from the openList and set it as the currentNode
        #add the currentNode to the closed list

        #if the currentNode is equal to the goalNode
            #break

        #For each of neighbourNode to the currentNode:
            #if the neighbourNode is in the closed list:
                #skip and continue with the next neighbour
            
            #calculate the g-, h-, and f-values of the neighbourNode

            #if the neighbourNode is in the openList and its g-value is larger than the one of that:
                #skip and continue with the next neighbour
            #else:
                #add the neighbourNode to the openList
                #add the neighbourNode (key) and the currentNode (value) to the path

#printPath(path, currentNode)
    #print currentNode

    #while currentNode in path:
        #set currentNode as path(currentNode)
        #print currentNode

#call - aStar(startNode, goalNode)
#call - printPath(path, goalNode)
