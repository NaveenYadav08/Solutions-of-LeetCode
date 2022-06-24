https://leetcode.com/problems/number-of-atoms/

class Solution {
public:
    
map<string, int> count;
string formula;
    
string countOfAtoms(string formula) {
        string result;
        this->formula = formula;
        
        int i = formula.size()-1;
        eval(i,1);
        
        for(auto m:count){
            result+=m.first;
            
            if(m.second>1)
                result+=to_string(m.second);
        }
        
        return result;
    }
    
    void eval(int &i, int multiplier){
        while(i>=0){
            int currMultiplier = 1;
            if(isdigit(formula[i]))
                currMultiplier = getMultiplier(i); // multiplier to be used exclusively in current iteration.

            if(formula[i] == ')'){
                i--; // skip the ) character
                eval(i, multiplier*currMultiplier);
                continue;
            }
            if(formula[i] == '(')
            {
                i--;
                return;
            }
            else{
                string atom = getAtom(i);
                count[atom] += currMultiplier* multiplier;
                i--;
            }
        }
    }
    
	// helper method to return atom string
    string getAtom(int& i){
        string atom = "";
        while(!isupper(formula[i]))
            atom+=formula[i--];
        atom+=formula[i];
        reverse(atom.begin(), atom.end());
        return atom;
    }
    
	//helper method to parse digits.
    int getMultiplier(int &k){
        int mul = formula[k] - '0';
        int i=1;
        while(isdigit(formula[k-i])){
            mul = (formula[k-i] - '0')*pow(10,i) + mul;
            i++;
        }
        
        k = k-i;
        return mul;
    }
    
    
};
