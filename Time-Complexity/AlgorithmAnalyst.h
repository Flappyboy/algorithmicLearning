//
// Created by 16143 on 2018/3/8.
//

#ifndef TIME_COMPLEXITY_ALGORITHMANALYST_H
#define TIME_COMPLEXITY_ALGORITHMANALYST_H

#include <iostream>
#include <algorithm>
#include <cassert>
#include <ctime>
#include <vector>
#include <map>

using namespace std;

class AlgorithmAnalyst {

private:
    int multiple=2;
    int size=1;
    double tempResult=-1;
    clock_t startTime = NULL;
    clock_t endTime = NULL;

    map<int,double> results;

    class Analysis{

    };
public:
    AlgorithmAnalyst(int multiple): AlgorithmAnalyst(){
        this->multiple = multiple;
    }
    AlgorithmAnalyst(){
        multiple =2;
        reset();
    }
    void reset(){
        size=0;
        results.clear();
        tempResult=-1;
    }
    void begin(int multiple){
        this->multiple = multiple;
        begin();
    }
    void begin(){
        size *= multiple;
        startTime = clock();
    }
    double end(){
        assert(startTime);
        endTime = clock();
        double result = double(endTime - startTime) / CLOCKS_PER_SEC;
        results.insert(make_pair(size,result));
        return result;
    }
    void endAndShow(){
        double result = end();
        cout << 'data size ' << size << '  Time cost: '<< result<< ' s ';
        if(tempResult!=-1)
            cout<< result/tempResult;
        cout<<endl;
    }
    void show(){
        cout.precision(3);
        double temp=-1;
        for (map<int, double >::iterator iter = results.begin(); iter != results.end(); ++iter) {
            cout << 'data size ' << iter->first << '  Time cost: '<< iter->second<< ' s ';
            if(temp!=-1)
                cout<< iter->second/temp;
            cout<<endl;
        }
    }

};

#endif //TIME_COMPLEXITY_ALGORITHMANALYST_H
