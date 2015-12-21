// Давайте напишем простой аллокатор.

// N.B. Для получения баллов дефрагментацию делать не требуется, но очень рекомендуется сделать ее для самотренировки.

// N.B. ReAlloc должен сохранять данные в блоке. То есть это не просто пара Free + Alloc.

// N.B. Следующий вариант и ему подобные считаются читерством:

// class SmallAllocator {
// public:
//         void *Alloc(unsigned int Size) {
//                 return malloc(Size);
//         };
//         void *ReAlloc(void *Pointer, unsigned int Size) {
//                 return realloc(Pointer, Size);
//         };
//         void Free(void *Pointer) {
//                 return free(Pointer);
//         };
// };

class SmallAllocator {
private:
        char Memory[1048576];
public:
        void *Alloc(unsigned int Size) {};
        void *ReAlloc(void *Pointer, unsigned int Size) {};
        void Free(void *Pointer) {};
};