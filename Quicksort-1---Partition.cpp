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
