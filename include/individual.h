#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>
#include <bits/stdc++.h>
#include <random>

#define MAX_ALLELES 6

class Individual
{
    public:
        Individual(int x, int y);
        virtual ~Individual();
        int x;
        int y;
        std::vector<std::vector<int>> genes;
        double fitness;

    double calculateFitness();
    std::vector<std::vector<int>> generateChromosomes(int x, int y, int max_chrom);
    void generateOrderedPair();
    Individual crossOver(Individual couple);
    void mutate(float mutation_range);
};

#endif // INDIVIDUAL_H

