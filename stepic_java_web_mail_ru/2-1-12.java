// class A{
//             public static <T> T  getFirstValue(T[] array){return array[0];}
// }
//  Отметьте два выражения, которые можно скомпилировать.

Object[] a = new Object[10]; Object b = A.getFirstValue(a);
Long[] a = {1L, 2L}; long b = A.getFirstValue(a);