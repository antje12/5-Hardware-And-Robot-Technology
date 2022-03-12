#An unweighted graph of nodes
graph = {
    'A' : ['B', 'C', 'D'],
    'B' : ['A', 'E', 'F'],
    'C' : ['A', 'G', 'H'],
    'D' : ['A', 'I', 'J'],
    'E' : ['B', 'K'],
    'F' : ['B', 'K'],
    'G' : ['C', 'K'],
    'H' : ['C', 'K'],
    'I' : ['D', 'K'],
    'J' : ['D', 'K'],
    'K' : ['E', 'F', 'G', 'H', 'I', 'J']
}

#A dictionary used to store the travelled path
path = {}

#bfs(startNode, goalNode):
    #visited - used to store the nodes which has been visited
    #queue - used to store the nodes ready to be visited

    #add the startNode to the visited and queue lists
        
    #while there a nodes in the queue list:
        #pop the first node from the queue and set it as the currentNode

        #for each neighbour to the currentNode:
            #if the neighbour is equal to the goalNode
                #add the neigbour and its parent (currentNode) to the path and return

            #if the neighbour is not in the visited list:
                #add the neighbour to the visited list and queue list
                #add the neighbour and its parent (currentNode) to the path

#printPath(path, currentNode)
    #print currentNode

    #while currentNode in path:
        #set currentNode as path(currentNode)
        #print currentNode

#call - bfs(startNode, goalNode)
#call - printPath(path, goalNode)