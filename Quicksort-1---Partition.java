import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'quickSort' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static List<Integer> quickSort(List<Integer> arr) {
        quickSort(arr, 0, arr.size() - 1);
        return arr;
    }

    private static void quickSort(List<Integer> arr, int begin, int end) {
        if (end - begin + 1 <= 3) {
            bubbleSort(arr, begin, end);
            return;
        }

        int mid = begin + (end - begin) / 2;
        medianSort(arr, begin, mid, end);

        int pivot = arr.get(mid);
        swap(arr, mid, end - 1);

        int i = begin;
        int j = end - 1;

        while (true) {
            while (++i < end && arr.get(i) < pivot);
            while (--j > begin && arr.get(j) > pivot);

            if (i >= j) break;

            swap(arr, i, j);
        }

        swap(arr, i, end - 1);

        quickSort(arr, begin, i - 1);
        quickSort(arr, i + 1, end);
    }

    private static void medianSort(List<Integer> arr, int begin, int mid, int end) {
        if (arr.get(begin) > arr.get(mid)) swap(arr, begin, mid);
        if (arr.get(mid) > arr.get(end)) swap(arr, mid, end);
        if (arr.get(begin) > arr.get(mid)) swap(arr, begin, mid);
    }

    private static void swap(List<Integer> arr, int i, int j) {
        int temp = arr.get(i);
        arr.set(i, arr.get(j));
        arr.set(j, temp);
    }

    private static void bubbleSort(List<Integer> arr, int begin, int end) {
        for (int i = begin; i <= end; i++) {
            for (int j = i + 1; j <= end; j++) {
                if (arr.get(j) < arr.get(i)) {
                    swap(arr, i, j);
                }
            }
        }
    }
}
