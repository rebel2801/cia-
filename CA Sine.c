import numpy as np
import math


lower_bound = -10
upper_bound = 10


pop_size = 50
num_iterations = 100
num_culture_cycles = 5
num_immigrants = 10
num_accepted = 20


def fitness_function(x):
    return -np.sin(x)


def culture_function(population):
    return np.mean(population)


population = np.random.uniform(lower_bound, upper_bound, pop_size)


for i in range(num_iterations):

    fitness = fitness_function(population)


    max_fitness = np.max(np.abs(fitness))


    sorted_indices = np.argsort(fitness)
    population = population[sorted_indices]


    for j in range(num_culture_cycles):
        # Calculate the culture value
        culture_value = culture_function(population)


        immigrants = np.random.uniform(lower_bound, upper_bound, num_immigrants)

  
        population[-num_immigrants:] = immigrants

 
        fitness = fitness_function(population)


        max_fitness = np.max(np.abs(fitness))

       
        sorted_indices = np.argsort(fitness)
        population = population[sorted_indices]

     
        population[:num_accepted] = population[:num_accepted] * (1 - 0.1) + 0.1 * culture_value


print("Best solution:", population[0], "Fitness:", max_fitness)