import random
import math

num_particles = 50
max_iterations = 100
inertia_weight = 0.8
c1 = 1.4
c2 = 1.4

lower_bound = -10
upper_bound = 10

def evaluate(position):
    return math.sin(position)

particles = []
for i in range(num_particles):
    position = random.uniform(lower_bound, upper_bound)
    velocity = 0
    particles.append({'position': position, 'velocity': velocity, 'pbest': position})

gbest = particles[0]['position']
for particle in particles:
    if evaluate(particle['position']) > evaluate(gbest):
        gbest = particle['position']

for iteration in range(max_iterations):
    for particle in particles:
        # Update velocity
        particle['velocity'] = (inertia_weight * particle['velocity'] +
                                c1 * random.random() * (particle['pbest'] - particle['position']) +
                                c2 * random.random() * (gbest - particle['position']))
        particle['position'] += particle['velocity']
        if evaluate(particle['position']) > evaluate(particle['pbest']):
            particle['pbest'] = particle['position']
        if evaluate(particle['position']) > evaluate(gbest):
            gbest = particle['position']
    print("Iteration {}: Best fitness = {}".format(iteration, evaluate(gbest)))

print("Global best: position = {}, fitness = {}".format(gbest, evaluate(gbest)))