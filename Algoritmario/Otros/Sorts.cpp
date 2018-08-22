#include <bits/stdc++.h>

#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 15
#define MOD 1000000007

int arr[MAXN];
int comp, inter;

void print() {
    FOR(i, 0, MAXN) {
        cout << arr[i] << " \n"[i == MAXN-1];
    }
    cout << endl;
}

void bubbleSort() {
    int n = MAXN;
    bool b = true;

    for(int i = 0; i < n - 1 && b; i ++){
        b = false;
        FOR(j, 0, n - 1 - i) {
            if (arr[j+1] < arr[j]) {
                swap(arr[j], arr[j + 1]);
                b = true;

                inter ++;
            }
            comp ++;
        }
    }
}

void selectionSort() {
	int n = MAXN;
	FOR(i, 0, n - 1) {
        int mini = i;
        FOR(j, i + 1, n) {
            comp ++;
			if (arr[j] < arr[mini]) mini = j;

		}

		if (i != mini) {
            swap(arr[i], arr[mini]);
			inter ++;
		}
	}
}

void intercambioSort() {
    int n = MAXN;
    FOR(i, 0, n - 1) {
        FOR(j, i + 1, n) {
            if (arr[i] > arr[j]) {
			    swap(arr[i], arr[j]);
				inter++;
			}
			comp++;
        }
    }
}

void insertionSort() {
    int j, key, n = MAXN;
    FOR(i, 1, n) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            inter ++;
            arr[j+1] = arr[j];
            j = j - 1;
        }

        comp = inter;
        if(j)   comp ++;

        arr[j+1] = key;
    }
}

void insertionBinarySort() {
    int n = MAXN;
    vi v;
    FOR(i, 0, n) {
        v.insert(upper_bound(v.begin(), v.end(), arr[i]), arr[i]);
    }

    copy(v.begin(), v.end(), arr);
}


void Une(int ini, int mitad, int fin) {
    int aux[fin - ini + 1];
    int i = ini, j = mitad + 1, k = 0;

    while(i <= mitad && j <= fin) {
        if (arr[i] < arr[j]) {
            aux[k] = arr[i];
            i ++;
        }
        else {
            aux[k] = arr[j];
            j ++;
        }
        k ++;
    }

    for(; i <= mitad; i ++, k ++)    aux[k] = arr[i];
    for(; j <= fin; j ++, k ++)      aux[k] = arr[j];

    for(k = 0; ini <= fin; ini ++, k ++)
        arr[ini] = aux[k];
}

void mergeSort(int ini, int fin){
    if(ini < fin){
        int mitad = (ini + fin) / 2;
        mergeSort(ini, mitad);
        mergeSort(mitad + 1, fin);
        Une(ini, mitad, fin);
    }
}


void heapify(int n, int i) {
    int maxi = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[maxi])
        maxi = l;

    if (r < n && arr[r] > arr[maxi])
        maxi = r;

    if (maxi != i) {
        swap(arr[i], arr[maxi]);
        heapify(n, maxi);
    }
}

void heapSort() {
    int n = MAXN;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(i, 0);
    }
}

int part(int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    FOR(j, low, high) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// QuickSort with less recursion calls.
void quickSortNoTail(int low, int high) {
    while (low < high) {
        int pi = part(low, high);

        if (pi - low < high - pi) {
            quickSortNoTail(low, pi - 1);
            low = pi + 1;
        }
        else {
            quickSortNoTail(pi + 1, high);
            high = pi - 1;
        }
    }
}

void quickSort(int low, int high) {
    if (low < high) {
        int pi = part(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void inicializa() {
    arr[0] = 17;
    arr[1] = 1;
    arr[2] = 4;
    arr[3] = 21;
    arr[4] = 12;
    arr[5] = 25;
    arr[6] = 22;
    arr[7] = 8;
    arr[8] = -10;
    arr[9] = 0;
    arr[10] = 1;
    arr[11] = 4;
    arr[12] = 21;
    arr[13] = 21;
    arr[14] = 21;

    comp = 0;
    inter = 0;
}



int main() {
    inicializa();
    bubbleSort();
    cout << "bubble:" << endl;
    print();

    inicializa();
    selectionSort();
    cout << "selection:" << endl;
    print();

    inicializa();
    insertionSort();
    cout << "insertion:" << endl;
    print();

    inicializa();
    insertionBinarySort();
    cout << "insertion binary:" << endl;
    print();

    inicializa();
    intercambioSort();
    cout << "intercambio:" << endl;
    print();

    inicializa();
    mergeSort(0, MAXN - 1);
    cout << "Merge Sort:" << endl;
    print();

    inicializa();
    heapSort();
    cout << "Heap Sort:" << endl;
    print();

    inicializa();
    quickSort(0, MAXN - 1);
    cout << "Quick Sort:" << endl;
    print();

    inicializa();
    quickSortNoTail(0, MAXN - 1);
    cout << "Quick Sort (no tail):" << endl;
    print();

    return 0;
}
