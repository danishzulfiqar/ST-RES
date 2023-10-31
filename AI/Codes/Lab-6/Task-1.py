import random
import math

class ga:
    def __init__(self,individualsize, populationsize):
        self.population = dict()
        self.individualsize = individualsize
        self.populationsize = populationsize
        self.totalfitness = 0
        i = 0
        while i < populationsize:
            listofbits = [0]*individualsize
            listoflocations = list(range(0, individualsize))
            numberofones = random.randint(0, individualsize-1)
            oneslocations = random.sample(listoflocations, numberofones)
            for j in oneslocations:
                listofbits[j] = 1
                self.population[i] = [listofbits, numberofones]
                self.totalfitness = self.totalfitness + numberofones
                i = i+1


    def updatepopulationfitness(self):
        self.totalfitness = 0
        for indvidual in self.population:
            individualfitness = sum(self.population[indvidual][0])
            self.population[indvidual][1] = individualfitness
            self.totalfitness = self.totalfitness + individualfitness


    def selectparents(self):
        roulettewheel = []
        wheelsize = self.populationsize*5
        h_n = []
        for individual in self.population:
            h_n.append(self.population[individual][1])
        j = 0
        for individual in self.population:
            individuallength = round(wheelsize*(h_n[j]/sum(h_n)))
            j = j+1
            if individuallength > 0:
                i = 0
                while i < individuallength:
                    roulettewheel.append(individual)
                    i = i+1
        random.shuffle(roulettewheel)
        parentindices = []
        i = 0
        while i < self.populationsize:
            parentindices.append(roulettewheel[random.randint(0, len(roulettewheel)-1)])
            i = i+1
        newgeneration = dict()
        i = 0
        while i < self.populationsize:
            newgeneration[i] = self.population[parentindices[i]].copy()
            i = i+1
        del self.population
        self.population = newgeneration.copy()
        self.updatepopulationfitness()


    def generatechildren(self, crossoverprobability):
        numberofpairs = round(crossoverprobability*self.populationsize/2)
        individualindices = list(range(0, self.populationsize))
        random.shuffle(individualindices)
        i = 0
        j = 0
        while i < numberofpairs:
            crossoverpoint = random.randint(0, self.individualsize-1)
            child1 = self.population[j][0][0:crossoverpoint]\
                    + self.population[j+1][0][crossoverpoint:]
            child2 = self.population[j+1][0][0:crossoverpoint]\
                    + self.population[j][0][crossoverpoint:]
            self.population[j] = [child1, sum(child1)]
            self.population[j+1] = [child2, sum(child2)]
            i = i+1
            j = j+2
        self.updatepopulationfitness()


    def mutatechildren(self, mutationprobability):
        numberofbits = round(mutationprobability*\
                             self.populationsize*self.individualsize)
        totalindices = list(range(0, self.populationsize*self.individualsize))
        random.shuffle(totalindices)
        swaplocations = random.sample(totalindices, numberofbits)

        for loc in swaplocations:
            individualindex = math.floor(loc/self.individualsize)
            bitindex = math.floor(loc % self.individualsize)

            if self.population[individualindex][0][bitindex] == 0:
                self.population[individualindex][0][bitindex] = 1
            else:
                self.population[individualindex][0][bitindex] = 0
        self.updatepopulationfitness()


individualsize, populationsize = 8, 10
i = 0
instance = ga(individualsize, populationsize)
while True:
    instance.selectparents()
    instance.generatechildren(0.8)
    instance.mutatechildren(0.03)
    print(instance.population)
    print(instance.totalfitness)
    print(i)
    i = i+1
    found = False
    for individual in instance.population:
        if instance.population[individual][1] == individualsize:
            found = True
            break
    if found:
        break
