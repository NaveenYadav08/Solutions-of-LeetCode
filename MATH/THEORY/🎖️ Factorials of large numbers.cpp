// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1/#

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
            number[i] = (char)((num + carry) % 10);
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
