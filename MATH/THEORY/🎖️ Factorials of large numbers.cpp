// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1/#


// 1) Create an array ‘res[]’ of MAX size where MAX is number of maximum digits in output. 
// 2) Initialize value stored in ‘res[]’ as 1 and initialize ‘res_size’ (size of ‘res[]’) as 1. 
// 3) Do following for all numbers from x = 2 to n. 
// ……a) Multiply x with res[] and update res[] and res_size to store the multiplication result.


// Since the factorial of N can be a very large number. 
// It can not be stored in a regular integer data type. 
// To store the factorial use an array of digits. 
// Use simple school mathematics to conduct each multiplication operation. Keep track of carry.

class Solution{
public:
    void multiply(int n, vector<int>& number) {
        int carry = 0;
        for (int i = 0; i < number.size(); i++) {
            int num = n * number[i];
            number[i] = (num + carry) % 10;
            carry = (num + carry) / 10;
        }
        while (carry) {
            number.push_back(carry % 10);
            carry /= 10;
        }
    }
    vector<int> factorial(int N){
        vector<int> number;
        number.push_back(1);
        for (int i = 2; i <= N; i++) 
            multiply(i, number);
        reverse(number.begin(), number.end()); 
        return number;
    }

};
