using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'quickSort' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static List<int> quickSort(List<int> arr)
    {
        quickSort(arr, 0, arr.Count - 1);
        return arr;
    }

    private static void quickSort(List<int> arr, int begin, int end)
    {
        if (end - begin + 1 <= 3)
        {
            BubbleSort(arr, begin, end);
            return;
        }

        int mid = begin + (end - begin) / 2;
        MedianSort(arr, begin, mid, end);

        int pivot = arr[mid];
        Swap(arr, mid, end - 1);

        int i = begin;
        int j = end - 1;

        while (true)
        {
            while (++i < end && arr[i] < pivot) ;
            while (--j > begin && arr[j] > pivot) ;

            if (i >= j)
                break;

            Swap(arr, i, j);
        }

        Swap(arr, i, end - 1);

        quickSort(arr, begin, i - 1);
        quickSort(arr, i + 1, end);
    }

    private static void MedianSort(List<int> arr, int begin, int mid, int end)
    {
        if (arr[begin] > arr[mid]) Swap(arr, begin, mid);
        if (arr[mid] > arr[end]) Swap(arr, mid, end);
        if (arr[begin] > arr[mid]) Swap(arr, begin, mid);
    }

    private static void Swap(List<int> arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int n = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> arr = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(arrTemp => Convert.ToInt32(arrTemp)).ToList();

        List<int> result = Result.quickSort(arr);

        textWriter.WriteLine(String.Join(" ", result));

        textWriter.Flush();
        textWriter.Close();
    }
}
