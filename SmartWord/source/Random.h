#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>
#include <ctime>
#include <map>

    //int *ran = random.getMultiRand(num, 0, dict->getDictSize());

class Random
{
public:
    int getSingleRand(int l, int r) {
        srand((unsigned)(time(NULL)));
        return getRand(l, r);
    }

    int* getMultiRand(int num, int l, int r) {
        int *ret = new int[num + 3];
	std::map <int, bool> check;
        srand((unsigned)(time(NULL)));
        for(int i=0; i<num; i++) {
            ret[i] = getRand(l, r);
	    if (check.find(ret[i]) != check.end())
	    {
		i--;
		continue;
	    }
	    check[ ret[i] ] = 1;
        }
        return ret;
    }

private:
    int getRand(int l, int r) {
        return (rand() % (r-l)) + l;
    }
};

#endif // RANDOM_H
