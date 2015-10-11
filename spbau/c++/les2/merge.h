#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include <cstring>
#include <iostream> 

void merge(char * array, int middle, int size, char *buffer)
{
	int lpos = 0, rpos = 0;
	int llen = middle, rlen = size-middle;
	char *b = buffer;
	int s = size;

	for (;s;s--,b++) {
		if (lpos == llen) {
			strncpy(b, array+middle+rpos, rlen-rpos);
			s = 1;
		} else if (rpos == rlen) {
			strncpy(b, array+lpos, llen-lpos);
			s = 1;
		} else if (*(array+lpos)>*(array+middle+rpos)) {
			*b = *(array+middle+rpos);
			rpos++;
		} else {
			*b = *(array+lpos);
			lpos++;
		}
	}

	strncpy(array, buffer, size);
}

void merge_sort(char *c, int size, char *buffer)
{
	int middle;
	if (size > 1) {
		middle = size/2;
		merge_sort(c,middle,buffer);
		merge_sort(c+middle,size-middle,buffer);
		merge(c,middle,size,buffer);
	}
}

#endif /* _MERGE_SORT_H_ */
