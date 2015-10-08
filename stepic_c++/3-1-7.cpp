// Вопрос тот же самый: какова будет сумма элементов внутри экземпляра iv3d после завершения функции?

#include <iostream>
using namespace std;

struct ivector3d {
    int array[3];
};

void scale(ivector3d v, int k) {
    for (int i = 0; i != 3; ++i)
        v.array[i] *= k;
};

int main() {
    ivector3d iv3d;
    //Заполняем единицами
    for(int i = 0; i !=3; i++){
        iv3d.array[i] = 1;
    }

    scale(iv3d, 2);

    for (int i = 0; i != 3; ++i)
        cout << iv3d.array[i] << " ";
}