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
