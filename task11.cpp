#include<iostream>
#include<vector>
#include<fstream>

enum SortingStrategy {
    BUBBLE_SORT, SELECTION_SORT
};


struct SortingOption {
   SortingStrategy e;
   void (*fptr)(std::vector<int>&);
};

void bubble(std::vector<int>& arr) {
    int n = arr.size();
   for (int i = 0; i < n - 1;++i) {
      for (int j = 0; j < n - 1 -i; ++j) {
           if (arr[j]  < arr[j + 1]) {
	      std::swap(arr[j],arr[j + 1]);
	   }
      }
   }
}

void selection(std::vector <int>& arr ) {
	int n = arr.size();
   int minIndex;
   for (int i = 0;i < n; ++i) {
        minIndex = i;
	for (int j = i + 1; j < n; ++j) {
	    if (arr[j] < arr[minIndex]) {
	        minIndex = j;
	    }
	    if (minIndex != i) {
	       std::swap(arr[minIndex],arr[i]);
	    }
	}
   }
}

std::vector<int> read_from_file(const std::string& file_name) {
   
   std::vector<int>  res;
   std::ifstream input_file(file_name);
   if (input_file.is_open()) {

   int val;
   while (input_file >> val) {
       res.push_back(val);
   }

    input_file.close();
   }
   else {
     std::cout << "Cant opening file for readinng" << std::endl;
   }
   return res;
}

void save_to_file(const std::vector<int>& arr, const std::string& file_name) {
    std::ofstream output_file(file_name);

    if (!output_file.is_open()) {
        std::cout << "cant opening file for writing: " << file_name << std::endl;
        return;
    }

    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    output_file.close();
    std::cout << "Sorted array saved to file: " << file_name << std::endl;
}


int main()
{
    std::string file_name = "taskfile.txt";
    //read array from file
    std::vector<int> array = read_from_file(file_name);

    std::cout << "Array read from file: ";
    for (auto it = array.begin(); it != array.end(); ++it) {
        std::cout << *it << " ";
    }
   
    std::cout << std::endl;
    return 0;
    const int size = 2;
    SortingOption arr[size];

    std::cout << "choose the SortingStrategy : " << std::endl;
    std::cout << "Press 1 if u want to use bubble sort :" << std::endl;
    std::cout << "Press 2 if u want to use selection sort :" << std::endl;
 
    int choice;
    std::cin >> choice;

    for (int i = 0; i < size; ++i) {
      if (choice == 1) {
        arr[i].fptr = bubble;
      } else arr[i].fptr = selection;
    }
 
    std::cout << "Array after srting"  << std::endl;
   for (int j = 0;j < size; ++j) {
 	  std::cout << "Enter the " << j <<  "st SortingStrategy " << std::endl;
 	  arr[j].fptr(array);
      for (auto it = array.begin(); it != array.end(); ++it) {
         std::cout << *it << " ";
       }

  }
   save_to_file(array,file_name);


   return 0;
}

