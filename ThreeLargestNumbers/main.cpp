//
//  main.cpp
//  ThreeLargestNumbers
//
//  Created by adeeb mohammed on 03/01/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

/*
 
 Write a function that takes in an array of integers and returns
 a sorted array of the three
 largest integers in the input array.
 Note that the function should return duplicate integers if necessary;
 for example,
 it should return [10, 10, 12] for an input array of [10, 5, 9, 10, 12].
 */

#include <vector>
#include <iostream>
#include <map>
#include <climits>

// space complexity o(n) and time complexity o(1) for this algorithm
std::vector<int> findThreeLargestNumbersOrg(std::vector<int> array){
    std::vector<int> resultVector;
    std::vector<int> resultVectorTemp;
    const int topElements = 3;
    std::map<int,int> occuranceMap;
    
    // this function sorts this array here
    // here the insertion is o(log(n)) complexity
    for(auto it = array.begin(); it != array.end(); ++it){
        occuranceMap[*it]++;
    }
    
    int k = 0;
    for(auto it = occuranceMap.rbegin(); it != occuranceMap.rend(); ++it){
        for(auto i = 0; i< it->second; i++){
            if(k < topElements){
                resultVectorTemp.push_back(it->first);
            }else{
                break;
            }
            k++;
        }
    }
    for(auto it = resultVectorTemp.rbegin(); it != resultVectorTemp.rend(); ++it){
        resultVector.push_back(*it);
    }
    occuranceMap.clear();
    resultVectorTemp.clear();
    return resultVector;
}


// function for inserting largest element in the
// stack and pusing the smallest element if
// its more than the number of required elements
void shiftAndUpdate(std::vector<int> &array,int num,int idx){
    for(int i = 0; i <= idx; i++){
        if (i == idx) {
            array.at(i) = num;
        }else{
            array.at(i) = array.at(i+1);
        }
    }
}

// function for updating the largest of three numbers
void updateLargest(std::vector<int> &array, int num){
    if(num > array.at(2)){
        shiftAndUpdate(array, num, 2);
    }else if(num > array.at(1)){
        shiftAndUpdate(array, num, 1);
    }else if(num > array.at(0)){
        shiftAndUpdate(array, num, 0);
    }
}

// below is an optimal soultion for this problem
// time complexity o(n) space complexity o(1)

std::vector<int> findThreeLargestNumbers(std::vector<int> array){
    std::vector<int> resultVector = {INT_MIN,INT_MIN,INT_MIN};
    for(auto num : array){
        updateLargest(resultVector,num);
    }
    return resultVector;
}

int main(int argc, const char * argv[]) {
    std::cout << "Program for finding the largest three numbers in an array";
    std::vector<int> array = {7,7,7,7,7,7,7};
    auto resultVector = findThreeLargestNumbersOrg(array);
    std::cout<< std::endl;
    for(auto it = resultVector.begin(); it!= resultVector.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout<< std::endl;
    std::cout << INT_MIN << std::endl;
    
    return 0;
}
