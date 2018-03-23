//
// Created by 16143 on 2018/3/9.
//

#ifndef LEETCODE_11CONTAINERWITHMOSTWATER_H
#define LEETCODE_11CONTAINERWITHMOSTWATER_H

#include <iostream>
#include <vector>

using namespace std;
//Given n non-negative integers a1, a2, ..., an,
// where each represents a point at coordinate (i, ai).
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
// Find two lines, which together with x-axis forms a container,
// such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.
namespace ContainerWithMostWater {
    int binarySearchForCeil(vector<vector<int>::iterator> v,int dst){

        int l=0; int r=v.size()-1;
        while(l<=r){//[l,,,r]
            int mid = l + (r-l)/2;
            if(dst == *v[mid]){
                for (int i = mid+1; i <= r; ++i) {
                    if (dst == *v[i]){
                        mid=i;
                    }else{
                        break;
                    }
                }
                return mid;
            }
            if (dst < *v[mid]) {//[l,,mid,,dst,,r] [l,,mid,,dst,mid+1,r]
                if(mid==v.size()-1)
                    return mid;
                if(dst > *v[mid+1])
                    return mid;
                l = mid + 1;
            } else {//[l,,dst,,mid,,r] [l,,mid-1,,dst,mid,r]
                if(mid==0)
                    return 0;
                if(dst < *v[mid-1])
                    return mid-1;
                r = mid - 1;
            }
        }
        return 0;
    }
    int findDistance(vector<vector<int>::iterator> v, vector<int>::iterator src){

        int dst = binarySearchForCeil(v,*src);
        vector<vector<int>::iterator>::iterator temp = v.begin()+dst;
        if(*src> **temp){
            return 0;
        }
        return abs(src-*temp);
    }

    int maxArea1(vector<int> &height) {
        //在一个区域内，如果两头的line是最高的（不考虑相等的情况），那么在中间的所有line不可能是形成最高的墙的那一条line
        //先选出最高的两条line，然后每次从剩下的区域选出一个最高的，最后计算剩下的line
        vector<vector<int>::iterator> left;
        vector<vector<int>::iterator> right;
        vector<int>::iterator max1 = height.begin();
        vector<int>::iterator max2 = height.end();


        for (auto iter = height.begin()+1; iter != height.end();iter++){
            if(*iter>*max1){
                max2=max1;
                max1=iter;
            }else if(max2==height.end()||*iter>*max2){
                max2=iter;
            }
        }
        if (max1 > max2) {
            auto temp = max1;
            max1 = max2;
            max2 = temp;
        }

        cout<<*max1<<' '<<*max2<<endl;

        left.push_back(max1);
        right.push_back(max2);
        while (max1 != height.begin()) {
            max1 = max_element(height.begin(), max1);
            left.push_back(max1);
        }
        while (max2 != (height.end()-1) ) {
            max2 = max_element(max2+1, height.end());
            right.push_back(max2);
        }

        //输出left和right
        for (auto iter = left.begin(); iter != left.end();iter++)
        {
            cout << **iter << " ";
        }
        cout<<endl;
        for (auto iter = right.begin(); iter != right.end();iter++)
        {
            cout << **iter << " ";
        }

        int maxAreal = -1;
        for (auto iter = left.begin(); iter != left.end(); iter++)
        {
            auto result = findDistance(right, *iter);
            if(result!=0) {
                int areal = (result * **iter);
                if (maxAreal < areal)
                    maxAreal = areal;
            }
        }
        for (auto iter = right.begin(); iter != right.end(); iter++)
        {
            auto result = findDistance(left, *iter);
            if(result!=0) {
                int areal = (result * **iter);
                if (maxAreal < areal)
                    maxAreal = areal;
            }
        }
        return maxAreal;
    }

}
#endif //LEETCODE_11CONTAINERWITHMOSTWATER_H
