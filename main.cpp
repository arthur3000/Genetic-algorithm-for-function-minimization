#include <iostream>
#include <vector>
#include <random>
#include "individual.h"

#define POPULATION_SIZE 150
#define MAX_ALLELES 6
#define MAX_GENERATIONS 100
#define MUTATION_RANGE 0.05

int newNumber(){
    return rand() % 60 + 1;
}

Individual chooseParent(std::vector<Individual>& population){
    return population[rand() % population.size()];
}

bool compareFitness(Individual i1, Individual i2){
    return (i1.fitness > i2.fitness);
}

int main()
{
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::vector<Individual> population;
    for(unsigned int i = 0; i < POPULATION_SIZE; i++){
        Individual ind(newNumber(), newNumber());
        population.push_back(ind);
    }
    int generationCount = 0;
    while(generationCount < MAX_GENERATIONS){
        std::cout << "Generation -- " << generationCount+1 << std::endl;
        sort(population.begin(), population.end(), compareFitness);
        for(unsigned int i = 89; i < 99; i++){ //TOP 10' fat candidates
            std::cout << "[" << population[i].x << " " << population[i].y << "]" <<
                " F = " << population[i].fitness << std::endl;
        }
        for(unsigned int i = 0; i < POPULATION_SIZE; i++){
            Individual p1 = chooseParent(population);
            Individual p2 = chooseParent(population);
            Individual child = p1.crossOver(p2);
            child.mutate(MUTATION_RANGE);
            population[i] = child;
        }
        generationCount++;

    }
    std::cout << "Ending population" << std::endl;
    for(unsigned int i = 0; i < population.size(); i++){
        std::cout << "[" << population[i].x << " " << population[i].y << "]" <<
                " F = " << population[i].fitness << std::endl;
    }
    return EXIT_SUCCESS;
}
