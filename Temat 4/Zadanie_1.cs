int[] liczby = { 5,2,22,36,6,5,7,85,96,14,27,15,11,73,10};

// przyklad 1

            int min;
            int max;
            for (int i = 0; i < liczby.Length; i++)
            {
                min = i;
                for (int j = i+1; j < liczby.Length; j++)
                {
                    if (liczby[j] < liczby[min]) 
                        min = j;
                }
                int temp = liczby[min];
                liczby[min] = liczby[i];
                liczby[i] = temp;
            }
	
// przyklad 2

int key;
            for (int i = 0; i < liczby.Length; i++)
            {
                key = liczby[i];
                int j = i - 1;
                while ((j>=0)&&(liczby[j]>key))
                {
                    liczby[j + 1] = liczby[j];
                    j--;
                }
                liczby[j + 1] = key;
            }

// przyklad 3

for (int i = 0; i < liczby.Length; i++)
            {
                for (int j = liczby.Length-1; j > i; j--)
                {
                    if (liczby[j-1]>liczby[j])
                    {
                        int temp = liczby[j];
                        liczby[j] = liczby[j - 1];
                        liczby[j - 1] = temp;
                    }
                }
            }

// przyklad 4

class Quicksort
    {
        public static void qsort(int []items)
        {
            qs(items, 0, items.Length - 1);
        }
        private static void qs(int []items, int left, int right)
        {
            int i, j;
            int x, y;
            i = left; j = right;
            x = items[(left + right) / 2];

            do
            {
                while ((items[i] < x) && (i < right)) i++;
                while ((x < items[j]) && (j > left)) j--;

                if (i <= j)
                {
                    y = items[i];
                    items[i] = items[j];
                    items[j] = y;
                    i++;
                    j--;
                }
            } while (i <= j);

            if (left < j) qs(items, left, j);
            if (i < right) qs(items, i, right);
        }
    }

// przyklad 5

class MergeSort
    {
        public static int[] mergeSort(int[] array)
        {
            int[] lewo;
            int[] prawo;
            int[] wynik = new int[array.Length];
            if (array.Length <= 1)
                return array; 
            int srodek = array.Length / 2;
            lewo = new int[srodek];
            if (array.Length % 2 == 0)
                prawo = new int[srodek];
            else
                prawo = new int[srodek + 1];
            for (int i = 0; i < srodek; i++)
                lewo[i] = array[i];
            int x = 0;
            for (int i = srodek; i < array.Length; i++)
            {
                prawo[x] = array[i];
                x++;
            }
            lewo = mergeSort(lewo);
            prawo = mergeSort(prawo);
            wynik = merge(lewo, prawo);
            return wynik;
        }
        public static int[] merge(int[] lewo, int[] prawo)
        {
            int dlugosc = prawo.Length + lewo.Length;
            int[] wynik = new int[dlugosc];
            int INDEX_lewy = 0, INDEX_prawy = 0, INDEX_wynik = 0;
            while (INDEX_lewy < lewo.Length || INDEX_prawy < prawo.Length)
            {
                if (INDEX_lewy < lewo.Length && INDEX_prawy < prawo.Length)
                { 
                    if (lewo[INDEX_lewy] <= prawo[INDEX_prawy])
                    {
                        wynik[INDEX_wynik] = lewo[INDEX_lewy];
                        INDEX_lewy++;
                        INDEX_wynik++;
                    }
                    else
                    {
                        wynik[INDEX_wynik] = prawo[INDEX_prawy];
                        INDEX_prawy++;
                        INDEX_wynik++;
                    }
                }
                else if (INDEX_lewy < lewo.Length)
                {
                    wynik[INDEX_wynik] = lewo[INDEX_lewy];
                    INDEX_lewy++;
                    INDEX_wynik++;
                }
                else if (INDEX_prawy < prawo.Length)
                {
                    wynik[INDEX_wynik] = prawo[INDEX_prawy];
                    INDEX_prawy++;
                    INDEX_wynik++;
                }
            }
            return wynik;
        }
    }
