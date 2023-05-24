#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdexcept>
using namespace std; 

// PART ONE
template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index);
/* Passes in index of type int & vector type T. Fct returns index of min 
value starting from index to end of vector */
template<typename T>
void selection_sort(vector<T> &vals);
/* Passes in vector of type T & sorts based on selection sort method. Fct
should utilize min_index fct to find index of min value in unsorted portion
of vector */

// PART TWO
template<typename T>
T getElement(vector<T> vals, int index);
/* Passes in vector of type T & index of type int. Fct returns the element
located at index of vals. Write a try catch block in main fct so tht when 
index OUT OF RANGE of vector, the "std::outofrange" exception will be caught
by catch (const std::outofrange& excpt). Once exception caught, should output
"out of range exception occured" followed by new line */
vector<char> createVector();
/* creates a vector of chars of rand size */

int main() {
  // PART B -- BEGIN
  srand(time(0));
  vector<char> vals = createVector();
  char curChar;
  long unsigned index;
  int numOfRuns = 10;

  while(--numOfRuns >= 0) {
    try {
      cout << "Enter a number: " << endl;
      cin >> index;

      // if index is out of range, call the exception
      if (index > vals.size() - 1) {
        throw out_of_range("Out of Range Exception Occured");
      }

      curChar = getElement(vals, index);
      cout << "Element located at " << index << ": is " << curChar << endl;
    }
    catch (out_of_range &excpt) {
      cout << excpt.what() << endl; 
    }
  }
  // PART B -- END

  return 0; 
}

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
  T minVal; 

  minVal = vals.at(index);
  // finds the minVal
  for (long unsigned i = index; i < vals.size(); ++i) {
    if (vals.at(i) < minVal) {
      minVal = vals.at(i);
    }
  }

  // finds index of minVal
  while(vals.at(index) != minVal) {
    ++index;
  }

  return index; 
}

template<typename T>
void selection_sort(vector<T> &vals) {
  int minIndex; 

  for (long unsigned i = 0; i < vals.size(); ++i) {
    minIndex = min_index(vals, i);
    swap(vals.at(i), vals.at(minIndex));
  }

  for (long unsigned i = 0; i < vals.size(); ++i) {
    cout << vals.at(i) << ' ';
  }
  cout << endl; 
}

template<typename T>
T getElement(vector<T> vals, int index) {
  return vals.at(index);
}

vector<char> createVector() {
  int vecSize = rand() % 26;
  char c = 'a';
  vector<char> vals;

  for(int i = 0; i < vecSize; ++i) {
    vals.push_back(c);
    c++;
  }

  return vals;
}
