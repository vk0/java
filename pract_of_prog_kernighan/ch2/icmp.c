/* icmp: сравнение целых чисел *p1 и *p2 */
int icmp(const void *p1, const void *p2)
{
    int v1, v2;
    v1 = *(int *) p1;
    v2 = *(int *) p2;
    if (v1 < v2)
        return -1;
    else if (v1 == v2)
        return 0;
    else
        return 1;
}