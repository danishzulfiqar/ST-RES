import random
import itertools
import math

def generate_points(num_points=15):
    return [(random.uniform(0, 0.5), random.uniform(0, 0.5)) for _ in range(num_points)]

def distance(point1, point2):
    return math.sqrt((point1[0]-point2[0])**2 + (point1[1]-point2[1])**2)

def heuristic(individual):
    return sum(distance(individual[i], individual[i+1]) for i in range(len(individual)-1))

def crossover(parent1, parent2):
    idx = random.randint(0, len(parent1)-2)
    child1 = parent1[:idx] + parent2[idx:]
    child2 = parent2[:idx] + parent1[idx:]
    return child1, child2

def GA():
    points = generate_points()
    population = [random.sample(points, len(points)) for _ in range(45)]

    for generation in range(100):  
        population.sort(key=heuristic)
        
        population = population[:len(population)//2]

        children = []
        for i in range(0, len(population) - 1, 2):
            child1, child2 = crossover(population[i], population[i+1])
            children.append(child1)
            children.append(child2)

        for child in children:
            if random.uniform(0, 1) < 0.1:  
                idx1, idx2 = random.sample(range(len(child)), 2)
                child[idx1], child[idx2] = child[idx2], child[idx1]
        
        population.extend(children)
        
    population.sort(key=heuristic)
    return population[0], heuristic(population[0])

solution, cost = GA()
print("Best Route:", solution)
print("Total Distance:", cost)
