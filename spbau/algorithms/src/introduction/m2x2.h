#ifndef __M2_X_2_H__
#define __M2_X_2_H__

struct m2x2 {
	unsigned long a11, a12, a21, a22;
};

void mul(struct m2x2 *m1, struct m2x2 *m2)
{
	unsigned long a11 = (*m1).a11*(*m2).a11 + (*m1).a12*(*m2).a21;
	unsigned long a12 = (*m1).a11*(*m2).a12 + (*m1).a12*(*m2).a22;
	unsigned long a21 = (*m1).a21*(*m2).a11 + (*m1).a22*(*m2).a21;
	unsigned long a22 = (*m1).a21*(*m2).a12 + (*m1).a22*(*m2).a22;

	(*m1).a11 = a11; (*m1).a12 = a12;
	(*m1).a21 = a21; (*m1).a22 = a22;
}

void copy(struct m2x2 *src, struct m2x2 *dst)
{
	(*dst).a11 = (*src).a11;
	(*dst).a12 = (*src).a12;
	(*dst).a21 = (*src).a21;
	(*dst).a22 = (*src).a22;
}

#endif
