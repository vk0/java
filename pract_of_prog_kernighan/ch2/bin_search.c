/* lookup: двоичный поиск строки name в массиве tab; возвращает индекс */
int lookup(char *name, Nameval tab[], int ntab)
{
    int low, high, mid, cmp;
    low = 0;
    high = ntab - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        cmp = strcmp(name, tab[mid].name);
        if (cmp < 0)
            high = mid - 1;
        else if (cmp > 0)
            low = mid + 1;
        else /* элемент найден */
            return mid;
    }
    return -1; /* элемент не найден */
}

half = lookup("frac12", htmlchars, NELEMS(htmlchars));