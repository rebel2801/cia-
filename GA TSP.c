import numpy as np
import random

distances = np.array([[0, 2, 5, 7],
                      [2, 0, 8, 3],
                      [5, 8, 0, 1],
                      [7, 3, 1, 0]])

POP_SIZE = 50
NUM_GENERATIONS = 100
MUTATION_RATE = 0.01

def calculate_fitness(tour):
    tour_length = 0
    for i in range(len(tour) - 1):
        tour_length += distances[tour[i], tour[i+1]]
    tour_length += distances[tour[-1], tour[0]]
    return 1 / tour_length

def create_tour():
    tour = list(range(len(distances)))
    random.shuffle(tour)
    return tour

def create_population():
    population = []
    for i in range(POP_SIZE):
        population.append(create_tour())
    return population

def tournament_selection(population):
    tournament_size = 5
    tournament = random.sample(population, tournament_size)
    parent = max(tournament, key=lambda x: calculate_fitness(x))
    return parent

def crossover(parent1, parent2):
    point1 = random.randint(0, len(parent1) - 1)
    point2 = random.randint(0, len(parent1) - 1)
    if point1 > point2:
        point1, point2 = point2, point1
    child = [None] * len(parent1)
    for i in range(point1, point2 + 1):
        child[i] = parent1[i]
    j = 0
    for i in range(0, point1):
        while parent2[j] in child:
            j += 1
        child[i] = parent2[j]
    for i in range(point2 + 1, len(parent1)):
        while parent2[j] in child:
            j += 1
        child[i] = parent2[j]
    return child

def mutate(tour):
    for i in range(len(tour)):
        if random.random() < MUTATION_RATE:
            j = random.randint(0, len(tour) - 1)
            tour[i], tour[j] = tour[j], tour[i]
    return tour

def genetic_algorithm():
    population = create_population()
    for i in range(NUM_GENERATIONS):
        fitness_scores = [calculate_fitness(tour) for tour in population]
        max_fitness = max(fitness_scores)
        max_index = fitness_scores.index(max_fitness)
        best_tour = population[max_index]
        new_population = [best_tour]
        while len(new_population) < POP_SIZE:
            parent1 = tournament_selection(population)
            parent2 = tournament_selection(population)
            child = crossover(parent1, parent2)
            child = mutate(child)
            new_population.append(child)
        population = new_population
    return best_tour

best_tour = genetic_algorithm()
print("Best tour:", best_tour)