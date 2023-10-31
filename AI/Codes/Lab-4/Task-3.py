from collections import deque

class Node:
    def __init__(self, state, parent, actions):
        self.state = state
        self.parent = parent
        self.actions = actions

def BFS(graph, initial_state, goal_state):
    frontier = deque([initial_state])
    explored = set()

    while frontier:
        current_node = frontier.popleft()  # Using FIFO for BFS
        explored.add(current_node)

        if current_node == goal_state:
            return action_sequence(graph, initial_state, goal_state)

        for child in graph[current_node].actions:
            if child not in frontier and child not in explored:
                graph[child].parent = current_node
                frontier.append(child)

    return None

def action_sequence(graph, initial_state, goal_state):
    solution = [goal_state]
    current_parent = graph[goal_state].parent
    
    while current_parent != initial_state:
        solution.append(current_parent)
        current_parent = graph[current_parent].parent
    
    solution.append(initial_state)
    solution.reverse()
    return solution

graph = {
    'A': Node('A', None, ['B', 'E', 'C']),
    'B': Node('B', None, ['D', 'E', 'A']),
    'C': Node('C', None, ['A', 'F', 'G']),
    'D': Node('D', None, ['B', 'E']),
    'E': Node('E', None, ['A', 'B', 'D']),
    'F': Node('F', None, ['C']),
    'G': Node('G', None, ['C'])
}

initial_state = 'D'
goal_state = 'C'

solution = BFS(graph, initial_state, goal_state)
if solution:
    print("Solution Path:", ' -> '.join(solution))
    print("Explored Node Sequence:", ', '.join(solution))
else:
    print("No solution found.")
