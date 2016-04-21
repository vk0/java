# Массив, который нужно было создать в предыдущей задаче, хранится в переменной mat. Превратите его в вертикальный вектор и напечатайте.

import numpy as np
z = mat.flatten()
print(z.reshape(z.shape+(1,)))

# import numpy as np
# mat = mat.reshape((12,1))
# print(mat)