#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> findTriplets (int numbers[], int n, int sum){
    std::vector<std::vector<int>> res;

    std::sort(numbers, numbers + n);

    for (int i = 0; i < n; i++)
    {
        int num = numbers[i];
        int target = sum - num;

        int left = i+1;
        int right = n-1;
        while (left < right)
        {
            int leftNum = numbers[left];
            int rightNum = numbers[right];
            int total = leftNum + rightNum;

            if (total == target)
            {
                std::vector<int> triplet;
                triplet.push_back(leftNum);
                triplet.push_back(num);
                triplet.push_back(rightNum);
                res.push_back(triplet);

                left++;
                right--;
            }
            else if (total < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    
    return res;
}

int main()
{
    int arr[1000006];
    int n;
    int sum = 0;
    
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::vector<std::vector<int>> res = findTriplets(arr, n, sum);

    std::cout << "Triplets are: \n";
    for(int i = 0; i < res.size(); i++)
        std::cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<"\n";
}