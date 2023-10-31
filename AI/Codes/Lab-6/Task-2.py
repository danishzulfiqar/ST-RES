import random
import math


class queensGA:
    def updateIndividualFitness(self, individualArray):
        i = 0
        fitnessValue = 0
        while i < self.individualSize:
            j = 0
            while j < self.individualSize:
                if i != j:
                    if individualArray[j] == individualArray[i]:
                        fitnessValue = fitnessValue + 1
                    elif individualArray[j] == individualArray[i] - abs(j - i):
                        fitnessValue = fitnessValue + 1
                    elif individualArray[j] == individualArray[i] + abs(j - i):
                        fitnessValue = fitnessValue + 1
                j = j + 1
            i = i + 1
        return fitnessValue

    def selectParents(self):
        rouletteWheel = []
        wheelSize = self.populationSize * 5
        h_n = []
        for individual in self.population:
            h_n.append(1 / (self.population[individual][1] + 1e-6))  # Add a small constant like 1e-6
        j = 0
        for individual in self.population:
            individualFitness = round(wheelSize * (h_n[j] / sum(h_n)))
            j = j + 1
            if individualFitness > 0:
                i = 0
                while i < individualFitness:
                    rouletteWheel.append(individual)
                    i = i + 1
        random.shuffle(rouletteWheel)
        parentIndices = []
        i = 0
        while i < self.populationSize:
            parentIndices.append(rouletteWheel[random.randint(0, len(rouletteWheel) - 1)])
            i = i + 1
        newGeneration = dict()
        i = 0
        while i < self.populationSize:
            newGeneration[i] = self.population[parentIndices[i]].copy()
            i = i + 1
        del self.population
        self.population = newGeneration.copy()
        self.updatePopulationFitness()

    def updatePopulationFitness(self):
        self.totalFitness = 0
        for individual in self.population:
            individualFitness = self.updateIndividualFitness(self.population[individual][0])
            self.population[individual][1] = individualFitness
            self.totalFitness = self.totalFitness + individualFitness

    def __init__(self, individualSize, populationSize):
        self.population = dict()
        self.individualSize = individualSize
        self.populationSize = populationSize
        self.totalFitness = 0
        i = 0
        while i < populationSize:
            individualArray = [0] * individualSize
            j = 0
            while j < individualSize:
                value = random.randint(0, individualSize - 1)
                individualArray[j] = value
                j = j + 1
            self.population[i] = [individualArray.copy(), 0]
            i = i + 1
        self.updatePopulationFitness()

    def generateChildren(self, crossoverProbability):
        numberOfPairs = round(crossoverProbability * self.populationSize / 2)
        individualIndices = list(range(0, self.populationSize))
        random.shuffle(individualIndices)
        i = 0
        j = 0
        while i < numberOfPairs:
            crossoverPoint = random.randint(0, self.individualSize - 1)
            child1 = self.population[j][0][0:crossoverPoint] + self.population[j + 1][0][crossoverPoint:]
            child2 = self.population[j + 1][0][0:crossoverPoint] + self.population[j][0][crossoverPoint:]
            self.population[j] = [child1, 0]
            self.population[j + 1] = [child2, 0]
            i = i + 1
            j = j + 2
        self.updatePopulationFitness()

    def mutateChildren(self, mutationProbability):
        numberOfBits = round(mutationProbability * self.populationSize * self.individualSize)
        totalIndices = list(range(0, self.populationSize * self.individualSize))
        random.shuffle(totalIndices)
        swapLocations = random.sample(totalIndices, numberOfBits)
        for loc in swapLocations:
            individualIndex = math.floor(loc / self.individualSize)
            bitIndex = math.floor(loc % self.individualSize)
            value = random.randint(0, individualSize - 1)
            while value == self.population[individualIndex][0][bitIndex]:
                value = random.randint(0, individualSize - 1)
            self.population[individualIndex][0][bitIndex] = value
        self.updatePopulationFitness()


individualSize, populationSize = 8, 16
i = 0
instance = queensGA(individualSize, populationSize)
while True:
    instance.selectParents()
    instance.generateChildren(0.5)
    instance.mutateChildren(0.03)
    if i % 20 == 0:
        print(instance.population)
        print(instance.totalFitness)
        print(i)
    i = i + 1
    found = False
    for individual in instance.population:
        if instance.population[individual][1] == 0:
            found = True
            break
        if found:
            print(instance.population)
            print(instance.totalFitness)
            print(i)
            break
