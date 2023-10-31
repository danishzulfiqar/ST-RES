class Node:
    def __init__(self, state, parent, actions):
        self.state = state
        self.parent = parent
        self.actions = actions

def DFS():
    initialState = 'A'
    goalState = 'F'
    
    graph = {
        'A': Node('A', None, ['B', 'E', 'C']),
        'B': Node('B', None, ['D', 'E', 'A']),
        'C': Node('C', None, ['A', 'F', 'G']),
        'D': Node('D', None, ['B', 'E']),
        'E': Node('E', None, ['A', 'B', 'D']),
        'F': Node('F', None, ['C']),
        'G': Node('G', None, ['C'])
    }
    
    frontier = [initialState]
    explored = []

    while len(frontier) != 0:
        currentNode = frontier.pop()  # Using LIFO for DFS
        print(currentNode)
        explored.append(currentNode)
        
        if currentNode == goalState:
            print(explored)
            return actionSequence(graph, initialState, goalState)
        
        currentChildren = 0
        for child in graph[currentNode].actions:
            if child not in frontier and child not in explored:
                graph[child].parent = currentNode
                frontier.append(child)
                currentChildren += 1
        
        if currentChildren == 0:
            explored.pop()  # Removing the last node if it has no unexplored children

    return None

def actionSequence(graph, initialState, goalState):
    solution = [goalState]
    currentParent = graph[goalState].parent
    
    while currentParent is not None:
        solution.append(currentParent)
        currentParent = graph[currentParent].parent
    
    solution.reverse()
    return solution

solution = DFS()
if solution:
    print("Solution:", ' -> '.join(solution))
else:
    print("No solution found.")
