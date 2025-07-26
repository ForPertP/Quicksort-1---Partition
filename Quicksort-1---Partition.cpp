#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'quickSort' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

template <typename T>
void swap_value(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void median_sort(T& arr, int begin, int mid, int end)
{
    if (arr[begin] > arr[mid])
    {
        swap_value(arr[begin], arr[mid]);
    }

    if (arr[mid] > arr[end])
    {
        swap_value(arr[mid], arr[end]);
    }

    if (arr[begin] > arr[mid])
    {
        swap_value(arr[begin], arr[mid]);
    }
}

template <typename T>
void quick_sort(T& arr, int begin, int end)
{
    int mid = begin + (end - begin) / 2;
    median_sort(arr, begin, mid, end);

    if (end - begin + 1 > 3)
    {
        int pivot = arr[mid];
        swap_value(arr[mid], arr[end - 1]);

        int i = begin;
        int j = end - 1;

        while (true)
        {
            while (arr[++i] < pivot && i < end);
            while (arr[--j] > pivot && j > begin);

            if (i >= j)
            {
                break;
            }

            swap_value(arr[i], arr[j]);
        }
        swap_value(arr[i], arr[end - 1]);

        quick_sort(arr, begin, i - 1);
        quick_sort(arr, i + 1, end);
    }
}

vector<int> quickSort(vector<int> arr)
{
    int index = std::distance(arr.begin(), arr.end());
    quick_sort(arr, 0, index - 1);

    return arr;    
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = quickSort(arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);
    s.erase(
        s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );
    return s;
}

string rtrim(const string &str)
{
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end()
    );
    return s;
}

string rtrim(const string &str)
{
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end()
    );
    return s;
}

std::vector<string> split(const string &str)
{
    vector<string> tokens;
    string_view str_view(str);
    size_t start = 0;
    size_t end = 0;

    while (end = str_view.find(' ', 
