#include <primesieve.hpp>
#include <iostream>
#include <vector>
#include <map>

std::map< std::vector<int>, int> primeCount;

int main(int argc, char* argv[])
{
	int N = atoi(argv[1]);
	int q = atoi(argv[2]);
	int k = atoi(argv[3]);

    std::vector<int> primes;
    primesieve::generate_primes(N, &primes);

    std::vector<int> vcount;
    for (auto v : primes) {
    	if (v <= q) {
    		continue;
    	}
    	if (vcount.size() == k) {
    		vcount.erase(vcount.begin());
    	}

    	vcount.push_back(v % q);
    	if (vcount.size() == k) {
    		primeCount[vcount]++;
    	}
    }

    int totalCount = 0;
    for (auto it : primeCount) {
    	totalCount += it.second;
    }

    for (auto it : primeCount) {
    	printf("( ");
    	for (auto idx : it.first) {
    		printf("%d, ", idx);
    	}
    	printf(") ");
    	printf("%d %.2f percent \n", it.second, (double) it.second / totalCount * 100 );
    }
    return 0;
}