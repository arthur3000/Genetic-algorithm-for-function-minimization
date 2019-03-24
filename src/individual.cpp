#include "individual.h"
std::random_device rd;
std::default_random_engine gen(rd());

Individual::Individual(int x, int y)
{
    this->x = x;
    this->y = y;
    genes = generateChromosomes(x, y, MAX_ALLELES);
    fitness = this->calculateFitness();
}

Individual::~Individual()
{
    //dtor
}

double Individual::calculateFitness()
{
    //Function to minimize: (x^2+y-11)^2 + (x+y^2-7)^2
    return (pow((pow(x,2)+y-11),2) + pow((x+pow(y,2)-7),2));
}

std::vector<std::vector<int>> Individual::generateChromosomes(int x, int y, int max_chrom)
{
    std::vector<std::vector<int>> v(2, std::vector<int>(max_chrom));
    int i = 0;
    while (x > 0)
    {
        v[0][i] = (x % 2);
        x = x / 2;
        i++;
    }
    i = 0;
    while (y > 0)
    {
        v[1][i] = (y % 2);
        y = y / 2;
        i++;
    }
    return v;
}

void Individual::generateOrderedPair()
{
    //Calculate X
    int sum = 0;
    for(unsigned int i = 0; i < genes.size(); i++)
    {
        if(genes[0][i] == 1)
            sum += 2^i;
    }
    x = sum;
    //Calculate Y
    sum = 0;
    for(unsigned int i = 0; i < genes.size(); i++)
    {
        if(genes[1][i] == 1)
            sum += 2^i;
    }
    y = sum;
}

Individual Individual::crossOver(Individual couple)
{
    Individual child = Individual(0, 0);
    int halfPoint = genes[0].size()/2;
    for(unsigned int i = 0; i < 2; i++)  //We use 2 because we traverse a (x,y) orderded pair
    {

        for(int j = 0; j < genes[0].size(); j++)
        {
            if(j < halfPoint)
            {
                child.genes[i][j] = genes[i][j];
            }
            else
            {
                child.genes[i][j] = couple.genes[i][j];
            }
        }
    }
    child.generateOrderedPair();
    child.fitness = child.calculateFitness();
    return child;
}

void Individual::mutate(float mutation_range)
{
    std::uniform_real_distribution<> disReal(0.0, 1.0);//uniform distribution between 0 and 1
    std::uniform_int_distribution<int> disInt(0, 1);
    for(unsigned int i = 0; i < genes[0].size(); i++)
    {
        if(disReal(gen) < mutation_range)
        {
            int changedValue = disInt(gen);
            genes[changedValue][i] = genes[changedValue][i] ^ 1; //XOR
        }
    }
}
