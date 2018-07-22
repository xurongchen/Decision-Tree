#include "InformationEntropy.h"
#include <cmath>

double InformationEntropy::CalculateEntropy(double *ProbabilityList, int ListLength) {
	double Entropy = 0;
	for (int i = 0; i < ListLength; i++) {
		double Probability = *(ProbabilityList + i);
		Entropy -= Probability * log(Probability);
	}
	return Entropy;
};