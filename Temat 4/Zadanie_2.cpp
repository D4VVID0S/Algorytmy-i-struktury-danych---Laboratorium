 public static int binSearch(int[] liczby, int key)
        {
            int lewo = 0;
            int prawo = liczby.Length - 1;
            while (lewo <= prawo)
            {
                int cos = (lewo + prawo) / 2;
                if (key == liczby[cos])
                    return cos;
                else if (key < liczby[cos])
                    prawo = cos - 1;
                else
                    lewo = cos + 1;
            }
            return -1;
        }