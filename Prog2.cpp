//
//  main.cpp
//  Proj333
//
//  Created by nebil on 6/24/22.
//


//  main.cpp
//  Prog2
//
//  Created by nebil on 6/23/22.
//


#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <iomanip>



using namespace::std;


int findColumnIndex(char column);
int findRowIndex(string row);

//int main(int argc, const char * argv[])


int main() {
    
    
   
    
    
    string productionRule[8][2] ={
        
        
        {"E","E+T"} // Rule1
        ,{"E","E-T"}  // Rule2
        ,{"E","T"} // Rule3
        ,{"T","T*F"} // Rule4
        ,{"T","T/F"} // Rule5
        ,{"T","F"} // Rule6
        ,{"F", "(E)"} // Rule7
        ,{"F" , "i"} // Rule8
    };
    
    
    
    string parsingTable[16][11] = {
       // i   +    -   *   /    (    )    $    E    T    F
        {"S5","0", "0","0", "0","S4","0", "0", "1", "2", "3"} // 0
       ,{"0", "S6","S7","0","0","0","0", "acc","0","0", "0" }//1
       ,{"0","R3","R3","S8","S9","0","R3","R3","0","0","0"}//2
       ,{"0","R6","R6","R6","R6","0","R6","R6","0","0","0" }//3
       ,{"S5","0","0", "0", "0","S4","0","0", "10","2","3"}//4
       ,{"0","R8","R8","R8","R8","0","R8","R8","0","0","0"}//5
       ,{"S5","0","0","0","0","S4","0","0","0","11","3"}//6
        ,{"S5","0","0","0","0","S4","0","0","0","12","3"}//7
        ,{"S5","0","0","0","0","S4","0","0","0","0","13"}//8
        ,{"S5","0","0","0","0","S4","0","0","0","12","14"}//9
        ,{"0","S6","S7","0","0","0","S15","0","0","0","0"}//10
        ,{"0","R1","R1","S8","S9","0","R1","R1","0","0","0"}//11
        ,{"0","S2","S2","S8","S9","0","R2","R2","0","0","0"}//12
        ,{"0","R4","R4","R4","R4","0","R4","R4","0","0","0"}//13
        ,{"0","R5","R5","R5","R5","0","R5","R5","0","0","0"}//14
        ,{"0","R7","R7","R7","R7","0","R7","R7","0","0","0"}//15
                
    };
    
    
    
    string inputString = "i/i$";
    inputString = "(i+i)*i$";
    
    
    //string firstName;
    cout << "Type one string end with $: ";
    cin >> inputString; // get user input from the keyboard
    
    
    
//    cout << "Type one string end with $" << endl;
//    cout << "For (i+i)*i$  type = 1" << endl;
//    cout << "For (i*)$ typle = 2 " << endl;
//    cout << "If you want type your string  type = 3" << endl;
    
    
    
    
    
    
    
    
    stack<string> myStack;
    myStack.push("0");
//    string inputString = "i/i$";
//    inputString = "(i+i)*i$";
    int currentindex = 0;
    
    
    bool nebil = true;
  
    
    while (nebil) {
        
    
        
        if (currentindex > inputString.length()) {
            
            nebil = false;
        }


        
        
     
        int columnIndex = findColumnIndex(inputString[currentindex]);
        
        
        int rowIndex =  findRowIndex(myStack.top());
        
        
        
        
     string state =  parsingTable[rowIndex][columnIndex];
        
        
        
        if (state == "acc") {
            
            cout <<" String  " <<inputString << "  is accepted "<< endl;
            break;
            
        }
        else if (state == "0") {
            cout <<" String  " <<inputString << "  is not accepted "<< endl;
            break;
            
            
        }
        else {
        
    
        
        
        if (state[0] == 'S') {
            
            cout << "State = " << state << endl;
            
            string convertChartToString = "";
            convertChartToString = convertChartToString + inputString[currentindex];
            
            
            myStack.push(convertChartToString);
           
            if (state.length() == 3) {
                
                string convertChartToString = "";
                convertChartToString = convertChartToString + state[1];
                convertChartToString = convertChartToString + state[2];
                
                
                myStack.push(convertChartToString);
                
                
                
                
            }else if (state.length() == 2) {
                string convertChartToString = "";
                convertChartToString = convertChartToString + state[1];
                myStack.push(convertChartToString);
                
                
            }
        

            
            currentindex = 1 + currentindex;
            
            /*
             
             
             
             {"E","E+T"} // Rule1
             ,{"E","E-T"}  // Rule2
             ,{"E","T"} // Rule3
             ,{"T","T*F"} // Rule4
             ,{"T","T/F"} // Rule5
             ,{"T","F"} // Rule6
             ,{"F", "(E)"} // Rule7
             ,{"F" , "i"} // Rule8
             
             
             
             */
            
        }
        else if (state[0] == 'R') {
          
            cout << "State = " << state << endl;
            
            
            
      
            string productionRuleIndex = "";
            productionRuleIndex += state[1];
            
          int xx = findRowIndex(productionRuleIndex);
            
            
            //cout << xx << "                xx" << endl;
      
            string rightSideRule =   productionRule[xx-1][1];
            string leftSideRule =   productionRule[xx-1][0];
            
            
            
            string rightRuleFirstChartConvertToString = "";
            rightRuleFirstChartConvertToString = rightRuleFirstChartConvertToString + rightSideRule[0];
            
            while (myStack.top() != rightRuleFirstChartConvertToString) {
                myStack.pop();
            }
            myStack.pop();
            
       
            string temp = myStack.top();
            
            
//
//            string convertLeftRuleToString = "";
//            convertLeftRuleToString = convertLeftRuleToString + leftSideRule[0];
            
           
            
            
            myStack.push(leftSideRule);
        //                            top()   left production
        // find number from array  table[0]   [F]
            
            
            int newIndex = findColumnIndex(leftSideRule[0]);
            
            
            
            string convertTemp = "";
            convertTemp = convertTemp + temp;
            
            
            int convertTempToInt = findRowIndex(convertTemp);
          
             
            
            
            
            //  parsingTable[temp][leftSideRule];
            
            
          string nnn = parsingTable[convertTempToInt][newIndex];
            
            
            
            
            myStack.push(nnn);
            
            
            
            
            
            
        }
        else {
            
            
            
            
            cout << "No  | R | and | S| %%%%%%%%%%%%%%%%%%%%%" << endl;
        }
        
    
        }
    
    
    
    }
    

    
    
    
    
    

    
    
    
    
  
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}












int findColumnIndex(char column) {

    int num = 0;


    if (column == 'i') {
        num = 0;
    }
    else   if (column == '+') {
        num = 1;
    }
    else   if (column == '-') {
        num = 2;
    }

    else   if (column == '*') {
        num = 3;
    }

    else   if (column == '/') {
        num = 4;
    }

    else   if (column == '(') {
        num = 5;
    }
    else   if (column == ')') {
        num = 6;
    }
    else   if (column == '$') {
        num = 7;
    }
    else   if (column == 'E') {
        num = 8;
    }
    else   if (column == 'T') {
        num = 9;
    }  else   if (column == 'F') {
        num = 10;
    }
    else {

        num = 100;
        cout << "it is from tableColumn else part" << endl;
    }


    return num;
}




int findRowIndex(string row) {





    int num = 0;


    if (row == "0") {
        num = 0;
    }
    else   if (row == "1") {
        num = 1;
    }
    else   if (row == "2") {
        num = 2;
    }

    else   if (row == "3") {
        num = 3;
    }

    else   if (row == "4") {
        num = 4;
    }
    else   if (row == "5") {
        num = 5;
    } else   if (row == "6") {
        num = 6;
    } else   if (row == "7") {
        num = 7;
    } else   if (row == "8") {
        num = 8;
    } else   if (row == "9") {
        num = 9;
    } else   if (row == "10") {
        num = 10;
    } else   if (row == "11") {
        num = 11;
    } else   if (row == "12") {
        num = 12;
    } else   if (row == "13") {
        num = 13;
    } else   if (row == "14") {
        num = 14;
    }
    else   if (row == "15") {
        num = 15;
    }
    else {
        
        
        cout << "this is not in roww" << endl;
    }
    
    
    

   

    return num;





}
