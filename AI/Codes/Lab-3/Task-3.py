class Node:
    def __init__(self, state, parent, actions, totalCost):
        self.state = state
        self.parent = parent
        self.actions = actions
        self.totalCost = totalCost


graph = {'A': Node('A', None, ['B', 'C', 'E'], None),
         'B': Node('B', None, ['A', 'D', 'E'], None),
         'C': Node('C', None, ['A', 'F', 'G'], None),
         'D': Node('D', None, ['B', 'E'], None),
         'E': Node('E', None, ['A', 'B', 'D'], None),
         'F': Node('F', None, ['C'], None),
         'G': Node('G', None, ['C'], None)}


def actionSequence(graph, initialState, goalState):
    solution = [goalState]
    currentParent = graph[goalState].parent
    while currentParent is not None:
        solution.append(currentParent)
        currentParent = graph[currentParent].parent
    solution.reverse()
    return solution


def BFS():
    initialState = 'D'
    goalState = 'C'
    graph = {'A': Node('A', None, ['B', 'C', 'E'], None),
             'B': Node('B', None, ['A', 'D', 'E'], None),
             'C': Node('C', None, ['A', 'F', 'G'], None),
             'D': Node('D', None, ['B', 'E'], None),
             'E': Node('E', None, ['A', 'B', 'D'], None),
             'F': Node('F', None, ['C'], None),
             'G': Node('G', None, ['C'], None)}
    frontier = [initialState]
    explored = []
    while len(frontier) != 0:
        currentNode = frontier.pop(0)
        explored.append(currentNode)
        for child in graph[currentNode].actions:
            if child not in frontier and child not in explored:
                graph[child].parent = currentNode
                if graph[child].state == goalState:
                    return actionSequence(graph, initialState, goalState)
                frontier.append(child)


solution = BFS()
print(solution)
